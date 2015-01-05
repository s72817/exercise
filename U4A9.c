#include <stdio.h>


int A(int m, int n) {
	if (m == 0) return n + 1;
	else if (n == 0) return A(m - 1, 1);
	else return A(m - 1, A(m, n - 1));
}


int main(void) {
	int m = 3;
	int n = 66;

	printf("Ackermann fuer %d, %d = %d", m, n, A(m, n));

	getchar();
	return 0;
}