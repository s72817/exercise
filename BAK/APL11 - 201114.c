/*----------------------------
APL Programmierung 1, Teil 1
by Richard Kerber
17.11.2014
------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define MAXKunde 30

/*----------------------------
Globale Variabelen
------------------------------*/
static int KundeID = 0;

/*----------------------------
deklariert den Strukturtyp kunde
------------------------------*/
struct kunde {         
	int  Kontonummer;
	double Guthaben;
	int PIN;
	int isLogged;
	int isBlocked;
} kunden[MAXKunde]; //Max 20 Kunden können angelegt werden


/*----------------------------
Formatierter Ausgabetext
------------------------------*/
void Status(char *text) {
	printf("\n\n----------------------------\n");
	printf("%s\n", text);
	printf("----------------------------\n\n");
}

/*----------------------------
Funktionen
------------------------------*/
int GetRandKontonummer(int KundeID){
	int min = 1000, max = 9999;
	srand(KundeID); //Rand wird hier neu initialisiert
	return (rand() % (max - min + 1)) + min;
}

int GetRandPIN(int KundeID) {
	int min = 1000, max = 9999;
	return (rand() % (max - min + 1)) + min;
}

void Suche(struct kunde suche[]) {
	for (int i = 0; i <= MAXKunde; i++)
	{
		/*printf("%d", i);*/
		printf("%d\n", suche[i].Kontonummer);
	}
}

/*----------------------------
Einen nuene Kunden anlegen
------------------------------*/
void Kunde_anlegen(int KundeID, struct kunde neu[]) {
	//Kunde mit Daten anlegen
	neu[KundeID].Kontonummer = GetRandKontonummer(KundeID);
	neu[KundeID].Guthaben = 0.0;
	neu[KundeID].PIN = GetRandPIN(KundeID);

	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
	printf("KundenID......: %d\n", KundeID);
	printf("Kontonummer...: %d\n", neu[KundeID].Kontonummer);
	printf("Guthaben......: %.2lf Euro\n", neu[KundeID].Guthaben);
	printf("Pin...........: %d\n", neu[KundeID].PIN);
	printf("----------------------------\n");
}







int main(void) {
	struct kunde SKunde; //Aktuelle Session eines Kunden T

	int auswahl;
	Status("Das interaktive Banksystem\nby Richard Kerber");
	printf("Bitte waehlen Sie eine Option aus dem Menue,\nindem Sie die jeweilige Taste druecken:\n\n");
	do
	{
		printf("\n");
		printf("1: Einen neuen Kunden anlegen\n");
		printf("2: Anmelden\n");
		printf("3: Einzahlung\n");
		printf("4: Auszahlung\n");
		printf("5: Ueberweisung\n");
		printf("6: Kontostand\n");
		printf("7: 4-stellige Pin aendern\n");
		printf("8: Kundendaten anzeigen\n");
		printf("9: Abmelden\n");
		printf("10: Beenden\n");

		printf("\nIhre Wahl:\n");
		scanf_s("%d", &auswahl);

		switch (auswahl)
		{
		case 1:	//Einen neuen Kunden anlegen
			if (KundeID <= 20)
			{
				Kunde_anlegen(KundeID++, kunden); //Laufindex wird immer um 1 erhöht
			}
			else
			{
				Status("Sie koennen nicht mehr Kunden anlegen!");
			}
			
			break; //Wichtig, da sonst weiter abgearbeitet wird
		case 2:	//Anmelden
			Suche(kunden);
			break;
		case 3:	//Einzahlung
			
			break;
		case 4:	 //Auszahlung
			
			break;
		case 5:

			break;

		case 6:	 //Kontostand
			
			break;
		case 7:	 //4-stellige Pin aendern
			
			break;
		case 8: //Kundendaten anzeigen
			
			break;
		case 9:	 //Abmelden
			
			break;
		case 10: return 0; //Beenden
		default: Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");

		}
	} while (auswahl<10); //Ende der Schleife bei Eingabe der Zahl 8
	return 0;




}