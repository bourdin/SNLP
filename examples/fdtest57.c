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
	int p = 3;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 0.42;
	x[1] = 5.0;
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
	_f[0] = (0.49-x1-(0.49-x1)*exp((8.0-8.0)*x2))*(0.49-x1-(0.49-x1)*exp((8.0-8.0)*x2))+(0.49-x1-(0.49-x1)*exp((8.0-8.0)*x2))*(0.49-x1-(0.49-x1)*exp((8.0-8.0)*x2))+(0.48-x1-(0.49-x1)*exp((8.0-10.0)*x2))*(0.48-x1-(0.49-x1)*exp((8.0-10.0)*x2))+(0.47-x1-(0.49-x1)*exp((8.0-10.0)*x2))*(0.47-x1-(0.49-x1)*exp((8.0-10.0)*x2))+(0.48-x1-(0.49-x1)*exp((8.0-10.0)*x2))*(0.48-x1-(0.49-x1)*exp((8.0-10.0)*x2))+(0.47-x1-(0.49-x1)*exp((8.0-10.0)*x2))*(0.47-x1-(0.49-x1)*exp((8.0-10.0)*x2))+(0.46-x1-(0.49-x1)*exp((8.0-12.0)*x2))*(0.46-x1-(0.49-x1)*exp((8.0-12.0)*x2))+(0.46-x1-(0.49-x1)*exp((8.0-12.0)*x2))*(0.46-x1-(0.49-x1)*exp((8.0-12.0)*x2))+(0.45-x1-(0.49-x1)*exp((8.0-12.0)*x2))*(0.45-x1-(0.49-x1)*exp((8.0-12.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-12.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-12.0)*x2))+(0.45-x1-(0.49-x1)*exp((8.0-14.0)*x2))*(0.45-x1-(0.49-x1)*exp((8.0-14.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-14.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-14.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-14.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-14.0)*x2))+(0.44-x1-(0.49-x1)*exp((8.0-16.0)*x2))*(0.44-x1-(0.49-x1)*exp((8.0-16.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-16.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-16.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-16.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-16.0)*x2))+(0.46-x1-(0.49-x1)*exp((8.0-18.0)*x2))*(0.46-x1-(0.49-x1)*exp((8.0-18.0)*x2))+(0.45-x1-(0.49-x1)*exp((8.0-18.0)*x2))*(0.45-x1-(0.49-x1)*exp((8.0-18.0)*x2))+(0.42-x1-(0.49-x1)*exp((8.0-20.0)*x2))*(0.42-x1-(0.49-x1)*exp((8.0-20.0)*x2))+(0.42-x1-(0.49-x1)*exp((8.0-20.0)*x2))*(0.42-x1-(0.49-x1)*exp((8.0-20.0)*x2))+(0.43-x1-(0.49-x1)*exp((8.0-20.0)*x2))*(0.43-x1-(0.49-x1)*exp((8.0-20.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-22.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-22.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-22.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-22.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-22.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-22.0)*x2))+(0.42-x1-(0.49-x1)*exp((8.0-24.0)*x2))*(0.42-x1-(0.49-x1)*exp((8.0-24.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-24.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-24.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-24.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-24.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-26.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-26.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-26.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-26.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-26.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-26.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-28.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-28.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-28.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-28.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-30.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-30.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-30.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-30.0)*x2))+(0.38-x1-(0.49-x1)*exp((8.0-30.0)*x2))*(0.38-x1-(0.49-x1)*exp((8.0-30.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-32.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-32.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-32.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-32.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-34.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-34.0)*x2))+(0.41-x1-(0.49-x1)*exp((8.0-36.0)*x2))*(0.41-x1-(0.49-x1)*exp((8.0-36.0)*x2))+(0.38-x1-(0.49-x1)*exp((8.0-36.0)*x2))*(0.38-x1-(0.49-x1)*exp((8.0-36.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-38.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-38.0)*x2))+(0.4-x1-(0.49-x1)*exp((8.0-38.0)*x2))*(0.4-x1-(0.49-x1)*exp((8.0-38.0)*x2))+(0.39-x1-(0.49-x1)*exp((8.0-40.0)*x2))*(0.39-x1-(0.49-x1)*exp((8.0-40.0)*x2))+(0.39-x1-(0.49-x1)*exp((8.0-42.0)*x2))*(0.39-x1-(0.49-x1)*exp((8.0-42.0)*x2));
	_g[0] = 0.09+x1*x2-0.49*x2;
	_g[1] = 0.4-x1;
	_g[2] = -4.0-x2;
	return;
}
