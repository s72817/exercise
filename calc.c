#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
// Postfix-Rechner

int isnum(char *a) {
	if (*a == '\0') return 1;
	else return isdigit(*a) && isnum(a + 1);
}


int calc(char *expr[], int expr_length) {
	int k, n1, n2;
	stack *s = NULL;

	for (k = 0; k < expr_length; k++) {
		if (isnum(expr[k])) stack_push(&s, atoi(expr[k]));
		else { // Operator erwartet
			if (stack_isempty(&s)) {
				printf("Missing operand\n");
				exit(EXIT_FAILURE);
			}
			n2 = stack_pop(&s);
			n1 = stack_pop(&s);
			switch (expr[k][0]) {
			case '+': stack_push(&s, n1 + n2); break;
			case '-': stack_push(&s, n1 - n2); break;
			case '*': stack_push(&s, n1 * n2); break;
			case '/': stack_push(&s, n1 / n2); break;
			default: printf("Syntax error: %s unexpected\n", expr[k]); exit(EXIT_FAILURE);
			}
		}
	}
	n1 = stack_pop(&s);
	if (stack_isempty(&s)) return n1;
	else {
		printf("Missing operand\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]) {
	printf("%d\n", calc(argv + 1, argc - 1));
	return 0;
}
