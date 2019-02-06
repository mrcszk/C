#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define ROZT 45 /* rozmiar tablicy przechowuj?cej tytu? */

struct film
{
	char tytu?[ROZT];
	int ocena;
};
/* ogolne definicje typów */
typedef struct film Pozycja;
typedef enum boole { False, True } BOOLEAN;
typedef struct wezel
{
	Pozycja pozycja;
	struct wezel * nast;
} Wezel;
typedef Wezel * Lista;
/* prototypy funkcji */
/* dzia?anie: inicjalizuje list? */
/* warunki wstepne: wlista wskazuje na list? */
/* warunki ko?cowe: lista zostaje zainicjalizowana jako pusta */
void InicjujListe(Lista * wlista);
/* dzia?anie: okre?la, czy lista jest pusta */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki ko?cowe: funkcja zwraca True je?li lista jest pusta */
/* a w przeciwnym wypadku False */
BOOLEAN PustaLista(Lista l);
/* dzia?anie: okre?la, czy lista jest pe?na */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki ko?cowe: funkcja zwraca True je?li lista jest pe?na */
/* a w przeciwnym wypadku False */
BOOLEAN PelnaLista(Lista l);
/* dzia?anie: okre?la liczb? pozycji w li?cie */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki ko?cowe: funkcja zwraca liczb? pozycji w li?cie */
unsigned int LiczbaPozycji(Lista l);
/* dzia?anie: dodaje pozycje na ko?cu listy */
/* warunki wstepne: pozycja jest pozycja do dodania */
/* wlista wskazuje na zainicjalizowana list? */
/* warunki ko?cowe: je?li jest to mo?liwe, funkcja dodaje */
/* pozycje na ko?cu listy i zwraca True; */
/* w przeciwnym wypadku funkcja zwraca False */
BOOLEAN DodajPozycje(Pozycja pozycja, Lista * wlista);
/* dzia?anie: stosuje funkcje do ka?dej pozycji w li?cie */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* wfun wskazuje na funkcje, która pobiera */
/* argument typu Pozycja i nie ma warto?ci */
/* zwracanej */
/* warunki ko?cowe: funkcja wskazywana przez wfun jest */
/* uruchamiana jeden raz dla ka?dej pozycji */
/* w li?cie */
void Przejdz(Lista l, void(*wfun)(Pozycja pozycja));
void pokazfilm(Pozycja pozycja);


int main(void)
{
	setlocale(LC_ALL, "polish");
	Lista filmy;
	Pozycja tymcz;
	InicjujListe(&filmy);
	if (PelnaLista(filmy))
	{
		fprintf(stderr, "Brak pami?ci! Do widzenia!\n");
		exit(1);
	}
	puts("Podaj pierwszy tytu? filmu:");
	while (gets(tymcz.tytu?) != NULL && tymcz.tytu?[0] != '\0')
	{
		puts("Podaj Twoja ocene <0-10>:");
		scanf("%d", &tymcz.ocena);
		while (getchar() != '\n')
			continue;
		if (DodajPozycje(tymcz, &filmy) == False)
		{
			fprintf(stderr, "Blad alokacji pamieci\n");
			break;
		}
		if (PelnaLista(filmy))
		{
			puts("Lista jest juz pe?na.");
			break;
		}
		puts("Podaj nast?pny tytu? filmu (pusty wiersz ko?czy wpisywanie):");
	}
	if (PustaLista(filmy))
		printf("Nie wpisano ?adnych danych. ");

	else
	{
		printf("Oto lista filmów:\n");
		Przejdz(filmy, pokazfilm);
	}
	printf("Do widzenia!\n");
	getchar();
	getchar();
	return 0;
}
void pokazfilm(Pozycja pozycja)
{
	printf("Film: %s Ocena: %d\n", pozycja.tytu?, pozycja.ocena);
}
/* funkcje lokalne */
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel);
/* funkcje interfejsu */
/* inicjalizuje list? jako pusta */
void InicjujListe(Lista * wlista)
{
	*wlista = NULL;
}
/* zwraca prawd?, je?li lista jest pusta */
BOOLEAN PustaLista(Lista l)
{
	if (1 == NULL)
		return True;
	else
		return False;
}
/* zwraca prawd?, je?li lista jest pe?na */
BOOLEAN PelnaLista(Lista l)
{
	Wezel * wsk;
	BOOLEAN full;
	wsk = (Wezel *)malloc(sizeof(Wezel));
	if (wsk == NULL)
		full = True;
	else
		full = False;
	free(wsk);
	return full;
}
/* zwraca liczb? wezlow */
unsigned int LiczbaPozycji(Lista l)
{
	unsigned int licznik = 0;
	while (l != NULL)
	{
		++licznik;
		l = l->nast; /* sprawia, ze 1 wskazuje na nast?pny wezel */
	}
	return licznik;
}
/* tworzy wezel przechowuj?cy pozycje i dodaje go na ko?cu */
/* listy wskazywanej przez wlista (wolna implementacja) */
BOOLEAN DodajPozycje(Pozycja pozycja, Lista * wlista)
{
	Wezel * wnowy;
	Wezel * szuk = *wlista;
	wnowy = (Wezel *)malloc(sizeof(Wezel));
	if (wnowy == NULL)
		return False; /* ko?czy funkcje w razie niepowodzenia */
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if (szuk == NULL) /* lista jest pusta, wnowy nale?y */
		* wlista = wnowy; /* wiec umiescic na jej pocz?tku */
	else
	{
		while (szuk->nast != NULL)
			szuk = szuk->nast; /* znajduje koniec listy */
		szuk->nast = wnowy; /* dodaje wnowy na ko?cu */
	}
	return True;
}
/* "odwiedza" ka?dy wezel i wykonuje funkcje wskazywana przez wfun */
void Przejdz(Lista l, void(*wfun)(Pozycja pozycja))
{
	while (l != NULL)
	{
		(*wfun)(l->pozycja); /* stosuje funkcje do pozycji */
		l = l->nast;
	}
}
/* kopiuje pozycje do wezla */
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel)
{
	wwezel->pozycja = pozycja; /* przypisanie struktury */
}
