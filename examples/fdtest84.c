/*  This file was automatically generated by ParamOptToC  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *_x, double *_f, double *_h, double *_g);

int main() {
	double *x = NULL;
SNLP s;
int exit_code, i;	int n = 5;
	int m = 0;
	int p = 16;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 2.52;
	x[1] = 2.0;
	x[2] = 37.5;
	x[3] = 9.25;
	x[4] = 6.8;
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
	double x5 = _x[4];
		double a19;
		double a18;
		double a17;
		double a16;
		double a15;
		double a14;
		double a13;
		double a12;
		double a11;
		double a10;
		double a21;
		double a20;
		double a9;
		double a8;
		double a7;
		double a6;
		double a5;
		double a4;
		double a3;
		double a2;
		double a1;
	_f[0] = 0.0;
	a1 = -24345.0;
	a2 = -8720288.849;
	a3 = 150512.5253;
	a4 = -156.6950325;
	a5 = 476470.3222;
	a6 = 729482.8271;
	a7 = -145421.402;
	a8 = 2931.1506;
	a9 = -40.427932;
	a10 = 5106.192;
	a11 = 15711.36;
	a12 = -155011.1084;
	a13 = 4360.53352;
	a14 = 12.9492344;
	a15 = 10236.884;
	a16 = 13176.786;
	a17 = -326669.5104;
	a18 = 7390.68412;
	a19 = -27.8986976;
	a20 = 16643.076;
	a21 = 30988.146;
	_f[0] = -a1-a2*x1-a3*x1*x2-a4*x1*x3-a5*x1*x4-a6*x1*x5;
	_g[0] = 6.5-x5;
	_g[1] = x5-7.0;
	_g[2] = 9.0-x4;
	_g[3] = x4-9.3;
	_g[4] = 20.0-x3;
	_g[5] = x3-60.0;
	_g[6] = 1.2-x2;
	_g[7] = x2-2.4;
	_g[8] = -x1;
	_g[9] = x1-1000.0;
	_g[10] = -a7*x1-a8*x1*x2-a9*x1*x3-a10*x1*x4-a11*x1*x5;
	_g[11] = a7*x1+a8*x1*x2+a9*x1*x3+a10*x1*x4+a11*x1*x5-294000.0;
	_g[12] = -a12*x1-a13*x1*x2-a14*x1*x3-a15*x1*x4-a16*x1*x5;
	_g[13] = a12*x1+a13*x1*x2+a14*x1*x3+a15*x1*x4+a16*x1*x5-294000.0;
	_g[14] = -a17*x1-a18*x1*x2-a19*x1*x3-a20*x1*x4-a21*x1*x5;
	_g[15] = a17*x1+a18*x1*x2+a19*x1*x3+a20*x1*x4+a21*x1*x5-277200.0;
	return;
}
