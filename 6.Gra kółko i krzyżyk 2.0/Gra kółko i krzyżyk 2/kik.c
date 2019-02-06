# include <stdio.h>
char pole[9] = { '1','2','3','4','5','6','7','8','9' };
int p,r;
char j;

void tab()
{
	int i;
	for (i = 0; i <= 9; i++)
	{
		if (i == 2 || i == 5 || i == 9)
			printf("%2c\n", pole[i]);
		else
			printf("%2c", pole[i]);
	}
}

void czyX()
{
	switch (r)
	{
	case 1:
		pole[r - 1] = 'X';
		tab();
		break;
	case 2:
		pole[r - 1] = 'X';
		tab();
		break;
	case 3:
		pole[r - 1] = 'X';
		tab();
		break;
	case 4:
		pole[r - 1] = 'X';
		tab();
		break;
	case 5:
		pole[r - 1] = 'X';
		tab();
		break;
	case 6:
		pole[r - 1] = 'X';
		tab();
		break;
	case 7:
		pole[r - 1] = 'X';
		tab();
		break;
	case 8:
		pole[r - 1] = 'X';
		tab();
		break;
	case 9:
		pole[r - 1] = 'X';
		tab();
		break;

	default:
		printf("Nie smieszne. Tracisz ruch ;)\n");
		tab();
		break;
	}
}
void czyO()
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
		printf("Nie smieszne. Tracisz ruch ;)\n");
		tab();
		break;
	}
}



int graX()
{
	for (;;) {
		koniecy();
		printf("X:Podaj pole: ");
		scanf_s("%d", &r);
		system("cls");
		if (pole[r - 1] == 'X' || pole[r - 1] == 'O')
		{
			system("cls");
			printf("Bylo.\n");
			tab();
			continue;
		}
		else
		{
			czyX();
			break;
		}
	}
}
int graO() {
	for (;;) {
		koniecx();
		printf("O:Podaj pole: ");
		scanf_s("%d", &p);
		system("cls"); 
		if (pole[p - 1] == 'X' || pole[p - 1] == 'O')
		{
			system("cls");
			printf("Bylo.\n");
			tab();
			continue;
		}
		else
		{
			czyO();
			break;
		}
	}
}
int koniecx()
{
	if ((pole[0] == pole[1] && pole[1] == pole[2]) || (pole[3] == pole[4] && pole[3] == pole[5]) || (pole[6] == pole[7] && pole[7] == pole[8]) || (pole[0] == pole[4] && pole[4] == pole[8]) || (pole[2] == pole[4] && pole[4] == pole[6]) || (pole[0] == pole[3] && pole[3] == pole[6]) || (pole[1] == pole[4] && pole[4] == pole[7]) || (pole[2] == pole[5] && pole[5] == pole[8]))
	{
		printf("Koniec gry. Wygral gracz I (ten co mial X)\n");
		
		printf("Grasz jeszcze raz?(t/n) ");
		scanf_s(" %c", &j);

		if (j == 'n')
			exit(0);
		if (j== 't')
		{

			system("cls");
		}
		else
		{
			printf("Jesli chciales mialo byc 't', wiec jest koniec gry.\n");
			getchar();
			system("pause");
			exit(0);
		}

		pole[0] = '1';
		pole[1] = '2';
		pole[2] = '3';
		pole[3] = '4';
		pole[4] = '5';
		pole[5] = '6'; 
		pole[6] = '7';
		pole[7] = '8';
		pole[8] = '9'; 
		tab();
	}
}
int koniecy()
{
	if ((pole[0] == pole[1] && pole[1] == pole[2]) || (pole[3] == pole[4] && pole[3] == pole[5]) || (pole[6] == pole[7] && pole[7] == pole[8]) || (pole[0] == pole[4] && pole[4] == pole[8]) || (pole[2] == pole[4] && pole[4] == pole[6]) || (pole[0] == pole[3] && pole[3] == pole[6]) || (pole[1] == pole[4] && pole[4] == pole[7]) || (pole[2] == pole[5] && pole[5] == pole[8]))
	{
		printf("Koniec gry. Wygral gracz II (ten co mial Y)\n");

		printf("Grasz jeszcze raz?(t/n) ");
		scanf_s(" %c", &j);

		if (j == 'n')
			exit(0);
		if (j == 't')
		{

			system("cls");
		}
		else
		{
			printf("Jesli chciales mialo byc 't', wiec jest koniec gry.\n");
			getchar();
			system("pause");
			exit(0);
		}

		pole[0] = '1';
		pole[1] = '2';
		pole[2] = '3';
		pole[3] = '4';
		pole[4] = '5';
		pole[5] = '6';
		pole[6] = '7';
		pole[7] = '8';
		pole[8] = '9';
		tab();
	}
}

int main(void) {
		printf("Gracz 1 - X\n");
		printf("Gracz 2 - O\n");
		tab();
		while (1) 
		{
			graX();
			graO();		
		}
	getchar();
	getchar();
	return 0;
}