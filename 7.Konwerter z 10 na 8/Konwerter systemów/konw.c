#include <stdio.h>

int main(void) {
	int a;
	int i = 0;
	int tab[10];
	printf("Podaj liczbe naturalna: ");
	scanf_s("%d", &a);

	printf("System osemkowy:");
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
	getchar();
	getchar();
	return 0;
}