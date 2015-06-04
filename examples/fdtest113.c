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
	int p = 8;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 2;
	x[1] = 3;
	x[2] = 5;
	x[3] = 5;
	x[4] = 1;
	x[5] = 2;
	x[6] = 7;
	x[7] = 3;
	x[8] = 6;
	x[9] = 10;
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
	_f[0] = x1*x1+x2*x2+x1*x2-14*x1-16*x2+pow((x3-10),2)+4*pow((x4-5),2)+pow((x5-3),2)+2*pow((x6-1),2)+5*x7*x7+7*pow((x8-11),2)+2*pow((x9-10),2)+pow((x10-7),2)+45;
	_g[0] = 4*x1+5*x2-3*x7+9*x8-105;
	_g[1] = 10*x1-8*x2-17*x7+2*x8;
	_g[2] = 2*x2-8*x1+5*x9-2*x10-12;
	_g[3] = 3*pow((x1-2),2)+4*pow((x2-3),2)+2*x3*x3-7*x4-120;
	_g[4] = 5*x1*x1+8*x2+pow((x3-6),2)-2*x4-40;
	_g[5] = 0.5*pow((x1-8),2)+2*pow((x2-4),2)+3*x5*x5-x6-30;
	_g[6] = x1*x1+2*pow((x2-2),2)-2*x1*x2+14*x5-6*x6;
	_g[7] = 6*x2-3*x1+12*pow((x9-8),2)-7*x10;
	return;
}
