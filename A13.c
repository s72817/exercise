#include <stdio.h>

int MaxRenditePos;

//Rendite der banken
double Rendite(double a, double b, double c, double d)
{
	return ((1.0 + a)*(1.0 + b)*(1.0 + c)*(1.0 + d) - 1) * 100;
	//Kap. nach 1 Jahr = Startkapital * (1.0 + Zinsen/100.0)
}

double Rendite1(double a[], int anz) {
	double sum = 1.0;
	for (int i = 0; i < anz; i++) {
		sum *= 1.0 + a[i];
	}
	return (sum - 1) * 100;
}

double Renditemax(double Arr[], int anz) {
	double Maxwert = Arr[0];
	
	for (int i = 1; i < anz; i++) {
		if (Maxwert < Arr[i])
		{
			Maxwert = Arr[i];
			MaxRenditePos = i; //Hier wird Pos übergeben
		}
	}
	return Maxwert;
}

//int ArrPos(double Arr[], int anz, double Wert) {
//	int Pos = 0;
//	for (int i = 1; i < anz; i++) {
//		if (Arr[i] = Wert) Pos = i;
//		break;
//	}
//	return Pos;
//}

void Bankmax(char Banken[], double Renditemax){
	printf("Die Bank %c hat die hoechste Rendite mit %.2lf%%.", Banken[MaxRenditePos], Renditemax);
}

////berechnet die Array Länge | Array Lenght
//int ArrLen(double Arr[]) {
//	return (sizeof(Arr) / sizeof(Arr[0]));
//}




int main() {

	double A [] = {0.02, 0.03, 0.04, 0.05, 0.03, 0.02, 0.09};
	double B [] = {0.09, 0.09, 0.09, 0.09};
	double C [] = {0.02, 0.02, 0.06, 0.01, 0.04, 0.07, 0.08};


	//1x alle Renditen + 1x alle Banken
	double MaxArray [] = { Rendite1(A, 7), Rendite1(B, 4), Rendite1(C, 7) };
	char Banken[] = {'A', 'B', 'C'};

	printf("\n--------------------------\n");
	printf("--------Rendite-----------\n");
	printf("--------------------------\n\n");

	printf("Die Rendite der Bank A betraegt %.2lf%%\n", Rendite1(A, 7));
	printf("Die Rendite der Bank B betraegt %.2lf%%\n", Rendite1(B, 4));
	printf("Die Rendite der Bank C betraegt %.2lf%%\n", Rendite1(C, 7));

	printf("\n--------------------------\n\n");

	Bankmax(Banken, Renditemax(MaxArray, 3));
	
	getch();
	return 0;
}