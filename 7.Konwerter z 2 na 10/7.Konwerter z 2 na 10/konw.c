#include <stdio.h>
#include <math.h>
int main(void) {
	int a,b=0;
	int c,i = 0;
//	int tab[10];
	printf("Podaj liczbe w sys binarnym: ");
	scanf_s("%d", &a);

	printf("System dziesietny:");
	while (a != 0)
	{
		c = a % 10;
		a = a / 10;
		b += c * pow(2, i);
		i++;
	}
	printf("%d", b);
	//	i--;
/*
	for (i; i >= 0; i--)
	{
		printf("%d", tab[i]);
	}*/
	getchar();
	getchar();
	return 0;
}