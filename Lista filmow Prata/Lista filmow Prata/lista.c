#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define ROZT 45 /* rozmiar tablicy przechowuj¹cej tytu³ */

struct film
{
	char tytu³[ROZT];
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
/* dzia³anie: inicjalizuje listê */
/* warunki wstepne: wlista wskazuje na listê */
/* warunki koñcowe: lista zostaje zainicjalizowana jako pusta */
void InicjujListe(Lista * wlista);
/* dzia³anie: okreœla, czy lista jest pusta */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki koñcowe: funkcja zwraca True jeœli lista jest pusta */
/* a w przeciwnym wypadku False */
BOOLEAN PustaLista(Lista l);
/* dzia³anie: okreœla, czy lista jest pe³na */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki koñcowe: funkcja zwraca True jeœli lista jest pe³na */
/* a w przeciwnym wypadku False */
BOOLEAN PelnaLista(Lista l);
/* dzia³anie: okreœla liczbê pozycji w liœcie */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* warunki koñcowe: funkcja zwraca liczbê pozycji w liœcie */
unsigned int LiczbaPozycji(Lista l);
/* dzia³anie: dodaje pozycje na koñcu listy */
/* warunki wstepne: pozycja jest pozycja do dodania */
/* wlista wskazuje na zainicjalizowana listê */
/* warunki koñcowe: jeœli jest to mo¿liwe, funkcja dodaje */
/* pozycje na koñcu listy i zwraca True; */
/* w przeciwnym wypadku funkcja zwraca False */
BOOLEAN DodajPozycje(Pozycja pozycja, Lista * wlista);
/* dzia³anie: stosuje funkcje do ka¿dej pozycji w liœcie */
/* warunki wstepne: 1 jest zainicjalizowana lista */
/* wfun wskazuje na funkcje, która pobiera */
/* argument typu Pozycja i nie ma wartoœci */
/* zwracanej */
/* warunki koñcowe: funkcja wskazywana przez wfun jest */
/* uruchamiana jeden raz dla ka¿dej pozycji */
/* w liœcie */
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
		fprintf(stderr, "Brak pamiêci! Do widzenia!\n");
		exit(1);
	}
	puts("Podaj pierwszy tytu³ filmu:");
	while (gets(tymcz.tytu³) != NULL && tymcz.tytu³[0] != '\0')
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
			puts("Lista jest juz pe³na.");
			break;
		}
		puts("Podaj nastêpny tytu³ filmu (pusty wiersz koñczy wpisywanie):");
	}
	if (PustaLista(filmy))
		printf("Nie wpisano ¿adnych danych. ");

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
	printf("Film: %s Ocena: %d\n", pozycja.tytu³, pozycja.ocena);
}
/* funkcje lokalne */
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel);
/* funkcje interfejsu */
/* inicjalizuje listê jako pusta */
void InicjujListe(Lista * wlista)
{
	*wlista = NULL;
}
/* zwraca prawdê, jeœli lista jest pusta */
BOOLEAN PustaLista(Lista l)
{
	if (1 == NULL)
		return True;
	else
		return False;
}
/* zwraca prawdê, jeœli lista jest pe³na */
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
/* zwraca liczbê wezlow */
unsigned int LiczbaPozycji(Lista l)
{
	unsigned int licznik = 0;
	while (l != NULL)
	{
		++licznik;
		l = l->nast; /* sprawia, ze 1 wskazuje na nastêpny wezel */
	}
	return licznik;
}
/* tworzy wezel przechowuj¹cy pozycje i dodaje go na koñcu */
/* listy wskazywanej przez wlista (wolna implementacja) */
BOOLEAN DodajPozycje(Pozycja pozycja, Lista * wlista)
{
	Wezel * wnowy;
	Wezel * szuk = *wlista;
	wnowy = (Wezel *)malloc(sizeof(Wezel));
	if (wnowy == NULL)
		return False; /* koñczy funkcje w razie niepowodzenia */
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if (szuk == NULL) /* lista jest pusta, wnowy nale¿y */
		* wlista = wnowy; /* wiec umiescic na jej pocz¹tku */
	else
	{
		while (szuk->nast != NULL)
			szuk = szuk->nast; /* znajduje koniec listy */
		szuk->nast = wnowy; /* dodaje wnowy na koñcu */
	}
	return True;
}
/* "odwiedza" ka¿dy wezel i wykonuje funkcje wskazywana przez wfun */
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
