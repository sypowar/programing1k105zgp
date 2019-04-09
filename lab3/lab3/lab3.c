#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	printf("lab 3.1 - 1 \nlab 3.2 - 2 \n");
	int b;
	scanf_s("%d", &b);
	if (b == 1) {
		int a[3] = { 100,23,6 };
		int max = 0;
		int min = 1000;

		for (int i = 0; i < 3; i++) {
			printf("%d | ", a[i]);
		}
		printf("\n");
		for (int i = 0; i < 3; i++) {
			if (a[i] >= 100) {
				a[i] = a[i] % 10 + (a[i] / 10) % 10 + (a[i] / 100) % 10;
			}
			if (a[i] < 100 || a[i] >= 10) {
				a[i] = a[i] % 10 + (a[i] / 10) % 10;
			}
			printf("%d | ", a[i]);

			if (a[i] >= max) {
				max = a[i];
			}
			if (a[i] <= min) {
				min = a[i];
			}
		}
		printf("\n");
		printf("%d min \n", min);
		printf("%d max \n", max);
		printf("\n");
	}

	if (b == 2) {
		int a1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
		int a2[3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%d | ", a1[i][j]);
			}
			printf("\n");
		}
		
		for (int i = 0; i < 3; i++) {
			a2[i] = a1[0][i] * a1[1][i] * a1[2][i];
			printf("%d | ", a2[i]);
		}
	}
	getchar();
	getchar();
	return 0;
}