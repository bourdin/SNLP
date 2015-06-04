/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 10;
	int m = 0;
	int p = 20;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 9;
	x[1] = 9;
	x[2] = 9;
	x[3] = 9;
	x[4] = 9;
	x[5] = 9;
	x[6] = 9;
	x[7] = 9;
	x[8] = 9;
	x[9] = 9;
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
	double x10 = _x[9];
	double x5 = _x[4];
	double x4 = _x[3];
	_f[0] = 0.0;
	_f[0] = pow(log(x1-2.0),2.0)+pow(log(10.0-x1),2.0)+pow(log(x2-2.0),2.0)+pow(log(10.0-x2),2.0)+pow(log(x3-2.0),2.0)+pow(log(10.0-x3),2.0)+pow(log(x4-2.0),2.0)+pow(log(10.0-x4),2.0)+pow(log(x5-2.0),2.0)+pow(log(10.0-x5),2.0)+pow(log(x6-2.0),2.0)+pow(log(10.0-x6),2.0)+pow(log(x7-2.0),2.0)+pow(log(10.0-x7),2.0)+pow(log(x8-2.0),2.0)+pow(log(10.0-x8),2.0)+pow(log(x9-2.0),2.0)+pow(log(10.0-x9),2.0)+pow(log(x10-2.0),2.0)+pow(log(10.0-x10),2.0)-pow((x1*x2*x3*x4*x5*x6*x7*x8*x9*x10),0.2);
	_g[0] = 2.001-x1;
	_g[1] = 2.001-x2;
	_g[2] = 2.001-x3;
	_g[3] = 2.001-x4;
	_g[4] = 2.001-x5;
	_g[5] = 2.001-x6;
	_g[6] = 2.001-x7;
	_g[7] = 2.001-x8;
	_g[8] = 2.001-x9;
	_g[9] = 2.001-x10;
	_g[10] = x1-9.999;
	_g[11] = x2-9.999;
	_g[12] = x3-9.999;
	_g[13] = x4-9.999;
	_g[14] = x5-9.999;
	_g[15] = x6-9.999;
	_g[16] = x7-9.999;
	_g[17] = x8-9.999;
	_g[18] = x9-9.999;
	_g[19] = x10-9.999;
	return;
}
