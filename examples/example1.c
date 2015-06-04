    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #include "snlp.h"
    
    void fhg(double *x, double *f, double *h, double *g) {
        double x1 = x[0];
        double x2 = x[1];
        f[0] = 100.0*(x2-x1*x1)*(x2-x1*x1) + (1-x1)*(1-x1);
        g[0] = x1*x1 + x2*x2 - 1.5;
    }
    
    int main() {
        int n = 2;
        int m = 0;
        int p = 1;
        SNLP s;
        int exit_code, i;
        
        double *x = NULL;
        x = (double *)calloc(n, sizeof(double));
        
        x[0] = -2.9;
        x[1] = 2.0;
        
        s = SNLPNew(n, m, p, fhg);
        s->show_progress = 1; // 1 == YES, 0 == NO
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
