#include <stdio.h>
#include <assert.h>

int MaxRenditePos;

//Rendite der banken dyn.
double Rendite(double a[], int anz) {
	double sum = 1.0;
	for (int i = 0; i < anz; i++) {
		sum *= 1.0 + a[i];
	}
	//assert(((sum - 1) * 100) <= 0);
	return (sum - 1) * 100;
}

// Max Rendite
double Renditemax(double Arr[], int anz) {
	double Maxwert = Arr[0];
	for (int i = 1; i < anz; i++) {
		if (Maxwert < Arr[i])
		{
			Maxwert = Arr[i];
			MaxRenditePos = i; //Hier wird Pos übergeben
		}
	}
	//assert(Maxwert <= 0);
	return Maxwert;
}

void Bankmax(char Banken[], double Renditemax){
	printf("Die Bank %c hat die hoechste Rendite mit %.2lf%%.", Banken[MaxRenditePos], Renditemax);
}

////berechnet die Array Länge | Array Lenght
//int ArrLen(double Arr[]) {
//	return (sizeof(Arr) / sizeof(Arr[0]));
//}


int main() {

	//double A[] = { 0.02, 0.03, 0.04, 0.05, 0.03, 0.02, 0.09 };
	//double B[] = { 0.09, 0.09, 0.09, 0.09 };
	//double C[] = { 0.02, 0.02, 0.06, 0.01, 0.04, 0.07, 0.08 };


	////1x alle Renditen + 1x alle Banken
	//double MaxArray[] = { Rendite(A, 7), Rendite(B, 4), Rendite(C, 7) };
	//char Banken[20] = { 'A', 'B', 'C' };
	//

	//printf("\n--------------------------\n");
	//printf("--------Rendite-----------\n");
	//printf("--------------------------\n\n");

	//printf("Die Rendite der Bank A betraegt %.2lf%%\n", Rendite(A, 7));
	//printf("Die Rendite der Bank B betraegt %.2lf%%\n", Rendite(B, 4));
	//printf("Die Rendite der Bank C betraegt %.2lf%%\n", Rendite(C, 7));

	//printf("\n--------------------------\n\n");

	//Bankmax(Banken, Renditemax(MaxArray, 3));


	//Prüfroutine
	double AT[] = { 1.3, -0.03, 0.5, 0.0, 0.03, 0.02, 0.09 };
	double BT[] = { 0.5, 0.09, 0.09, 0.09 };
	double CT[] = { 0.02, 6.5, 10.7, 0.01, 90.9, 0.07, 0.08 };

	double MaxArrayT[] = { Rendite(AT, 7), Rendite(BT, 4), Rendite(CT, 7) };
	char BankenT[20] = { 'A', 'B', 'C' };
	
	printf("Die Rendite der Bank A betraegt %.2lf%%\n", Rendite(AT, 7));
	printf("Die Rendite der Bank B betraegt %.2lf%%\n", Rendite(BT, 4));
	printf("Die Rendite der Bank C betraegt %.2lf%%\n", Rendite(CT, 7));

	printf("\n--------------------------\n\n");

	Bankmax(BankenT, Renditemax(MaxArrayT, 3));

	getch();
	return 0;
}