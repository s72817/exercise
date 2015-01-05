#include <stdio.h>
#include <time.h>


//----------------------------
// Schaltjahrberechnung
// mit Zeitmessung
// by Richard Kerber
//--------------------------


int Schaltjahr(int jahr) {
	//langsamer
	/*if (jahr % 4 == 0) return 1;
	if (jahr % 100 == 0) return 0;
	if (jahr % 400 == 0) return 1;*/

	//schneller
	if ((jahr % 4 == 0) && (jahr % 100 != 0))  return 1;
	else if (jahr % 400 == 0) return 1;
	else return 0;
	
	
}


int main(void) {

	clock_t prgstart, prgende; //Definierung der Variablen
	prgstart = clock(); //CPU-Zeit zu Beginn des Programmes

	//Anfang des eigentlichen Programmes
	for (int i = 1800; i <= 2100; i++)
	{
		if (Schaltjahr(i) == 0) printf("Das Jahr %d ist kein Schaltjahr\n", i);
		else if (Schaltjahr(i) == 1) printf("Das Jahr %d ist ein Schaltjahr.\n", i);
		else printf("Ungültiges Jahr!\n");
	}
	//Ende des eigentlichen Programmes


	prgende = clock();//CPU-Zeit am Ende des Programmes
	printf("\nLaufzeit %.2f Sekunden\n", (float)(prgende - prgstart) / CLOCKS_PER_SEC);


	getch();
	return 0;
}