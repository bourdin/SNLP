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
	int p = 6;
	x = (double *)calloc(n, sizeof(double));
	x[0] = 100.0;
	x[1] = 12.5;
	x[2] = 3.0;
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
	_f[0] = (-0.1*1.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*1),0.6666667)-x2),x3)))*(-0.1*1.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*1),0.6666667)-x2),x3)))+(-0.1*2.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*2),0.6666667)-x2),x3)))*(-0.1*2.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*2),0.6666667)-x2),x3)))+(-0.1*3.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*3),0.6666667)-x2),x3)))*(-0.1*3.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*3),0.6666667)-x2),x3)))+(-0.1*4.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*4),0.6666667)-x2),x3)))*(-0.1*4.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*4),0.6666667)-x2),x3)))+(-0.1*5.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*5),0.6666667)-x2),x3)))*(-0.1*5.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*5),0.6666667)-x2),x3)))+(-0.1*6.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*6),0.6666667)-x2),x3)))*(-0.1*6.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*6),0.6666667)-x2),x3)))+(-0.1*7.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*7),0.6666667)-x2),x3)))*(-0.1*7.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*7),0.6666667)-x2),x3)))+(-0.1*8.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*8),0.6666667)-x2),x3)))*(-0.1*8.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*8),0.6666667)-x2),x3)))+(-0.1*9.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*9),0.6666667)-x2),x3)))*(-0.1*9.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*9),0.6666667)-x2),x3)))+(-0.1*10.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*10),0.6666667)-x2),x3)))*(-0.1*10.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*10),0.6666667)-x2),x3)))+(-0.1*11.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*11),0.6666667)-x2),x3)))*(-0.1*11.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*11),0.6666667)-x2),x3)))+(-0.1*12.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*12),0.6666667)-x2),x3)))*(-0.1*12.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*12),0.6666667)-x2),x3)))+(-0.1*13.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*13),0.6666667)-x2),x3)))*(-0.1*13.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*13),0.6666667)-x2),x3)))+(-0.1*14.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*14),0.6666667)-x2),x3)))*(-0.1*14.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*14),0.6666667)-x2),x3)))+(-0.1*15.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*15),0.6666667)-x2),x3)))*(-0.1*15.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*15),0.6666667)-x2),x3)))+(-0.1*16.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*16),0.6666667)-x2),x3)))*(-0.1*16.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*16),0.6666667)-x2),x3)))+(-0.1*17.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*17),0.6666667)-x2),x3)))*(-0.1*17.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*17),0.6666667)-x2),x3)))+(-0.1*18.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*18),0.6666667)-x2),x3)))*(-0.1*18.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*18),0.6666667)-x2),x3)))+(-0.1*19.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*19),0.6666667)-x2),x3)))*(-0.1*19.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*19),0.6666667)-x2),x3)))+(-0.1*20.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*20),0.6666667)-x2),x3)))*(-0.1*20.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*20),0.6666667)-x2),x3)))+(-0.1*21.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*21),0.6666667)-x2),x3)))*(-0.1*21.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*21),0.6666667)-x2),x3)))+(-0.1*22.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*22),0.6666667)-x2),x3)))*(-0.1*22.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*22),0.6666667)-x2),x3)))+(-0.1*23.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*23),0.6666667)-x2),x3)))*(-0.1*23.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*23),0.6666667)-x2),x3)))+(-0.1*24.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*24),0.6666667)-x2),x3)))*(-0.1*24.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*24),0.6666667)-x2),x3)))+(-0.1*25.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*25),0.6666667)-x2),x3)))*(-0.1*25.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*25),0.6666667)-x2),x3)))+(-0.1*26.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*26),0.6666667)-x2),x3)))*(-0.1*26.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*26),0.6666667)-x2),x3)))+(-0.1*27.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*27),0.6666667)-x2),x3)))*(-0.1*27.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*27),0.6666667)-x2),x3)))+(-0.1*28.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*28),0.6666667)-x2),x3)))*(-0.1*28.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*28),0.6666667)-x2),x3)))+(-0.1*29.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*29),0.6666667)-x2),x3)))*(-0.1*29.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*29),0.6666667)-x2),x3)))+(-0.1*30.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*30),0.6666667)-x2),x3)))*(-0.1*30.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*30),0.6666667)-x2),x3)))+(-0.1*31.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*31),0.6666667)-x2),x3)))*(-0.1*31.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*31),0.6666667)-x2),x3)))+(-0.1*32.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*32),0.6666667)-x2),x3)))*(-0.1*32.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*32),0.6666667)-x2),x3)))+(-0.1*33.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*33),0.6666667)-x2),x3)))*(-0.1*33.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*33),0.6666667)-x2),x3)))+(-0.1*34.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*34),0.6666667)-x2),x3)))*(-0.1*34.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*34),0.6666667)-x2),x3)))+(-0.1*35.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*35),0.6666667)-x2),x3)))*(-0.1*35.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*35),0.6666667)-x2),x3)))+(-0.1*36.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*36),0.6666667)-x2),x3)))*(-0.1*36.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*36),0.6666667)-x2),x3)))+(-0.1*37.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*37),0.6666667)-x2),x3)))*(-0.1*37.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*37),0.6666667)-x2),x3)))+(-0.1*38.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*38),0.6666667)-x2),x3)))*(-0.1*38.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*38),0.6666667)-x2),x3)))+(-0.1*39.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*39),0.6666667)-x2),x3)))*(-0.1*39.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*39),0.6666667)-x2),x3)))+(-0.1*40.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*40),0.6666667)-x2),x3)))*(-0.1*40.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*40),0.6666667)-x2),x3)))+(-0.1*41.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*41),0.6666667)-x2),x3)))*(-0.1*41.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*41),0.6666667)-x2),x3)))+(-0.1*42.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*42),0.6666667)-x2),x3)))*(-0.1*42.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*42),0.6666667)-x2),x3)))+(-0.1*43.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*43),0.6666667)-x2),x3)))*(-0.1*43.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*43),0.6666667)-x2),x3)))+(-0.1*44.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*44),0.6666667)-x2),x3)))*(-0.1*44.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*44),0.6666667)-x2),x3)))+(-0.1*45.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*45),0.6666667)-x2),x3)))*(-0.1*45.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*45),0.6666667)-x2),x3)))+(-0.1*46.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*46),0.6666667)-x2),x3)))*(-0.1*46.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*46),0.6666667)-x2),x3)))+(-0.1*47.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*47),0.6666667)-x2),x3)))*(-0.1*47.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*47),0.6666667)-x2),x3)))+(-0.1*48.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*48),0.6666667)-x2),x3)))*(-0.1*48.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*48),0.6666667)-x2),x3)))+(-0.1*49.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*49),0.6666667)-x2),x3)))*(-0.1*49.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*49),0.6666667)-x2),x3)))+(-0.1*50.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*50),0.6666667)-x2),x3)))*(-0.1*50.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*50),0.6666667)-x2),x3)))+(-0.1*51.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*51),0.6666667)-x2),x3)))*(-0.1*51.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*51),0.6666667)-x2),x3)))+(-0.1*52.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*52),0.6666667)-x2),x3)))*(-0.1*52.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*52),0.6666667)-x2),x3)))+(-0.1*53.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*53),0.6666667)-x2),x3)))*(-0.1*53.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*53),0.6666667)-x2),x3)))+(-0.1*54.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*54),0.6666667)-x2),x3)))*(-0.1*54.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*54),0.6666667)-x2),x3)))+(-0.1*55.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*55),0.6666667)-x2),x3)))*(-0.1*55.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*55),0.6666667)-x2),x3)))+(-0.1*56.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*56),0.6666667)-x2),x3)))*(-0.1*56.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*56),0.6666667)-x2),x3)))+(-0.1*57.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*57),0.6666667)-x2),x3)))*(-0.1*57.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*57),0.6666667)-x2),x3)))+(-0.1*58.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*58),0.6666667)-x2),x3)))*(-0.1*58.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*58),0.6666667)-x2),x3)))+(-0.1*59.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*59),0.6666667)-x2),x3)))*(-0.1*59.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*59),0.6666667)-x2),x3)))+(-0.1*60.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*60),0.6666667)-x2),x3)))*(-0.1*60.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*60),0.6666667)-x2),x3)))+(-0.1*61.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*61),0.6666667)-x2),x3)))*(-0.1*61.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*61),0.6666667)-x2),x3)))+(-0.1*62.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*62),0.6666667)-x2),x3)))*(-0.1*62.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*62),0.6666667)-x2),x3)))+(-0.1*63.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*63),0.6666667)-x2),x3)))*(-0.1*63.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*63),0.6666667)-x2),x3)))+(-0.1*64.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*64),0.6666667)-x2),x3)))*(-0.1*64.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*64),0.6666667)-x2),x3)))+(-0.1*65.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*65),0.6666667)-x2),x3)))*(-0.1*65.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*65),0.6666667)-x2),x3)))+(-0.1*66.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*66),0.6666667)-x2),x3)))*(-0.1*66.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*66),0.6666667)-x2),x3)))+(-0.1*67.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*67),0.6666667)-x2),x3)))*(-0.1*67.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*67),0.6666667)-x2),x3)))+(-0.1*68.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*68),0.6666667)-x2),x3)))*(-0.1*68.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*68),0.6666667)-x2),x3)))+(-0.1*69.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*69),0.6666667)-x2),x3)))*(-0.1*69.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*69),0.6666667)-x2),x3)))+(-0.1*70.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*70),0.6666667)-x2),x3)))*(-0.1*70.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*70),0.6666667)-x2),x3)))+(-0.1*71.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*71),0.6666667)-x2),x3)))*(-0.1*71.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*71),0.6666667)-x2),x3)))+(-0.1*72.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*72),0.6666667)-x2),x3)))*(-0.1*72.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*72),0.6666667)-x2),x3)))+(-0.1*73.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*73),0.6666667)-x2),x3)))*(-0.1*73.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*73),0.6666667)-x2),x3)))+(-0.1*74.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*74),0.6666667)-x2),x3)))*(-0.1*74.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*74),0.6666667)-x2),x3)))+(-0.1*75.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*75),0.6666667)-x2),x3)))*(-0.1*75.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*75),0.6666667)-x2),x3)))+(-0.1*76.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*76),0.6666667)-x2),x3)))*(-0.1*76.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*76),0.6666667)-x2),x3)))+(-0.1*77.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*77),0.6666667)-x2),x3)))*(-0.1*77.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*77),0.6666667)-x2),x3)))+(-0.1*78.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*78),0.6666667)-x2),x3)))*(-0.1*78.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*78),0.6666667)-x2),x3)))+(-0.1*79.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*79),0.6666667)-x2),x3)))*(-0.1*79.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*79),0.6666667)-x2),x3)))+(-0.1*80.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*80),0.6666667)-x2),x3)))*(-0.1*80.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*80),0.6666667)-x2),x3)))+(-0.1*81.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*81),0.6666667)-x2),x3)))*(-0.1*81.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*81),0.6666667)-x2),x3)))+(-0.1*82.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*82),0.6666667)-x2),x3)))*(-0.1*82.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*82),0.6666667)-x2),x3)))+(-0.1*83.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*83),0.6666667)-x2),x3)))*(-0.1*83.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*83),0.6666667)-x2),x3)))+(-0.1*84.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*84),0.6666667)-x2),x3)))*(-0.1*84.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*84),0.6666667)-x2),x3)))+(-0.1*85.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*85),0.6666667)-x2),x3)))*(-0.1*85.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*85),0.6666667)-x2),x3)))+(-0.1*86.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*86),0.6666667)-x2),x3)))*(-0.1*86.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*86),0.6666667)-x2),x3)))+(-0.1*87.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*87),0.6666667)-x2),x3)))*(-0.1*87.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*87),0.6666667)-x2),x3)))+(-0.1*88.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*88),0.6666667)-x2),x3)))*(-0.1*88.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*88),0.6666667)-x2),x3)))+(-0.1*89.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*89),0.6666667)-x2),x3)))*(-0.1*89.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*89),0.6666667)-x2),x3)))+(-0.1*90.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*90),0.6666667)-x2),x3)))*(-0.1*90.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*90),0.6666667)-x2),x3)))+(-0.1*91.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*91),0.6666667)-x2),x3)))*(-0.1*91.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*91),0.6666667)-x2),x3)))+(-0.1*92.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*92),0.6666667)-x2),x3)))*(-0.1*92.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*92),0.6666667)-x2),x3)))+(-0.1*93.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*93),0.6666667)-x2),x3)))*(-0.1*93.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*93),0.6666667)-x2),x3)))+(-0.1*94.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*94),0.6666667)-x2),x3)))*(-0.1*94.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*94),0.6666667)-x2),x3)))+(-0.1*95.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*95),0.6666667)-x2),x3)))*(-0.1*95.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*95),0.6666667)-x2),x3)))+(-0.1*96.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*96),0.6666667)-x2),x3)))*(-0.1*96.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*96),0.6666667)-x2),x3)))+(-0.1*97.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*97),0.6666667)-x2),x3)))*(-0.1*97.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*97),0.6666667)-x2),x3)))+(-0.1*98.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*98),0.6666667)-x2),x3)))*(-0.1*98.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*98),0.6666667)-x2),x3)))+(-0.1*99.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*99),0.6666667)-x2),x3)))*(-0.1*99.0+exp((-1.0/x1)*pow((25.0+pow(-50.0*log(0.01*99),0.6666667)-x2),x3)));
	_g[0] = 100.0-x1;
	_g[1] = 0.1-x1;
	_g[2] = -x2;
	_g[3] = x2-25.6;
	_g[4] = -x3;
	_g[5] = x3-5.0;
	return;
}
