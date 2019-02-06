#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct node
{
	int id;
	int time;

	struct node *next, *prev;
}node_t;

typedef struct nodeb
{
	int idb;

	struct node *nextb, *prevb;
}node_b;

typedef struct list
{
	node_t *head;
	node_t *tail;
}list_t;
typedef struct list2
{
	node_b *headb;
	node_b *tailb;
}list_b;

int removeSpecified(list_t *list, int var);
void removeList(list_t *list);
void printList(list_t *list);
void checkMemory(const void * const ptr);
node_t *makeNode(void);
void addElement(list_t *list);
void wpisywanie(char w, int tab[]);
void czas(list_t *list);
void addElementb(list_b *bany, int tab[]);
node_b *makeNodeb(int a);
int szukanie(list_t *list, int id);
void zapis(FILE *plik, list_t *list);
void printListb(list_b *bany);
void removeSpecified2(list_t *list, int var);
int removeSpecifiedb(list_b *bany, int var);
void zapisb(FILE *plik, list_b *bany);


int main(void)
{
	list_b *bany = malloc(sizeof(list_b));
	list_t *list = malloc(sizeof(list_t));
	FILE* plik;
	FILE* plikb;
	
	checkMemory(list);
	list->head = NULL;
	list->tail = NULL;
	bany->headb = NULL;
	bany->tailb = NULL;
	
	int tab[2] = { 0,0 };
	char w;
	int a,b,i=0;
	plik = fopen("plik.txt", "r"); /* rt - reading text */
	while (fscanf(plik, "%d %d", &tab[0],&tab[1]) != EOF)
	{
			addElement(list, tab);
		
	}
	fclose(plik);
	plikb = fopen("bany.txt", "r"); /* rt - reading text */
	while (fscanf(plikb, "%d", &tab[0]) != EOF)
	{
		addElementb(bany, tab[0]);

	}
	fclose(plikb);
printList(list);
	
	for (;;){

		wpisywanie(&w, tab);
		if (w == 'I') {
			czas(bany, list);

			a = removeSpecified(list, tab[0]);
			b = removeSpecifiedb(bany, tab[0]);
			if (a != 2 && b!=2)
				addElement(list, tab);

		}
		else if (w == 'O') {
			removeSpecified2(list, tab[0]);
			czas(bany, list);
		}
		else if (w == 'R')
			printList(list);
		else if (w == 'B')
			printListb(bany);
		else if (w == 'X')
		{
			plik = fopen("plik.txt", "w");
			zapis(plik, list);
			fclose(plik);
			plikb = fopen("bany.txt", "w");
			zapisb(plikb, bany);
			fclose(plikb);
			printf("End of program");
			return 0;

		}
		else
			printf("Podales bledna informacje!");
	}
	getchar();
	getchar();
	return 0;
}
void zapisb(FILE *plik, list_b *bany) {
	node_b *temp;
	for (temp = bany->headb; temp != NULL; temp = temp->nextb) {
		fprintf(plik, "%d\n", temp->idb);
	}
}
void zapis(FILE *plik, list_t *list) {
	node_t *temp;
	for (temp = list->head; temp != NULL; temp = temp->next) {
		fprintf(plik, "%d %d\n", temp->id, temp->time);
	}
}
void czas(list_b *bany, list_t *list) {
	node_t *temp;
	for (temp = list->head; temp != NULL; temp = temp->next) {
		(temp->time)--;
		if (temp->time == -1)
			addElementb(bany, temp->id);
	}
}
void wpisywanie(char *w, int tab[]) {
	int i = 0;
	printf("Wpisz rejestr: ");
	scanf("%c", *&w);
	while (getchar() != '\n' && i < 2)
	{
		scanf("%d", &tab[i++]);
	}
}

void addElement(list_t *list, int tab[])
{
	node_t *node = makeNode(tab);


	if (list->tail == NULL)
	{
		list->tail = node;
		list->head = node;
		return;
	}
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
}
void addElementb(list_b *bany, int a)
{
	node_b *node = makeNodeb(a);
	if (bany->tailb == NULL)
	{
		bany->tailb = node;
		bany->headb = node;
		return;
	}
	node->prevb = bany->tailb;
	bany->tailb->nextb = node;
	bany->tailb = node;
}
node_b *makeNodeb(int a)
{
	node_b *nodeb = malloc(sizeof(node_b));
	nodeb->prevb = NULL;
	nodeb->nextb = NULL;
	nodeb->idb = a;
	return nodeb;
}

node_t *makeNode(int tab[])
{
	node_t *node = malloc(sizeof(node_t));
	checkMemory(node);
	node->prev = NULL;
	node->next = NULL;
	node->id = tab[0];
	node->time = tab[1];
	return node;
}

void checkMemory(const void * const ptr)
{
	if (ptr == NULL)
	{
		errno = ENOMEM;
		perror("Nie mozna zaalokowac pamieci!");
		exit(EXIT_FAILURE);
	}
}

void printList(list_t *list)
{	node_t *temp;
	if (list->head == NULL)
	{
		puts("Brak elementow na liscie!");
		return 0 ;
	}
	
	for (temp = list->head; temp != NULL; temp = temp->next)
		if(temp->time<0)
		printf("BAN: Kod: %d, czas: %d\n", temp->id, temp->time);
		else
			printf("Kod: %d, czas: %d\n", temp->id, temp->time);
};
void printListb(list_b *bany)
{
	node_b *temp;
	if (bany->headb == NULL)
	{
		puts("Brak banow!");
		return 0;
	}

	for (temp = bany->headb; temp != NULL; temp = temp->nextb)
		printf("Kod: %d\n", temp->idb);
};

void removeList(list_t *list)
{
	while (list->head != NULL)
	{
		list->tail = list->head;
		list->head = list->head->next;
		free(list->tail);
	}
	list->head = NULL;
	list->tail = NULL;
}

int removeSpecified(list_t *list, int var)
{
	node_t *temp;
	if (list->head == NULL) {
		return 1;
	}

	for (temp = list->head; temp != NULL; temp = temp->next) {
		if (temp->id == var)
		{
			printf("Osoba juz jest w budynku!\n");
			return 2;
		}
	}
}
int removeSpecifiedb(list_b *bany, int var)
{
	node_b *temp;
	if (bany->headb == NULL) {
		return 1;
	}

	for (temp = bany->headb; temp != NULL; temp = temp->nextb) {
		if (temp->idb == var)
		{
			printf("Osoba ma bana!\n");
			return 2;
		}
	}
}
void removeSpecified2(list_t *list, int var)
{
	node_t *temp;
	if (list->head == NULL)
	{
		puts("Brak elementow na liscie!");
		return;
	}

	for (temp = list->head; temp != NULL; temp = temp->next)
		if (temp->id == var)
		{
			if (temp->prev == NULL)
			{
				list->head = list->head->next;
				list->head->prev = NULL;
			}
			else if (temp->next == NULL)
			{
				list->tail = list->tail->prev;
				list->tail->next = NULL;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			free(temp);
			return;
		}
	puts("Brak takiego elementu na liscie!");
}
