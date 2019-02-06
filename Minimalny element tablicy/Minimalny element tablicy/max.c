#include <stdio.h>

void wart(double t[], int e,double *min, double *maks) {
	*maks = *min = t[0];
	for (int i = 1; i < e; i++) {
		if (*min > t[i])
			*min = t[i];

		if (*maks < t[i])
			*maks = t[i];
	}
}

int main() {
	double t[50];
	double min,maks;
	int l = 0;
	int e;

	printf("Ile elementow tablicy chcesz podac? ");
	scanf_s("%d", &e);
	while (l < e){
		scanf_s("%lf",&t[l]);
		l++;
	} 

	wart(t, e,&min,&maks);
	
	printf("Najmniejszy element tej tablicy to: %lf\n",min);
	printf("Najwiekszy element tej tablicy to: %lf\n", maks);

	getchar();
	getchar();
	return 0;
}