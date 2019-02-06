#include <stdio.h>
#include <string.h> 
void minw(double *t, int d) {
	int min;
	min = t[0];
	for (int i = 1; i < d; i++) {
		if (min < t[i])
			continue;
		else
			min = t[i];
	}
	printf("%d", min);


}
int main() {
	double t[8];
	double k;
	int l = 0;
	int d, e;
	printf("Ile elementow tablicy chcesz podac? ");
	scanf_s("%d", &e);
	do
	{
		scanf_s("%lf", &t[l]);
		l++;
	} while (l < e);

	minw(&t, e);

	
	getchar();
	getchar();
	return 0;
}