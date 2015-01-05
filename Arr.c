#include <stdio.h>

void KuAn(int KN[], int PINx[], double GH[], int ID) {
	//Initialisierung des 1. Elements im Array KM, PIN, GH 
	KN[ID] = 1234; //0 = 1.Zeile
	PINx[ID] = 9876;
	GH[ID] = 0.0;
}


int main() {
	//0-Initialisierung der Arrays
	int KundeID = 0;

	int KN[] = { 0 }; //Var erstellen
	int PIN[] = { 0 };
	double GH[] = { 0 };

	int f = 11;
	//Menu
	int auswahl;
	while (1) {
		printf("Menu\n"); //	\n = New line
		printf("1 - Kunde anlegen\n");
		printf("2 - kunde anmelden\n");

		scanf_s("%d", &auswahl);

		switch (auswahl) {

		case 1: 
			KuAn(KN, PIN, GH, KundeID++);//KundeID++ => kundeID = kundeID + 1
			//printf("%d, %d, %lf\n", KN[0], PIN[0], GH[0]);
				break; //verhindert, dass die nächste case abgearbeitet wird
		case 2:
			for (int i = 0; i < 10; i++)
			{
				printf("%d, %d, %lf\n", KN[i], PIN[i], GH[i]);
			}

		}



	}

	getch();
	return 0;
}