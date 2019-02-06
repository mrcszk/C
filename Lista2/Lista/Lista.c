// Marcin Sawczuk wtorek 9:30
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

struct ListElement {
	int numer;
	char nazwa[BUFFER_SIZE];

	struct ListElement *next;
};

struct List {
	struct ListElement *head;
};

struct List createList() {
	struct List list;
	list.head = NULL;
	return list;
}

struct ListElement createListElement(char nazwa[], int numer) {
	struct ListElement element;
	element.numer = numer;
	strcpy(element.nazwa, nazwa);
	element.next = NULL;

	return element;
}

void printListElement(struct ListElement *element) {
	printf("Nazwa: %s\n", element->nazwa);
	printf("Ocena: %d\n", element->numer);
	
}

void printList(struct List *list) {
	struct ListElement *nextElement = list->head;

	while (nextElement != NULL) {
		printListElement(nextElement);
		nextElement = nextElement->next;
	}
}

void addElement(struct List *list, struct ListElement *element) {
	struct ListElement **nextElement = &list->head;

	while ((*nextElement) != NULL) {
		nextElement = &((*nextElement)->next);
	}

	*nextElement = element;
}




int main(void) {
	struct List list;
	struct ListElement element1;
	struct ListElement element2;
	struct ListElement element3;

	list = createList();
	element1 = createListElement("Analiza", 5);
	element2 = createListElement("JIMP",  5);
	element3 = createListElement("WDI", 5);

	addElement(&list, &element1);
	addElement(&list, &element2);
	addElement(&list, &element3);
	printList(&list);


	getchar();
	getchar();
	return 0;
}