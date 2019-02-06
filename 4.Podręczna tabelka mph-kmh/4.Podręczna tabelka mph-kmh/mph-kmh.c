#include <stdio.h>

int main(void) {
	double mph, km;
	printf("Podręczna tabelka dla interpretacji znaków ograniczenia prędkości.\n");
	km = 50;
	mph = (1 / 1.609)*km;
	printf("%5.1f km/h %10.1f mph\n", km, mph);

	km = 70;
	mph = (1 / 1.609)*km;
	printf("%5.1f km/h %10.1f mph\n", km, mph);

	km = 90;
	mph = (1 / 1.609)*km;
	printf("%5.1f km/h %10.1f mph\n", km, mph);

	km = 100;
	mph = (1 / 1.609)*km;
	printf("%5.1f km/h %10.1f mph\n", km, mph);
	getchar();
	getchar();
	return 0;
}