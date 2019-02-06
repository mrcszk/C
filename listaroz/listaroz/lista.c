#pragma warning(disable:4996) 
#include <time.h>
#include <stdio.h>

typedef struct tagListElement 
{ 
	struct tagListElement*next; 
	void*data; 
}ListElement;

typedef struct tagList 
{ 
	ListElement*head; 
	int size; 
	ConstDataFp dumpData; 
	DataFp freeData; 
	CompareDataFp compareData; 
}List;
/* inicjalizacja listy */ 
void init(List*list) 
{ 
	list->head = 0; 
	list->size = 0; 
	list->dumpData = 0; 
	list->freeData = 0; 
	list->compareData = 0; 
} 
/* zwolnienie pamięci listy */ 
void freeList(List*list) 
{ 
	ListElement*current = 0; 
	current = list->head; 
	while (current != 0) 
	{ 
		ListElement*todelete = current; 
		current = current->next; 
		if (list->freeData)list->freeData(todelete->data); 
		free(todelete); 
	} 
	list->size = 0; 
	list->head = 0; 
}
/* poszukiwanie ostatniego elementu */
ListElement*findLast(const List*list)
{
	ListElement*last = 0;
	ListElement*current = 0;
	for (current = list->head; current != 0; current = current->next) {
		last = current;
	}
	return last;
}
/* miejsce wstawienia */
ListElement*findInsertionPoint(const List*list, ListElement* element)
{
	ListElement*insertionPoint = 0;
	ListElement*current = 0;
	for (current = list->head; current != 0; current = current->next) {
		if (list->compareData(current->data, element->data) <= 0)
			insertionPoint = current;
	} // else break;
	return insertionPoint;
}
/* dodanie danych do listy */ void add(List*list, void*data) {
	ListElement*element = (ListElement*)malloc(sizeof(ListElement)); 
	element->next = 0; element->data = data; 
	if (!list->compareData) 
	{ 
		// bez sortowania 
		ListElement*last = findLast(list); 
		if(last==0)list->head=element; 
		else last->next=element; 
	}else
	{ 
		// sortowanie podczas wstawiania 
		ListElement*insertionPt = findInsertionPoint(list,element); 
		if(insertionPt==0)
		{ 
			element->next=list->head; 
			list->head=element; 
		}
		else
		{ 
			element->next=insertionPt->next; 
			insertionPt->next=element; 
		} 
	} 
	list->size++; 
}
/* wypisanie zawartości */ 
void dumpList(const List*list) 
{ 
	ListElement*i; 
	for (i = list->head; i != 0; i = i->next) 
	{ 
		if (list->dumpData)list->dumpData(i->data); 
		else printf("%p ", i->data); 
	} 
}
/* testy */ 
void printString(const void*data) 
{ 
	printf("%s ", data); 
}
void test1() 
{ 
	List list; 
	init(&list); 
	list.dumpData = printString; 
	add(&list, "Ala"); 
	add(&list, "ma"); 
	add(&list, "kota"); 
	add(&list, "i"); 
	add(&list, "psa"); 
	dumpList(&list); 
	freeList(&list); 
}
int compareString(const void*e1, const void*e2) 
{ 
	return stricmp((const char*)e1, (const char*)e2); 
} 
void test2() 
{ 
	List list; 
	init(&list); 
	list.dumpData = printString; 
	list.compareData = compareString; 
	add(&list, "Ala"); 
	add(&list, "ma"); 
	add(&list, "kota"); 
	add(&list, "i"); 
	add(&list, "psa"); dumpList(&list); freeList(&list); 
}

void freeMemory(void*e1)
{
	free(e1);
}
void test3()
{
	List list;
	init(&list);
	list.dumpData = printString;
	list.compareData = compareString;
	list.freeData = freeMemory;
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 100; i++) {
		char buf[256];
		sprintf(buf, "%d", rand());
		add(&list, strdup(buf));
	}
	dumpList(&list);
	freeList(&list);
}
int main(void) {
	test2();
	getchar();
	getchar();
	return 0;
}