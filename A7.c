#include <stdio.h>


int f(int x, int y) {
	//return ((x != y) && (x >= 0 && y >= 0)) == 0;
	return (x >= 0 || y >= 0 || x != y) == 1;
}

int f1(int x, int y) {
	if (x != y) {
		if (x >= 0) return 1;
		else if (y >= 0) return 1;
		else return 0;
	}
	else return 0;
}

int f2 (int x, int y) {
	return (x != y) && ((x >= 0) || (y >= 0));
}


int main()
{

	int x = -9;
	int y = -7;

	printf("%d\n", f2(x,y));
	printf("%d", f1(x, y));


	//char string[] = "Hello World";
	//printf("%d", textx);
	getch();
	return 0;
}