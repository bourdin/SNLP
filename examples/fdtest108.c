/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 9;
	int m = 0;
	int p = 14;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 1;
	x[1] = 1;
	x[2] = 1;
	x[3] = 1;
	x[4] = 1;
	x[5] = 1;
	x[6] = 1;
	x[7] = 1;
	x[8] = 1;
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
	double x9 = _x[8];
	double x8 = _x[7];
	double x7 = _x[6];
	double x6 = _x[5];
	double x5 = _x[4];
	double x4 = _x[3];
	_f[0] = 0.0;
	_f[0] = -0.5*(x1*x4-x2*x3+x3*x9-x5*x9+x5*x8-x6*x7);
	_g[0] = x3*x3+x4*x4-1;
	_g[1] = x5*x5+x6*x6-1;
	_g[2] = pow((x1-x5),2)+pow((x2-x6),2)-1;
	_g[3] = pow((x1-x7),2)+pow((x2-x8),2)-1;
	_g[4] = pow((x3-x5),2)+pow((x4-x6),2)-1;
	_g[5] = pow((x3-x7),2)+pow((x4-x8),2)-1;
	_g[6] = x7*x7+pow((x8-x9),2)-1;
	_g[7] = -x3*x9;
	_g[8] = x6*x7-x5*x8;
	_g[9] = x9*x9-1;
	_g[10] = x1*x1+pow((x2-x9),2)-1;
	_g[11] = x2*x3-x1*x4;
	_g[12] = x5*x9;
	_g[13] = -x9;
	return;
}
