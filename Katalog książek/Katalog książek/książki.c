#pragma warning(disable:4996)
/* książki.c — spis wielu książek */
#include <stdio.h>
#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100 /* maksymalna liczba książek */
struct ksiazka { /* definiuje szablon ksiazka */
	char tytuł[MAXTYT];
	char autor[MAXAUT];
	long int nr;
	float wartość;
};
int main(void)
{
	struct ksiazka bibl[MAXKS]; /* tablica struktur typu ksiazka */
	int licznik = 0;
	int index;
	printf("Aby zakonczyc, wcisnij [enter] na poczatku wiersza.\n");
	printf("Podaj tytul ksiazki.\n");
	
	while (licznik < MAXKS && gets(bibl[licznik].tytuł) != NULL && bibl[licznik].tytuł[0] != '\0')
	{
		printf("Teraz podaj autora.\n");
		scanf ("%s", &bibl[licznik].autor);
		printf("Teraz podaj numer.\n");
		scanf("%d", &bibl[licznik].nr);
		printf("Teraz podaj wartosc.\n");
		scanf("%f", &bibl[licznik].wartość);
		licznik++;
		while (getchar() != '\n')
			continue; /* czyści wiersz wejściowy */
		if (licznik < MAXKS)
			printf("Podaj kolejny tytuł.\n");
	}
	printf("Oto lista Twoich ksiazek:\n");
	for (index = 0; index < licznik; index++)
		printf("%s, autor: %s, nr.: %d, cena: %.2f zl\n", bibl[index].tytuł, bibl[index].autor,bibl[index].nr, bibl[index].wartość);
	getchar();
	getchar();
	return 0;
}
	