#include <stdlib.h>
#include <stdio.h>

struct _list {
	int item;
	struct _list *next;
};
typedef struct _list list;

list *l = NULL;

void push(int item) {
	list *new_el;
	// Speicher für neues Element anlegen
	new_el = (list*)malloc(sizeof(list));
	// Wert in neuem Element speichern
	new_el->item = item;
	// Neues Element am Anfang der Liste einfügen
	new_el->next = l;
	l = new_el;
}

void pop() {
	while (l->next != NULL) {
		l = l->next;
		printf("%d\n", l->item);
		//free(l);
	}
}

int is_empty() {
	if (l == NULL) return 0;
	else return 1;
}

int main() {
	/*for (int i = 1; i <= 11; i++)
		push(i);*/
	
	if (is_empty == 0) 
	{
		printf("Nüscht\n");
	}
	else pop();

	

	getch();
	return 0;
}