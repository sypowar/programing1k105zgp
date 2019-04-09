#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main() {
	//задание 2.2 | 35 вариант

	double x, y, f = 0;
	int a = -10, b = 10, a1 = 2, b1 = 4, c = 0, d = 1;
	double h = 0.1, hx = 0.2, hy = 0.1;

	for (x = a; x <= b; x += h) {
		if (x <= -3) {
			f += pow(3, 2 * x - 3);
		}
		if (x > -3 || x <= 3) {
			f += pow(3, abs(x - 3));
		}
		if (x > 3) {
			f += x - abs(x - 1);
		}
	}
	printf("F = ");
	printf("%f \n", f);
	f = 0;
	getchar();
	return 0;
}