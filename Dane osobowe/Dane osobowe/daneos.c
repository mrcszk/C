#include <stdio.h>

typedef struct ListElement
{
	int day;
	int month;
	int year;
	char *name;
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
void add_front(List*list, char name[], int day, int month, int year)
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i = 0;
	tmp->next = list->head;
	tmp->day = day;
	tmp->month = month;
	tmp->year = year;
	tmp->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(tmp->name, name);
	if (list->head != 0)
	{
		list->head = tmp;
	}
	else
	{
		list->head = list->tail = tmp;
	}
}
int date_compare(ListElement *t1, ListElement *t2) {
	// returns 1 if t1 greater than t2, -1 if t1 < t2, 0 if equal
	if (t1->year > t2->year) return(1);
	if (t1->year < t2->year) return(-1);
	// year matches. so check month
	if (t1->month > t2->month) return(1);
	if (t1->month < t2->month) return(-1);
	// month aslo matches. so check day
	if (t1->day > t2->day) return(1);
	if (t1->day < t2->day) return(-1);
	// day also matches
	return(0);
}
void addsorted(List*list, char name[], int day, int month, int year)
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	ListElement*help = list->head;
	int i = 0;
	tmp->day = day;
	tmp->month = month;
	tmp->year = year;
	tmp->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(tmp->name, name);
	if (help == 0)
	{
		tmp->next = list->head;
		list->head = tmp;
		list->tail = tmp;
	}
	else if (help->next == 0) {
		if (1 == date_compare(help, tmp)) {
			tmp->next = list->head;
			list->head = tmp;
		}
		else
		{
			list->head->next = tmp;
			tmp->next = 0;
			list->tail = tmp;
		}
	}
	else if (1 == date_compare(help, tmp)) {
		tmp->next = list->head;
		list->head = tmp;
	}
	
	else {
		while (1 == date_compare(help->next, tmp))
		{
			help = help->next;
			if (help->next == 0)
			{
				list->tail = tmp;
				break;
			}
		}
		tmp->next = help->next;
		help->next = tmp;
	}
}
/* Dodawanie danych do listy z tyłu*/
void add_back(List*list, char name[], int day, int month, int year)
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i = 0;
	tmp->next = 0;
	tmp->day = day;
	tmp->month = month;
	tmp->year = year;
	tmp->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(tmp->name, name);
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
	ListElement*tmp = list->head;
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
	while (tmp != 0) {
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
		printf("%s ", tmp->name);
		printf("%d.", tmp->day);
		printf("%d.", tmp->month);
		printf("%d\n", tmp->year);
	}
}
int main(void)
{

	List list;
	init(&list);
	int i;
	addsorted(&list, "AAA aa", 1, 2, 1284);
	addsorted(&list, "AAA aa", 1, 2 ,1290);
	
	addsorted(&list, "AAA aa", 1, 2, 1226);	
	addsorted(&list, "AAA aa", 1, 2, 1224);
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


	add_front(&list, "AAA aa", 1, 2, 1290);
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