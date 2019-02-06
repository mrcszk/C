#include <stdio.h>

typedef struct ListElement
{ 	
	int ocena; 
	char *nazwa;
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

/* Dodawanie danych do listy z przodu*/ 
void add_front(List*list, int ocena, char nazwa[]) 
{ 
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i = 0;
	tmp->next = list->head;
	tmp->ocena = ocena;
	tmp->nazwa = (char*)malloc((strlen(nazwa) + 1) * sizeof(char));
	strcpy(tmp->nazwa, nazwa);
	if (list->head != 0)
	{ 
		list->head = tmp;
	} else 
	{ 
		list->head = list->tail = tmp;
	} 
}
/* Dodawanie danych do listy z tyłu*/
void add_back(List*list, int ocena,char nazwa[])
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i = 0;
	tmp->next = 0;
	tmp->ocena = ocena;
	tmp->nazwa = (char*)malloc((strlen(nazwa) + 1) * sizeof(char));
	strcpy(tmp->nazwa, nazwa);
	if (list->tail != 0) {
		list->tail->next = tmp;
		list->tail = tmp;
	}
	else {
		list->head = list->tail = tmp;
	}
}

/* Usuwanie pierwszego elementu */
void delete_front(List*list) {
	ListElement*tmp;
	if (list->head == 0)
		return;
	tmp = list->head;
	list->head = list->head->next;
	if (list->head == 0)
		list->tail = 0;
	free(tmp);
}

/* Usuwanie ostatniego elementu */
void delete_back(List*list) {
	ListElement*tmp= list->head;
	while (tmp->next->next != 0) {
		tmp = tmp->next;
	}
	
	list->tail = tmp;
	tmp->next = NULL;
	if (list->head == 0)list->tail = 0;
	free(list->tail->next);
}

int amount(List*list) {
	int i = 0;
	ListElement*tmp = list->head;
	while (tmp!= 0) {		
		tmp = tmp->next;
		i++;
	}
	return i;
}

/* Zwalnianie całej listy */
void deleteList(List*list)
{
	while (list->head) {
		delete_front(list);
	}
}

/* Wypisanie zawartości listy*/
void printList(List*list)
{
	ListElement*tmp;
	for (tmp = list->head; tmp != 0; tmp = tmp->next) {
		printf("%d ", tmp->ocena);
		printf("%s\n", tmp->nazwa);
	}
}
int main(void)
{

	List list;
	init(&list);
	int i;

	add_back(&list, 2, "Analiza");
	add_back(&list, 3, "Algebra");
	add_back(&list, 4, "WDI");
	add_back(&list, 5, "JIMP");
	i = amount(&list);
	printf("Ilosc %d\n", i);	
	printList(&list);
	printf("\n");


	delete_back(&list);
	i = amount(&list);
	printf("Ilosc %d\n", i);	
	printList(&list);
	printf("\n");


	delete_front(&list);
	i = amount(&list);
	printf("Ilosc %d\n", i);	
	printList(&list);
	printf("\n");


	add_front(&list, 1, "W-F");
	i = amount(&list);
	printf("Ilosc %d\n", i);	
	printList(&list);
	printf("\n");


	deleteList(&list);
	i = amount(&list);
	printf("Ilosc %d\n", i);
	printList(&list);

	getchar();
	getchar();
	return 0;
}