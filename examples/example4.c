#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "snlp.h"

void fhg(double *x, double *f, double *h, double *g) {
	double x4 = x[3];
	double x3 = x[2];
	double x2 = x[1];
	double x1 = x[0];
	double x6 = x[5];
	double x5 = x[4];
	f[0] = x1+2*x2+4*x5+exp(x1*x4);
	h[0] = x1+2*x2+5*x5-6;
	h[1] = x1+x2+x3-3;
	h[2] = x4+x5+x6-2;
	h[3] = x1+x4-1;
	h[4] = x2+x5-2;
	h[5] = x3+x6-2;
	g[0] = -x1;
	g[1] = x1-1;
	g[2] = -x2;
	g[3] = -x3;
	g[4] = -x4;
	g[5] = x4-1;
	g[6] = -x5;
	g[7] = -x6;
	return;
}

int main() {
	int n = 6;
	int m = 6;
	int p = 8;
    SNLP s;
    int exit_code, i;
    
    double *x = NULL;
	x = (double *)calloc(n, sizeof(double));
    
	x[0] = 1;
	x[1] = 2;
	x[2] = 0;
	x[3] = 0;
	x[4] = 0;
	x[5] = 2;
    
	s = SNLPNew(n, m, p, fhg);

    s->show_progress = 1;
    s->print_function_gradient = 1;     // 1 == YES, 0 == NO
    s->print_constraint_gradient = 1;   // 1 == YES, 0 == NO
    s->simple_line_search = 1;          // 1 == YES, 0 == NO
    
	exit_code = SNLPL1SQP(s, x);
    
	printf("exit code: %d\n", exit_code);
	printf("x: ");
    for (i = 0; i < n; i++)
        printf("%e ", x[i]);
    printf("\n");
    
	SNLPDelete(s);
	free(x);
    
	return 0;
}
