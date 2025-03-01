#pragma warning(disable:4996)
#include <stdio.h>
typedef struct ListElement
{
	int *wiersz;
	struct ListElement*next;
}ListElement;

typedef struct List
{
	ListElement*head;
	ListElement*tail;
}List;

/* inicjalizacja listy */
void init(List*list)
{
	list->head = 0;
	list->tail = 0;
}

int amount(List*list) {
	int i = 0;
	ListElement*tmp = list->head;

	while (tmp != 0) {
		i++;
		tmp = tmp->next;
		
	}
	return i;
}
/* Dodawanie danych do listy z tyłu*/
void add_back(List*list, int ile)
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i, j;
	ListElement*tmp2 = list->tail;
	tmp->next = 0;
	tmp->wiersz = (int*)malloc((ile + 1) * sizeof(int));
	tmp->wiersz[ile+1] = 0;
	tmp->wiersz[0] = 1;
	
	
	if (ile >= 2) {
		
		for (i = 1; i < ile + 1; i++) {
			tmp->wiersz[i] = tmp2->wiersz[i] + tmp->wiersz[i - 1];
		}
	}
	else if (ile == 1)
		tmp->wiersz[1] = 1;
	
	if (list->tail != 0) {
		list->tail->next = tmp;
		list->tail = tmp;
	}
	else {
		list->head = list->tail = tmp;
	}
}
/* Wypisanie zawartości listy*/
void printList(List*list)
{
	ListElement*tmp;
	int i = 1, j;
	for (tmp = list->head; tmp != 0; tmp = tmp->next,i++) {
		for (j = 0; j < i; j++) {
			printf("% 5d", tmp->wiersz[j]);
		}
		printf("\n");
	}
}
void search(List*list,int a, int b)
{
	ListElement*tmp;
	int i = 1, j,x=1,y;
	for (tmp = list->head; tmp != 0; tmp = tmp->next, i++,x++) {
		if (x == a) {
			printf("Twoja wartosc: %d", tmp->wiersz[b-1]);
			
			printf("\n");
		}
	}
}
int main()
{
	List list;
	int i = 1,a,b;
	init(&list);
	while (i) {
	add_back(&list, amount(&list));
	printf("Czy chcesz kontynuowac (1/0): ");
	scanf("%d", &i);
	}

	printList(&list);
	printf("Podaj 1: ");
	scanf("%d", &a);
	printf("Podaj 2: ");
	scanf("%d", &b);
	search(&list, a, b);
	getchar();
	getchar();
}
