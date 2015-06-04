// Copyright (c) 2013 Brian C. Fabien
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the license.txt file.

/* 
 * File:   snlp.h
 * Author: fabien
 *
 * Created on April 6, 2013, 2:26 PM
 */

#ifndef _SNLP_H
#define	_SNLP_H

#if defined(_WIN32)	/* { */

#if defined(SNLP_EXPORTS)	/* { */
#define SNLP_API __declspec(dllexport)
#else						/* }{ */
#define SNLP_API __declspec(dllimport)
#endif						/* } */

#define SNLP_CALL __cdecl

#else				/* }{ */

#define SNLP_API 
#define SNLP_CALL 	

#endif				/* } */

#ifdef	__cplusplus
extern "C" {
#endif

struct snlp_ {

    // Required input
    
    int n; // number of parameters
    int m; // number of equality constraints
    int p; // number of inequality constraints
    void (*fhg)(double *x, double *f, double *h, double *g); // compute f(x), h(x), g(x)

    // Optional input
    
    void (*Dfhg)(double *x, double *Df, double **Dh, double **Dg);  // NULL (default)
    double tolerance;                                               // 1.0e-6
    int maximum_iterations;                                         // 500
    int show_progress;                                              // NO
    int print_function_gradient;      // default: NO
    int print_constraint_gradient;    // default: NO
    int simple_line_search;           // default: NO

    // Results
    
    double f;
    double normc;
    double normT;
    double *lambda;
    double *mu;
    int number_of_iterations;
    int number_of_function_calls;
    int number_of_gradient_calls;
    int number_of_QP_solves;
    int number_of_SOC;
    int exit_code;
};

typedef struct snlp_ * SNLP;

SNLP_API SNLP SNLP_CALL SNLPNew(int n,
             int m,
             int p,
             void (*fhg)(double *x, double *f, double *h, double *g));
SNLP_API void SNLP_CALL SNLPDelete(SNLP s);
SNLP_API int SNLP_CALL SNLPLinfSQP(SNLP s, double *x);
SNLP_API int SNLP_CALL SNLPL1SQP(SNLP s, double *x);

#ifdef	__cplusplus
}
#endif

#endif	/* _SNLP_H */
