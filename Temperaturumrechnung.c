#include <stdio.h>

//----------------------------
// Temperaturumrechnung
// von Fahrenheit in Celsius
// by Richard Kerber
//--------------------------

double F_to_C(double fahrenheit) {
		return 5.0 * (fahrenheit - 32.0) / 9.0;
}



int main() {
	int lower = 0, upper = 50, step = 5;

	printf("\n------by Richard Kerber---------\n");
	printf("\n--------------------------------");
	printf("\n-----Fahrenheit to Celsius------\n");
	printf("--------------------------------\n\n");

	printf("\nlower = %d, upper = %d, step = %d\n\n", lower, upper, step);

	for (int i = lower; i <= upper; i += step)
	{
		printf("%d Fahrenheit = %lf Celsius\n",i, F_to_C(i));
	}

	getch();
	return 0;
}