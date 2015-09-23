// Copyright (c) 2009,2010,2011,2012 Brian C. Fabien
//               2015 B. Bourdin bourdin@lsu.edu
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the license.txt file.

/* 
 * File:   nlp.h
 * Author: fabien
 *
 * Created on July 9, 2010, 6:26 PM
 */

#ifndef _NLP_H
#define	_NLP_H

#ifdef	__cplusplus
extern "C" {
#endif


struct nlp_ {
    int n; // number of parameters
    int m; // number of equality constraints
    int p; // number of inequality contstraints
    
    // return f(x): double
    // compute h(x): m-Vector
    // compute g(x): p-Vector
    // x is an n-Vector
    double (*fhg)(Vector x, Vector h, Vector g, void *ctx);
    
    // compute Df = df/dx: n-Vector
    // compute Dh = dh/dx: m-by-n Matrix
    // compute Dg = dg/dx: p-by-n Matrix
    void (*Dfhg)(Vector x, Vector Df, Matrix Dh, Matrix Dg, void *ctx);
    void *ctx;
    // private

    Equations e;
    Matrix De;
    Vector h, g;
};

typedef struct nlp_ * NLP;

NLP NLPNew();
void NLPDelete(NLP a);
void NLPDfhg(NLP a, Vector x0, Vector Df, Matrix Dh, Matrix Dg, void *ctx);

#ifdef	__cplusplus
}
#endif

#endif	/* _NLP_H */
