#include <stdio.h>

// x^n -> Potenz
int pow(x, n) {
	int y = 1;
	while (n > 0)
	{
		if (n % 2 == 1) y *= x;
		x *= x; n /= 2;
	}
	return y;
}



int main() {

	printf("%i", pow(3,4));
	getch();
	return 0;
}