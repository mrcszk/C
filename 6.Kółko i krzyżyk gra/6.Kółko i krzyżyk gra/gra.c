# include <stdio.h>
char pole[9] = { '1','2','3','4','5','6','7','8','9' };
int b = 1;
int p;
int a;
void tab(b)
{
	int i;
	if (b != 2) {
		for (i = 0; i <= 9; i++)
		{
			if (i == 2 || i == 5 || i == 9)
				printf("%2c\n", pole[i]);
			else
				printf("%2c", pole[i]);
		}


	}
}

void czyX(p)
{
	switch (p)
	{
	case 1:
		pole[p - 1] = 'X';
		tab();
		break;
	case 2:
		pole[p - 1] = 'X';
		tab();
		break;
	case 3:
		pole[p - 1] = 'X';
		tab();
		break;
	case 4:
		pole[p - 1] = 'X';
		tab();
		break;
	case 5:
		pole[p - 1] = 'X';
		tab();
		break;
	case 6:
		pole[p - 1] = 'X';
		tab();
		break;
	case 7:
		pole[p - 1] = 'X';
		tab();
		break;
	case 8:
		pole[p - 1] = 'X';
		tab();
		break;
	case 9:
		pole[p - 1] = 'X';
		tab();
		break;

	default:
		break;
	}
}
void czyO(p)
{
	switch (p)
	{
	case 1:
		pole[p - 1] = 'O';
		tab();
		break;
	case 2:
		pole[p - 1] = 'O';
		tab();
		break;
	case 3:
		pole[p - 1] = 'O';
		tab();
		break;
	case 4:
		pole[p - 1] = 'O';
		tab();
		break;
	case 5:
		pole[p - 1] = 'O';
		tab();
		break;
	case 6:
		pole[p - 1] = 'O';
		tab();
		break;
	case 7:
		pole[p - 1] = 'O';
		tab();
		break;
	case 8:
		pole[p - 1] = 'O';
		tab();
		break;
	case 9:
		pole[p - 1] = 'O';
		tab();
		break;

	default:
		break;
	}
}

int koniec()
{
	if ((pole[0] == pole[1] && pole[1] == pole[2]) || (pole[3] == pole[4] && pole[3] == pole[5]) || (pole[6] == pole[7] && pole[7] == pole[8]) || (pole[0] == pole[4] && pole[4] == pole[8]) || (pole[2] == pole[4] && pole[4] == pole[6]) || (pole[0] == pole[3] && pole[3] == pole[6]) || (pole[1] == pole[4] && pole[4] == pole[7]) || (pole[2] == pole[5] && pole[5] == pole[8]))
	{
		printf("Koniec gry.\n");
		return 2;
	}
}

void gra()
{
	while (a <= 5 && b != 2) {
		b = koniec();


		printf("X:Podaj pole: ");
		scanf_s("%d", &p);
		system("cls");

		czyX(p);
		b = koniec();
		if (b == 2)
			break;

		printf("O:Podaj pole: ");
		scanf_s("%d", &p);
		system("cls");
		czyO(p);
		a++;
	}
	b = 3;
}


int main(void) {
	tab(b);
	gra();
	getchar();
	getchar();
	return 0;
}