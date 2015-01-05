#include <stdio.h>
#include <math.h>

//Binärzahl wird zu Dezimalzahl umgerechnet
int BiToDe(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7)
{
	return i0 * pow(2, 7) + i1 * pow(2, 6) + i2 * pow(2, 5) + i3 * pow(2, 4) + i4 * pow(2, 3) + i5 * pow(2, 2) + i6 * pow(2, 1) + i7 * pow(2, 0);	
}

//Versuch einer Umwandlung
int BiToDe1(char input[])
{
	for (int i = 0; i < sizeof(input); i++)
		return i * pow(2, i);
}


int main() {

	//8Bit Ganzzahl
	int i0 = 1;
	int i1 = 1;
	int i2 = 1;
	int i3 = 1;
	int i4 = 0;
	int i5 = 1;
	int i6 = 0;
	int i7 = 1;
	char text[] = { "01011001" };

	//Ausgabe der Umgewandelten Binärzahl
	printf("Der Dezimalwert fuer folgende Binaerzahl %d%d%d%d%d%d%d%d\nbetraegt\n%d\n",i0,i1,i2,i3,i4,i5,i6,i7, BiToDe(i0,i1,i2,i3,i4,i5,i6,i7));
	printf("%s", BiToDe1(text));
	//printf("%i\n", pow(2, 2));


	getch();
	return 0;
}
