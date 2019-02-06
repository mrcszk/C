#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct osoba {
	char nazwa[20];
	int num_alb;
	struct osoba *next;
}wezel;

void dodaj(char *nazwa, int *num_al, struct osoba **hea) {
	struct osoba *tmp = (wezel*)malloc(sizeof(wezel));
	int i=0;
	while (nazwa[i] != '\0')
	{
		tmp->nazwa[i] = nazwa[i];
		i++;
	}
	tmp->nazwa[i] = '\0';
	tmp->num_alb = num_al;
	tmp->next = *hea;
	*hea = tmp;
}
void addElement(struct List *list, struct ListElement *element) {
	struct ListElement **nextElement = &list->head;

	while ((*nextElement) != NULL) {
		nextElement = &((*nextElement)->next);
	}

	*nextElement = element;
}
void zwolnij(wezel *hea) {
	wezel *nast;
	while (hea != NULL)
	{
		nast = hea->next;
		free(hea);
		hea = nast;
	}
}
void wypisz(wezel *hea) {
	while (hea != NULL) {
		printf("%s %d\n", hea->nazwa, hea->num_alb);
		hea = hea->next;
	}
}
void pop(wezel **hea) {
	if (*hea == NULL) {
		return;
	}
	if ((*hea)->next == NULL) {
		printf("%s %d\n", (*hea)->nazwa,  (*hea)->num_alb);
		free(*hea);
		*hea = NULL;
		return;
	}
	wezel *tmp = *hea;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	printf("%s %d\n", tmp->next->nazwa, tmp->next->num_alb);
	free(tmp->next);
	tmp->next = NULL;
}
int main(void) {
	setlocale(LC_ALL,"");
	struct osoba *head = NULL;
	printf("MENU\n");
	printf("'a' - dodanie elementu na koncu listy.\n");
	printf("'d' - dla skasowania elementu(wskazanego numerem albumu)\n");
	printf("'p' - dla wyprowadzenia na ekran wszystkich elementów listy\n");
	printf("'x' - dla zakończenia programu.\n");
	
	char nazwa[20];
	int num_alb;
	char wybor;
	for (;;) {
		
		
		printf("Podaj wybor: ");
		scanf("%c", &wybor);
		while (getchar() != '\n')
			continue; /* czyści wiersz wejściowy */
		switch (wybor) {
		case ('a'):
			printf("Podaj nazwe: ");
			scanf("%s", nazwa);
			while (getchar() != '\n')
				continue; /* czyści wiersz wejściowy */
			printf("Podaj numer albumu: ");
			scanf("%d", &num_alb);
			dodaj(nazwa, num_alb, &head);
			while (getchar() != '\n')
				continue; /* czyści wiersz wejściowy */
			break;
		case ('x'):
			return 1;
		case ('p'):
			wypisz(head);
			break;

		case ('s'):
			zwolnij(head);
			break;
		}
	}
	//wypisz(head);
	//pop(&head);
	//pop(&head);
	//pop(&head);
	//zwolnij(head);
	getchar();
	getchar();
	return 0;
}