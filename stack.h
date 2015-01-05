#include <stdlib.h>
#include <stdio.h>

// Class stack
typedef struct _stack {
	int item;
	struct _stack *next;
} stack;

void stack_push(stack **s, int item) {
	stack *top = (stack*)malloc(sizeof(stack));
	if (!top) {
		printf("stack_push: out of memory\n");
		return;
	}
	top->item = item;
	top->next = *s;
	*s = top;
}

int stack_pop(stack **s) {
	stack *top = *s;
	if (!*s) {
		printf("stack_pop: empty stack\n");
		abort();
	}
	int item = top->item;
	*s = top->next;
	free(top);
	return item;
}

int stack_isempty(stack **s) {
	stack *top = *s;
	if (top == NULL) return 1;
	else return 0;
}