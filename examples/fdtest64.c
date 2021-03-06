/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 3;
	int m = 0;
	int p = 4;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 1;
	x[1] = 1;
	x[2] = 1;
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
	double x3 = _x[2];
	double x2 = _x[1];
	double x1 = _x[0];
	_f[0] = 0.0;
	_f[0] = 5*x1+50000*pow(x1,-1)+20*x2+72000*pow(x2,-1)+10*x3+144000*pow(x3,-1);
	_g[0] = 4/x1+32/x2+120/x3-1;
	_g[1] = -x1+1.0e-5;
	_g[2] = -x2+1.0e-5;
	_g[3] = -x3+1.0e-5;
	return;
}
