/* Krzysztof Kosecki, 18.01.2017, 17:00 wersja C */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct point {
	int row;
	int col;
	double value;
	struct point* next;
};

struct limits {
	struct point* minValue;
	struct point* maxValue;
};

struct point* rewrite(double **arrayPointer, int rows, int cols) {
	/* Funkcja bierze wskaznik na tablice wskaznikow, do ktorej przepisalismy macierz, tworzy liste i przepisuje kazdy niezerowy element macierzy
		jako nowy node z polami i,j,arrayPointer[i][j] */
	int i, j;
	struct point* head = NULL;
	struct point* newNode;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (arrayPointer[i][j] != 0) {
				/* tutaj funkcja tworzy nowy node, wpisuje tam i,j i arrayPointer[i][j] */
				newNode = (struct point*)malloc(sizeof(struct point));
				newNode->row = i;
				newNode->col = j;
				newNode->value = arrayPointer[i][j];
				/* wpinanie tego nowego node'a: */
				newNode->next = head;
				head = newNode;
			}
		}
	}
	return head;
}

void displayList(struct point* head) { /* funkcja wyswietla liste, od tylu, ale nie bylo powiedziane w jakiej kolejnosci */
	printf("Zawartosc listy: \n\n");
	while (head != NULL) {
		printf("Wiersz: %d\n", head->row);
		printf("Kolumna: %d\n", head->col);
		printf("Wartosc: %f\n", head->value);
		printf("\n");
		head = head->next;
	}
}

struct limits findLimits(struct point* head) {
	struct limits listLimits;
	double minValue = DBL_MAX;
	double maxValue = -DBL_MAX; /* DBL_MIN zwraca 0.000, czyli najmniejsza niemniejsza od 0, natomiast liczby zmiennoprzecinkowe sa symetryczne, wiec mozna uzyc -DBL_MAX */
	while (head != NULL) {
		if (head->value < minValue) {
			listLimits.minValue = head;
			minValue = head->value;
		}
		if (head->value > maxValue) {
			listLimits.maxValue = head;
			maxValue = head->value;
		}
		head = head->next;
	}
	return listLimits;
}

int main(void) {

	/* Przykladowa macierz rzadka: */

	double matrix[5][5] = {
		{-1.2,0,0,0,0},
		{0,0,0.1,0,0},
		{0,0,2,0,0},
		{0,0,3,0,0},
		{-5,0,0,0,0}
	};
	/* wymiary tablicy: */
	int rows = 5;
	int cols = 5;
	double* p[5]; /* cols, tablica wskaznikow do poszczegolnych wierszy, zeby funkcja byla uniwersalna */
	int i;
	struct point* head; /* wskaznik na poczatek listy */
	struct limits listLimits; /* struktura do wartosci najwiekszej i najmniejszej */

	for (i = 0; i < cols; i++) { /* przepisanie macierzy, zeby funkcja mogla pobrac wskaznik */
		p[i] = matrix[i];
	}

	head = rewrite(p, rows, cols); /* wywolanie funkcji przepisujacej */
	if (head != NULL) { /* na wypadek macierzy wypelnionej zerami */
		displayList(head); /* wyswietlanie listy, czyli wspolrzedne i wartosc */
		listLimits = findLimits(head);  /* znalezienie wezlow z wartoscia minimalna i maksymalna */
		printf("---------------\n\n");
		printf("Element minimalny: \n");
		printf("Wiersz: %d\n", listLimits.minValue->row);
		printf("Kolumna: %d\n", listLimits.minValue->col);
		printf("Wartosc: %f\n\n", listLimits.minValue->value);
		printf("Element maksymalny: \n");
		printf("Wiersz: %d\n", listLimits.maxValue->row);
		printf("Kolumna: %d\n", listLimits.maxValue->col);
		printf("Wartosc: %f\n", listLimits.maxValue->value);
	}
	else {
		printf("Macierz jest wypelniona samymi zerami.\n");
	}
	getchar();
	getchar();
	return 0;
}