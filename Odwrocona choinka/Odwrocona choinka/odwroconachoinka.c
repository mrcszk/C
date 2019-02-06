// Marcin Sawczuk wtorek 9:30
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int wczytaj(void);
void choinka(int n);

int main(void)
{
	int n;
	n = wczytaj();
	choinka(n);	

	getchar();
	getchar();
	return 0;
}

int wczytaj(void) {
	int n=0;
	while ((n < 7 || n > 21) || (n % 2 ==0)) {
		printf("Podaj nieparzysta liczbe z zakresu 7-21: \n");
		scanf("%d", &n);
		while (getchar() != '\n')
			continue;
		if (n < 7 || n > 21 || (n % 2 == 0))
			printf("Wprowadziles bledne dane sproboj jeszcze raz!\n");
	}
	return n;
}
void choinka(int n) {
	int j, a;
	for (j = n; j > 0; j -= 2) {
		for (a = 0; a < n - j; a++)
			printf(" ");
		for (a = 0; a < j; a++)
			printf("* ");
		printf("\n");
	}

}