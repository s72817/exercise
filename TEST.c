#include <stdio.h>


int eq(char s1[], char s2[]) {
	return s1 == s2;
}

int f(int a[], int n, int v) {
	/*if (n == 0) return 0;
	else if (a[0] == v) return 1;
	else return f(a + 1, n - 1, v);*/
	return a + 1;
}

void swap(int *a, int *b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main() {

	
	/*int a[] = {4,0,0};
	int n = 3;
	int v = 4;*/


	//printf("%d\n", f(a, n, v));
	
	/*char a[] = "Hallo";
	char b[] = "Welt";*/
	
	//printf("%s\n", eq(a,b));


	int a = 3, b = 4;
	swap(&a, &b);
	printf("a=%d, b=%d", a,b);


	getch();
	return 0;
}