// Copyright (c) 2013 Brian C. Fabien
//               2015 B. Bourdin bourdin@lsu.edu
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the license.txt file.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

#include "runtime.h"
#include "vector.h"
#include "matrix.h"
#include "equations.h"
#include "snlp.h"
#include "nlp.h"
#include "nlpsolve.h"

int snlp_solve(SNLP s, double *x_ptr, int method);
double snlp_fhg(Vector xv, Vector hv, Vector gv, void *ctx);
void snlp_dfhg(Vector xv, Vector dfv, Matrix dhv, Matrix dgv, void *ctx);

static SNLP this_snlp;

// create a new SNLP data structure
SNLP_API SNLP SNLPNew(int n, int m, int p, void (*fhg)(double *x, double *f, double *h, double *g, void *ctx),
                      void (*Dfhg)(double *x, double *Df, double **Dh, double **Dg, void *ctx),void *ctx) {
    if (n < 1) {
        RuntimeWarning("SNLPNew(): n < 1: invalid number of parameters");
        return NULL;
    }
    if (m > n || m < 0) {
        RuntimeWarning("SNLPNew(): m < 0 or m > n: invalid number of equality constraints");
        return NULL;
    }
    if (p < 0) {
        RuntimeWarning("SNLPNew(): p < 0: invalid number of inequality constraints");
        return NULL;
    }
    if (fhg == NULL) {
        RuntimeWarning("SNLPNew(): NULL pointer to function evaluator");
        return NULL;
    }
    SNLP s;
    s = (SNLP)malloc(sizeof(struct snlp_));
    s->n = n;
    s->m = m;
    s->p = p;
    s->fhg = fhg;
    s->Dfhg = Dfhg;
    s->ctx = ctx;
    s->tolerance = 1.0e-6;
    s->maximum_iterations = 500;
    s->show_progress = NO;
    s->print_function_gradient = NO;
    s->print_constraint_gradient = NO;
    s->simple_line_search = NO;

    // Results
    
    s->f = 0;
    s->normc = 0;
    s->normT = 0;
    s->lambda = NULL;
    if (m > 0) {
        s->lambda = (double *)calloc(m, sizeof(double));
    }
    s->mu = NULL;
    if (p > 0) {
        s->mu = (double *)calloc(p, sizeof(double));
    }
    s->number_of_function_calls = 0;
    s->number_of_gradient_calls = 0;
    s->number_of_SOC = 0;
    s->number_of_QP_solves = 0;
    s->exit_code = 0;
    return s;
}

// delete the SNLP data structure
SNLP_API void SNLPDelete(SNLP a) {
    if (a->lambda != NULL) {
        free(a->lambda);
    }
    if (a->mu != NULL) {
        free(a->mu);
    }
    free(a);
}

SNLP_API int SNLPL1SQP(SNLP s, double *x) {
    if (s == NULL) {
        RuntimeWarning("SNLPL1SQP(): NULL pointer for SNLP data structure, s");
        return -1;
    }
    if (x == NULL) {
        RuntimeWarning("SNLPL1SQP(): NULL pointer for the initial estimate, x");
        return -1;
    }
    return snlp_solve(s, x, 0);
}

SNLP_API int SNLPLinfSQP(SNLP s, double *x) {
    if (s == NULL) {
        RuntimeWarning("SNLPLinfSQP(): NULL pointer for SNLP data structure, s");
        return -1;
    }
    if (x == NULL) {
        RuntimeWarning("SNLPLinfSQP(): NULL pointer for the initial estimate, x");
        return -1;
    }
    return snlp_solve(s, x, 1);
}

double snlp_fhg(Vector xv, Vector hv, Vector gv, void *ctx) {
    double f;
    double *x = NULL, *h = NULL, *g = NULL;
    x = xv->e;
    if (hv != NULL) {
        h = hv->e;
    }
    if (gv != NULL) {
        g = gv->e;
    }
    this_snlp->fhg(x, &f, h, g, ctx);
    return f;
}

void snlp_dfhg(Vector xv, Vector dfv, Matrix dhv, Matrix dgv, void *ctx) {
    double *x = NULL, *df = NULL, **dh = NULL, **dg = NULL;
    x = xv->e;
    if (dfv != NULL) {
        df = dfv->e;
    }
    if (dhv != NULL) {
        dh = dhv->e;
    }
    if (dgv != NULL) {
        dg = dgv->e;
    }
    this_snlp->Dfhg(x, df, dh, dg, ctx);
}

int snlp_solve(SNLP s, double *x_ptr, int method) {
// TODO: check options set by the user
  this_snlp = s;
	int n = s->n;
	int m = s->m;
	int p = s->p;

	Vector x = NULL;
  Vector lambda = NULL;
  Vector mu = NULL;
    
	x = VectorNew(n);
	if (m > 0) {
		lambda = VectorNew(m);
	}
	if (p > 0) {
		mu = VectorNew(p);
	}
	int i;
    for (i = 0; i < n; i++) {
        x->e[i] = x_ptr[i];
    }
    
	NLPOptions opt;
	if (method == 1) {
        opt.method = LinfSQPmethod;
    } else {
        opt.method = L1SQPmethod;
    }
	opt.tolerance = s->tolerance;
	opt.maximumIterations = s->maximum_iterations;
	opt.displayData = s->show_progress;
	opt.printFunctionGradient = s->print_function_gradient;
	opt.printConstraintGradient = s->print_constraint_gradient;
	opt.simpleLineSearch = s->simple_line_search;
    
	NLPStatistics stats;
    if (s->Dfhg == NULL) {
        stats = NLPsolve(snlp_fhg, NULL, s->ctx, x, lambda, mu, opt);
    } else {
        stats = NLPsolve(snlp_fhg, snlp_dfhg, s->ctx, x, lambda, mu, opt);
    }
    
    for (i = 0; i < n; i++) {
        x_ptr[i] = x->e[i];
    }
	if (m > 0) {
        for (i = 0; i < m; i++) {
            s->lambda[i] = lambda->e[i];
        }
	}
	if (p > 0) {
        for (i = 0; i < p; i++) {
            s->mu[i] = mu->e[i];
        }
	}
	VectorDelete(x);
	if (m > 0) {
		VectorDelete(lambda);
	}
	if (p > 0) {
		VectorDelete(mu);
	}

    s->f = stats.f;
    s->normc = stats.normc;
    s->normT = stats.normT;
    s->number_of_function_calls = stats.numberOfFunctionCalls;
    s->number_of_gradient_calls = stats.numberOfGradientCalls;
    s->number_of_iterations = stats.numberOfIterations;
    s->number_of_QP_solves = stats.numberOfQPSolves;
    s->number_of_SOC = stats.numberOfSOC;
    s->exit_code = stats.exitCode;

	return stats.exitCode;
}
