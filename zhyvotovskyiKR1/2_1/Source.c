#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static int factorial(int n) {
	return (n < 2) ? 1 : n * factorial(n - 1);
}

int main() {
	//задание 2.1 | 35 вариант
	float a = -0.5, b = 0.5, N = 20;
	double h = (b - a) / (N - 1), otvet, x = 0;
	printf("Enter x, N: ");
	if (scanf("%lf %d", &x, &N) != 2) {
		printf("Invalid input\n");
		return -1;
	}
	if (x < a || x > b) {
		char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
		printf(fmt, x, a, b);
		return -1;
	}
	double a = 1, S = 0;
	for (int n = 0; n <= N; ++n) {
		double tmp = pow(sqrt(x) + x, 2 * n + 1) / (pow(2, n)*(2 * n + n)*factorial(n));
		a *= tmp;
		S += a;
	}
	S = 3.14 / 2 - S;
	printf("S=%.7f\n", S);
	getchar();
	return 0;
}