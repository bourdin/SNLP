// Copyright (c) 2009,2010,2011,2012 Brian C. Fabien
//               2015 B. Bourdin bourdin@lsu.edu
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the license.txt file.

#ifndef _NLPSolve_H
#define	_NLPSolve_H

#ifdef	__cplusplus
extern "C" {
#endif

enum NLPmethod {L1SQPmethod, LinfSQPmethod}; //, HybridSQPmethod, LagNewtmethod };

struct nlpoptions_ {
    enum NLPmethod method;  // default: L1SQPmethod 
    double tolerance;       // default: 1.0e-6
    int maximumIterations;  // default: 1000
    int displayData;        // default: NO
    int printFunctionGradient;      // default: NO
    int printConstraintGradient;    // default: NO
    int simpleLineSearch;           // default: NO
};

typedef struct nlpoptions_ NLPOptions;

struct  nlpstatistics_ {
    double f;          // function value
    double normc;      // norm of the active constraints
    double normT;      // norm of the KKT conditions
    int n, m, p;
    int numberOfIterations;
    int numberOfFunctionCalls;
    int numberOfGradientCalls;
    int numberOfQPSolves;
    int numberOfRefinements;
    int numberOfSOC;
    int exitCode;
    char methodName[64];
};

typedef struct nlpstatistics_ NLPStatistics;

NLPStatistics
NLPsolve(double (*fhg) (Vector x, Vector h, Vector g, void *ctx),
         void (*Dfhg) (Vector x, Vector df, Matrix dh, Matrix dg, void *ctx),
         void *ctx,
         Vector x, Vector lambda, Vector mu,
         NLPOptions options);

void NLPPrintStatistics(NLPStatistics s);

#ifdef	__cplusplus
}
#endif

#endif	/* _NLPSolve_H */
