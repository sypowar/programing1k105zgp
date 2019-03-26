#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double x, y , f=0;
	int a = -4, b = 4 , a1 = -3 , b1 = 3 , c = 1 , d = 2;
	double h = 0.1 , hx = 0.25 , hy = 0.15;
	for (x = -4; x <= 4; x+=h) {
		if (x < 0) {
			f += -(x*x) + 1 / x;
		}
		if (0 < x , x < 3) {
			f += sqrt(x*x + 1);
		}
		if (x >= 3) {
			f += x - 3;
		}
	}
	printf("F = ");
	printf("%f \n", f);
	f = 0;
	for (x = -3; x <= 3; x += hx) {
		for (y = 1; y <= 2; y += hy) {
			f += (sqrt(x*(y + 1))) / (x - y);
		}
	}
	printf("F = ");
	printf("%f \n", f);
	getchar();
	return 0;
}