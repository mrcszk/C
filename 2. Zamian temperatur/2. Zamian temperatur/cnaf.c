#include <stdio.h>

int main(void) {
	double fahr, cels;
	printf("Podaj temperaturę w Farenheitach:");
	scanf_s("%lf", &fahr);
	cels = ((fahr - 32) * 5) / 9;
	printf("Jest to %1.1f  stopni Celsjusza.\n", cels);
	getchar();
	getchar();
	return 0;
}