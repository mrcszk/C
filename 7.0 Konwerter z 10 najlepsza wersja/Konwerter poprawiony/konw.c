#include <stdio.h>
int a,k,s,i = 0;
char tab[100];
void sys()
{
	switch (k)
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
	case 16:
	{
		tab[i] = 'g';
		break;
	}
	case 17:
	{
		tab[i] = 'h';
		break;
	}
	case 18:
	{
		tab[i] = 'i';
		break;
	}
	case 19:
	{
		tab[i] = 'j';
		break;
	}
	case 20:
	{
		tab[i] = 'k';
		break;
	}
	default:
		break;
	}
}

void wypis()
{
	printf("Twoja liczba wynosi: ");
	while (a != 0)
	{
		k = a % s;
		sys(k);
		a = a / s;
		i++;
	}
	i--;
	for (i; i >= 0; i--)
	{
		printf("%c", tab[i]);
	}
}
int main(void) {
	printf("Podaj system na jaki chcesz zamienic(podaj liczbe z przedzialu <2;20>: ");
	scanf_s("%d", &s);
	printf("Podaj liczbe naturalna: ");
	scanf_s("%d", &a);

	wypis();

	getchar();
	getchar();
	return 0;
}