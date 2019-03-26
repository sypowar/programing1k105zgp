#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int q = -1;
	double a=1;
	double x = 1, lx = 0 , rx = 3.14/2.0;
	double s=0;

	for (int i = 0; i <= 10; i++) {
		a *= (q * (sin(2 * i + 1)*x) / ((2 * i + 1)*(2 * i + 1)));
		q = -q;
		s += a;
	}
	printf("%.7f",s);
	getchar();
	getchar();
	return 0;
}