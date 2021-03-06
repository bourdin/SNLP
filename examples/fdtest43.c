/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 4;
	int m = 0;
	int p = 3;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	x[3] = 0;
	s = SNLPNew(n, m, p, fhg);
	s->tolerance = 1.0e-6;
	s->maximum_iterations = 500;
	s->show_progress = 1;
	exit_code = SNLPL1SQP(s, x);
	printf("x: ");
	for (i = 0; i < n; i++) {
		printf("%e ", x[i]);
	}
	printf("\n");
	SNLPDelete(s);
	free(x);
	return exit_code;
}
void fhg(double *_x, double *_f, double *_h, double *_g) {
	double x4 = _x[3];
	double x3 = _x[2];
	double x2 = _x[1];
	double x1 = _x[0];
	_f[0] = 0.0;
	_f[0] = x1*x1+x2*x2+2*x3*x3+x4*x4-5*x1-5*x2-21*x3+7*x4;
	_g[0] = x1*x1+x2*x2+x3*x3+x4*x4+x1-x2+x3-x4-8;
	_g[1] = x1*x1+2*x2*x2+x3*x3+2*x4*x4-x1-x4-10;
	_g[2] = 2*x1*x1+x2*x2+x3*x3+2*x1-x2-x4-5;
	return;
}
