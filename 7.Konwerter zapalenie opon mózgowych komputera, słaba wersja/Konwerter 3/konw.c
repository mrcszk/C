#include <stdio.h>

int main(void) {
	int a;
	int k;
	int i = 0;
	int tab[10];
	printf("Podaj system na jaki chcesz zamienic(podaj liczbe z przedzialu <2;16>: ");
	scanf_s("%d", &k);
	printf("Podaj liczbe naturalna: ");
	scanf_s("%d", &a);

	switch (k)
	{
		case 8:
		{printf("System osemkowy:");
		while (a != 0)
		{
			tab[i] = a % 8;
			a = a / 8;
			i++;
		}
		i--;

		for (i; i >= 0; i--)
		{
			printf("%d", tab[i]);
		}
		}
	}
		getchar();
		getchar();
		return 0;
		}
