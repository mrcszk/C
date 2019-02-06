# include <stdio.h>

int main(void) {
	double x, xp = 0.1, xk = 10 * xp;
	int    i, ip = 1, ik = 10 * ip;
	for (x = xp; x < xk; x += 0.1) printf("%f ", x);
	printf("\n");
	for (i = ip; i < ik; i += 1)   printf("%d ", i);
	printf("\n");
	getchar();
	getchar();
	return 0;
}