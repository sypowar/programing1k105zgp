#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	float a , b , x ;
	printf("Enter a");
	scanf_s("%f", &a);
	printf("Enter b");
	scanf_s("%f", &b);
	printf("Enter x");
	scanf_s("%f", &x);
	double s;
	s = (sqrtf(sqrtf(x*x*x)) - a * x) / (log10f(x) + b);
	printf("%.5f", s);
	getchar();
	getchar();
	return 0;
}