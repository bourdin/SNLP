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
	int p = 8;
	x = (double *)calloc(n, sizeof(double));
	x[0] = -3;
	x[1] = -1;
	x[2] = -3;
	x[3] = -1;
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
	_f[0] = 100*pow((x2-x1*x1),2)+pow((1-x1),2)+90*pow((x4-x3*x3),2)+pow((1-x3),2)+10.1*(pow((x2-1),2)+pow((x4-1),2))+19.8*(x2-1)*(x4-1);
	_g[0] = -10-x1;
	_g[1] = x1-10;
	_g[2] = -10-x2;
	_g[3] = x2-10;
	_g[4] = -10-x3;
	_g[5] = x3-10;
	_g[6] = -10-x4;
	_g[7] = x4-10;
	return;
}
