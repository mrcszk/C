#include <stdio.h>

int main(void) {
	double masa, wzrost, bmi;
	printf("Podaj masę(w kg):");
	scanf_s("%lf", &masa);
	printf("Podaj wzrost(w cm):");
	scanf_s("%lf", &wzrost);

	bmi = masa / ((wzrost / 100)*(wzrost / 100));
	printf("Twoje bmi wynosi: %f \n", bmi);
	getchar();
	getchar();
	return 0;
}