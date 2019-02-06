#include <stdio.h>

typedef struct ListElement
{
	int number;
	struct ListElement*next;
}ListElement;

typedef struct List
{
	ListElement*head;
}List;
void init(List*list)
{
	list->head = 0;
}

void add(List*list, int number)
{
	ListElement*tmp = (ListElement*)malloc(sizeof(ListElement));
	int i = 0;
	tmp->next = list->head;
	tmp->number = number;
	if (list->head != 0)
	{
		list->head = tmp;
	}
	else
	{
		list->head  = tmp;
	}
}

void reverse(List*list) {
	ListElement*tmp = 0;
	ListElement * help = list->head;
	ListElement * help2 = 0;
	ListElement * first = list->head;
	tmp = 0;
	help2 = 0;
	tmp = help->next;
	help->next = help2;	
	help2 = help;
	help = tmp;
	while (tmp->next != 0) {
		tmp = tmp->next;
		help->next = help2;
		help2 = help;
		help = tmp;
	}
	list->head = tmp;
	list->head->next = help2;	
}
void printList(List*list)
{
	ListElement*tmp;
	for (tmp = list->head; tmp != 0; tmp = tmp->next) {
		printf("%d  ", tmp->number);
	}
	printf("\n");
}
int main(void) {

	List list;
	init(&list);
	add(&list, 1);
	add(&list, 2);
	add(&list, 3);
	add(&list, 4);
	add(&list, 5);
	add(&list, 6);
	printList(&list);
	reverse(&list);
	printList(&list);
	reverse(&list);
	printList(&list);
	getchar();
	getchar();
	return 0;
}
