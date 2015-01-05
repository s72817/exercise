#include <stdio.h>
#include "calc.c"

int main(int argc, char *argv[]) {
	printf("%d\n", calc(argv + 1, argc - 1));
	return 0;
}