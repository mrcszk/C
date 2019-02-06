# include <stdio.h>
# include <stdlib.h>
#include <time.h>

int main(void) {
	//char tab[10];
	//fgets(tab, 10, stdin);
	//printf("%s", tab);
	srand(time(NULL));
	int wiersz = 0;
	int znak;
	int linia;

	char krzyzowka[50][50] ;
	char tekst[50];
	int ile = 0;
	char wyraz[50][50];
	int max = 0;
	int nr_wyr;


	FILE *plik;
	plik = fopen("polski.txt", "r");
	if (plik == NULL) {
		printf("Nie znaleziono pliku.");
		exit(1);
	}


	printf("Plik otwarty pomyslnie!\n");
	znak = fgetc(plik);
	while (znak != EOF)
	{
		printf("%c", znak);
		if (znak == '\n')
			++wiersz;
		znak = fgetc(plik);
	}
	printf("Plik zawiera %d wiersze\n", wiersz);
	linia = rand() % wiersz + 1;
	printf("%d", linia);
	wiersz = 0;
	while (wiersz <= linia + 1)
	{
		printf("%c", znak);
		if (znak == '\n')
			++wiersz;
		znak = fgetc(plik);
		if (wiersz == linia)
		{
			fseek(plik, nr_wyr, SEEK_SET);
			fscanf(plik, "%s", &tekst);
			for (int i = 0; i < strlen(tekst); i++) {
				krzyzowka[i][0] = tekst[i];
			}
		}
	}

	return 0;
}