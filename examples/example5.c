#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

typedef struct {
  double A[3];
  double p[3];
  double sigmac;
} userctx;

void fhg(double *x, double *f, double *h, double *g, void *c) {
    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    userctx *ctx = (userctx*) c;

    *f = ctx->A[0] * pow(x1-ctx->p[0],2) + ctx->A[0] * pow(x2-ctx->p[1],2) + ctx->A[0] * pow(x3-ctx->p[2],2);

    h[0] = x1 + x2 + x3;

    g[0] =  x1 - x2 - ctx->sigmac;
    g[1] = -x1 + x2 - ctx->sigmac;
    g[2] =  x1 - x3 - ctx->sigmac;
    g[3] = -x1 + x3 - ctx->sigmac;
    g[4] =  x2 - x3 - ctx->sigmac;
    g[5] = -x2 + x3 - ctx->sigmac;
}

void Dfhg(double *x, double *Df, double **Dh, double **Dg, void *c) {
    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    userctx *ctx = (userctx*) c;

    Df[0] = 2. * ctx->A[0] * (x1-ctx->p[0]);
    Df[1] = 2. * ctx->A[1] * (x2-ctx->p[1]);;
    Df[2] = 2. * ctx->A[2] * (x2-ctx->p[2]);;
    
    Dh[0][0] = 1.;  Dh[0][1] = 1.;  Dh[0][2] = 1.;
    
    Dg[0][0] = 1.;  Dg[0][1] = -1.; Dg[0][2] = 0.;
    Dg[1][0] = -1.; Dg[1][1] = 1.;  Dg[1][2] = 0.;
    Dg[2][0] = 1.;  Dg[2][1] = 0.;  Dg[2][2] = -1.;
    Dg[3][0] = -1.; Dg[3][1] = 0.;  Dg[3][2] = 1.;
    Dg[4][0] = 0.;  Dg[4][1] = 1.;  Dg[4][2] = -1.;
    Dg[5][0] = 0.;  Dg[5][1] = -1.; Dg[5][2] = 1.;
}

int main() {
    int n = 3;
    int m = 1;
    int p = 6;
    SNLP s;
    int exit_code, i;
    userctx ctx;
    
    double *x = NULL;
    x = (double *)calloc(n, sizeof(double));
    
    ctx.A[0] = 1.;  ctx.A[1] = 2.; ctx.A[2] = 5.;
    ctx.p[0] = -1.; ctx.p[1] = 2.; ctx.p[2] = -5.;
    ctx.sigmac = 1.;

    s = SNLPNew(n, m, p, fhg, Dfhg, &ctx);
    s->show_progress = 1; // 1 == YES, 0 == NO
    exit_code = SNLPL1SQP(s, x);
    
    printf("exit code: %d\n", exit_code);
    printf("x: ");
    for (i = 0; i < n; i++) 
        printf("%e ", x[i]);
    printf("\n");
    
    SNLPDelete(s);
    free(x);
    
    return 0;
}
