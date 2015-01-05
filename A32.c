#include <stdlib.h>
#include <stdio.h>

struct _list {
	int item;
	struct _list *next;
};
typedef struct _list list;

list *l = NULL; //Anfang
list *new_el = NULL; //eig. Struct

void add(int item) {
	(*new_el).item = item;
	(*new_el).next = l;
	l = new_el;
}

int main() {
	// Zeiger auf den Anfang der Liste (initial leer)
	//list *l = NULL;

	// Speicher für neues Element anlegen
	//list *new_el = (list*)malloc(sizeof(list));
	
	new_el = (list*)malloc(sizeof(list));

	// Wert in neuem Element speichern
	//new_el->item = 1;  
	//(*new_el).item = 1;

	// Neues Element am Anfang der Liste einfügen
	//new_el->next = l;
	//(*new_el).next = l;
	//l = new_el; //zuweisung an den anfang
	for (int i = 0; i <= 10; i++)
		add(i);

	/*for (int i = 0; i <= 10; i++)
	{
		printf("%d\n", (*l).item);
		new_el = l;
		l = l->next;
		free(new_el);
	}*/

		//for (int i = 0; i <= 10; i++)
		//{
			while (new_el != NULL)
			{
				printf("%d\n", l->item);
				l = l->next;
				//new_el = l;
				//l = l->next;
			}
		//}
	
		free(new_el);

	// l besteht jetzt aus einem Element, in dem 1 gespeichert ist
	//printf("%d\n", (*l).item);

	// Element mit dem Wert 1 löschen
	//new_el = l;
	//l = l->next;

	//free(new_el);

	// Liste ist wieder leer
	getch();
	return 0;
}



