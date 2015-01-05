#include <stdio.h>


//----------------------------
// Fakultätsberechnung iterativ und rekursiv
// + Übersicht: Das kleine 1x1
// by Richard Kerber
//--------------------------


//iterativ
int ifakultaet(int k) {
	long sum = 1; //Wenn hier 0 steht, kommt auch 0 raus ;)
	for (int i = 1; i <= k; i++)
		sum *= i;
	return sum;
}

//rekursiv
int rfakultaet(int k) {
	if (k == 0) return 1;
	else return k * rfakultaet(k - 1);
}


int main() {

	printf("\n\n----------------------------------");
	printf("\n------Fakultaet iterativ----------\n");
	printf("----------------------------------\n\n");
	//von 1 bis 10
	for (int i = 0; i <= 10; i++)
	{
				printf("%lu\n", ifakultaet(i));
	}

	printf("\n\n----------------------------------");
	printf("\n------Fakultaet rekursiv----------\n");
	printf("----------------------------------\n\n");
	//von 1 bis 10
	for (int i = 0; i <= 10; i++)
	{
		printf("%lu\n", rfakultaet(i));
	}

	printf("\n\n----------------------------------");
	printf("\n-----------Das kleine 1x1---------\n");
	printf("----------------------------------\n\n");

	for (int i = 1; i <= 10; i++)
	{
		for (int k = 1; k <= 10; k++)
		{
			printf("%-5d", i * k);
		}
		
		printf("\n\n");
	}

	getchar();
	return 0;
}