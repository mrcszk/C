#include <stdio.h>

int main(void) {
	int a;
	int i = 0;
	char tab[100];
	printf("Podaj liczbe naturalna: ");
	scanf_s("%d", &a);

	printf("System szesnastkowy: ");
	while (a != 0)
	{	
			switch ((a % 16))
			{
			case 0:
			{
				tab[i] = '0';
				break;
			}
			case 1:
			{
				tab[i] = '1';
				break;
			}
			case 2:
			{
				tab[i] = '2';
				break;
			}
			case 3:
			{
				tab[i] = '3';
				break;
			}
			case 4:
			{
				tab[i] = '4';
				break;
			}
			case 5:
			{
				tab[i] = '5';
				break;
			}
			case 6:
			{
				tab[i] = '6';
				break;
			}
			case 7:
			{
				tab[i] = '7';
				break;
			}
			case 8:
			{
				tab[i] = '8';
				break;
			}
			case 9:
			{
				tab[i] = '9';
				break;
			}
			case 10:
			{
				tab[i] = 'a';			
				break;
			}
			case 11:
			{
				tab[i] = 'b';			
				break;
			}
			case 12:
			{
				tab[i] = 'c';			
				break;
			}
			case 13:
			{
				tab[i] = 'd';
				break;
			}
			case 14:
			{
				tab[i] = 'e';
				break;
			}
			case 15:
			{
				tab[i] = 'f';
				break;
			}
			default:
				break;
			}

		a = a / 16;
		i++;
	}

	i--;

	for (i; i >= 0; i--)
	{
		printf("%c", tab[i]);
	}
	getchar();
	getchar();
	return 0;
}