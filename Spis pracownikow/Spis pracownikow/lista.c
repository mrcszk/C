#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct node
{
	char* nazwa;
	int ocena;


	struct node *next, *prev;
}node_s;
typedef struct list
{
	node_s *head;
	node_s *tail;
}list_s;
void checkMemory(const void * const ptr);
void addElement(list_s *list, char w, int ocena);
node_s *makeNode(char w, int ocena);
void wpisywanie(char w[], int *liczba);
void removeSpecified(list_s *list, int var);
void printList(list_s *list);
void ile(list_s *list);
int main(void)
{
	//int i; 
	//char b;

	//for (i = 65; i <= 26; i++) {
	//	b = (char)i;
	//	list_s *b = malloc(sizeof(list_s));
	//	checkMemory(b);
	//	b->head = NULL;
	//	b->tail = NULL;
	//}
	char w[30];
	int ocena;
	char *word;
	list_s *list = malloc(sizeof(list_s));
	checkMemory(list);
	list->head = NULL;
	list->tail = NULL;
	wpisywanie(w, &ocena);
	addElement(list, &w , ocena);
	printList(list);
getchar();
getchar();
return 0;
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
void addElement(list_s *list,char *w, int ocena)
{
	char *word;
	
	word = (char*)malloc(strlen(w) * sizeof(char)); /*  alokacja pamieci */
	strcpy(word, w); /* przepisanie z bufora na styrte */
	node_s *node = makeNode(word,ocena);
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
void printList(list_s *list)
{
	node_s *temp;
	if (list->head == NULL)
	{
		puts("Brak elementow na liscie!");
		return 0;
	}

	for (temp = list->head; temp != NULL; temp = temp->next)
		printf("Przedmiot %s, ocena %d\n", temp->nazwa,temp->ocena);
}

void ile(list_s *list)
{
	int i=0;
	node_s *temp;
	if (list->head == NULL)
	{
		puts("Brak elementow na liscie!");
		return 0;
	}

	for (temp = list->head; temp != NULL; temp = temp->next) {
		i++;
		printf("Jest %d elementow.", i);
	}
}
		
node_s *makeNode(char w, int ocena)
{
	node_s *node = malloc(sizeof(node_s));
	checkMemory(node);
	node->prev = NULL;
	node->next = NULL;
	node->nazwa = w;
	node->ocena = ocena;
	return node;
}
void wpisywanie(char w[], int *liczba) {
	printf("Wpisz nazwisko: ");
	scanf("%c", w);
	while (getchar() != '\n')
		continue; /* czyści wiersz wejściowy */
	printf("Wpisz ocene: ");
	scanf("%d", *&liczba);
	while (getchar() != '\n')
		continue; /* czyści wiersz wejściowy */

}
void removeSpecified(list_s *list, int var)
{
	node_s *temp;
	if (list->head == NULL)
	{
		puts("Brak elementow na liscie!");
		return;
	}

	for (temp = list->head; temp != NULL; temp = temp->next)
		if (temp->nazwa == var)
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
