#include <stdio.h>

struct stack {
	int wert;
	struct stack *next;
};


typedef struct stack stack_t; //zur Bequemlichkeit




int main() {
	int wert;
	stack_t *top, *neu, *aktuell;

	top = NULL; //Listenanker

	for (int i = 1; 1 <= 10; i++)
	{
		//hier push(i)
		neu = (stack_t*)malloc(sizeof(stack_t));
		neu->next = top;
		neu->wert = i; //

		top = neu; // neue liste startet jetzt mit dem neuen Element
	}


	aktuell = top;
	for (int i = 1; i <= 10; i++)
	{
		wert = aktuell->wert;
		printf("Wert:%d\n", wert);
		//hier wert = pop();
		//und wert ausgeben
		aktuell = aktuell->next;
	}


	return 0;
}