/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 2;
	int m = 0;
	int p = 4;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 0;
	x[1] = 0;
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
	double x2 = _x[1];
	double x1 = _x[0];
	_f[0] = 0.0;
	_f[0] = sin(x1+x2)+pow((x1-x2),2)-1.5*x1+2.5*x2+1.0;
	_g[0] = -1.5-x1;
	_g[1] = x1-4.0;
	_g[2] = -3.0-x2;
	_g[3] = x2-3.0;
	return;
}
