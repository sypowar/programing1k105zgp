#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(){
	//задание 1 | 38 вариант
	float a = -2.51, b = 6.07, x = -0.25;
	double otvet;
	otvet = pow(10, a*x) + log(fabs((2 - x) / (b + x)));
	printf("%f", otvet);
	getchar();
    return 0;
}