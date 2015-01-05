/*----------------------------
APL Programmierung 1, Teil 1
by Richard Kerber
17.11.2014
------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //boolesche Datentypen
#define MAXKunde 30

/*----------------------------
Globale Variabelen
------------------------------*/
int KundeID = 0;
int isLogged = 0;

/*----------------------------
deklariert den Strukturtyp kunde
------------------------------*/
struct kunde {         
	int  Kontonummer;
	double Guthaben;
	int PIN;
	//int isLogged;
	int isBlocked;
} kunden[MAXKunde]; //Max 20 Kunden k�nnen angelegt werden


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

int Suche(struct kunde suche[], int Kontonummer, int *KundeID) { //struct kunde *SKunde) {
	//Achtung: Hier bei der Suche darf kein else mit return 0 rein, da sonst nur erster Wert �berpr�ft wird!!!
	int result = 0;
	for (int i = 0; i <= MAXKunde; i++)
	{
		if (suche[i].Kontonummer == Kontonummer)
		{
			*KundeID = i;
			result = 1;
			break;
		}		
	}
	return result;
}

int Pruefen(int Kontonummer, int PIN) {
	int result = 0;
	for (int i = 0; i <= MAXKunde; i++)
	{
		if ((kunden[i].Kontonummer == Kontonummer) && (kunden[i].PIN == PIN))
		{
			result = 1;
		}	
	}
	return result;
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

/*----------------------------
Einzahlung
------------------------------*/
void Einzahlung(double Betrag, int KundeID){
	kunden[KundeID].Guthaben += Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro eingezahlt\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
Auszahlung
------------------------------*/
void Auszahlung(double Betrag, int KundeID){
	double tmp_Guthaben = kunden[KundeID].Guthaben;
	//Verhindert, dass Konto �berzogen werden kann
	if (tmp_Guthaben - Betrag < 0)
	{
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ausgezahlt werden,\nda sonst ihr Konto ueberzogen wird.\n", Betrag);
		printf("----------------------------\n\n");
		return;
	}
	kunden[KundeID].Guthaben -= Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro abgehoben\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
�berweisung
------------------------------*/
void Ueberweisung(double Betrag, int KundeID, int zu_Kontonummer) {
	int Kunde2;
	double tmp_Guthaben = kunden[KundeID].Guthaben;
	//Verhindert, dass Konto �berzogen werden kann
	if (tmp_Guthaben - Betrag < 0)
	{
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ueberwiesen werden,\nda sonst ihr Konto ueberzogen wird.\nSie koennen maximal %lf Euro Ueberweisen!\n", Betrag, kunden[KundeID].Guthaben);
		printf("----------------------------\n\n");
		return;
	}
	if (Suche(kunden, zu_Kontonummer, &Kunde2) == 1)
	{
		kunden[KundeID].Guthaben -= Betrag; //Den eigenen Kontostand minimieren
		kunden[Kunde2].Guthaben += Betrag; //Den Betrag dem anderen Konto gut schreiben
		printf("\n\n----------------------------\n");
		printf("Sie haben erfolgreich %.2lf Euro\nan das Konto %d ueberwiesen\n", Betrag, zu_Kontonummer);
		printf("----------------------------\n\n");
	}
	else
	{
		printf("\n\n----------------------------\n");
		printf("Die Kontonummer: %d konnte nicht gefunden werden!\n", zu_Kontonummer);
		printf("----------------------------\n\n");
	}
	
}



int main(void) {
	int SIDKunde; //Aktuelle SessionID eines Kunden
	
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
			if (KundeID <= MAXKunde)
				Kunde_anlegen(KundeID++, kunden); //Laufindex wird immer um 1 erh�ht
			else
				Status("Sie koennen nicht mehr Kunden anlegen!");
			break; //Wichtig, da sonst weiter abgearbeitet wird
	
		case 2:	//Anmelden
		{ //Klammern, weil in Switch Anweisungen keine Variaben am Anfang deklariert werden d�rfen!!
			if (isLogged == 1)
			{
				Status("Sie sind bereits angemeldet.");
				break;
			}
			//Tempor�re Variaben f�r Kontonummer und PIN anlegen
			int tmp_Kontonummer, tmp_PIN;
			//Z�hler f�r PIN-Versuche initialisieren
			int zaehler = 0;

			printf("Bitte geben Sie ihre Kontonummer ein:\n");
			scanf_s("%d", &tmp_Kontonummer);
			/*printf("Bitte geben Sie die dazugehoerige Pin ein:\n");
			scanf_s("%d", &tmp_PIN);*/
			
			if (Suche(kunden, tmp_Kontonummer, &SIDKunde) == 1)
			{
				//Abfrage, ob blockiert
				if (kunden[SIDKunde].isBlocked == 1)
				{
					printf("\n\n----------------------------\n");
					printf("Die Kontonummer %d ist blockiert.\nSie koennen sich nicht mehr anmelden!\n", kunden[SIDKunde].Kontonummer);
					printf("----------------------------\n");
					break;
				}
				//abfrage nach PIN
				printf("Bitte geben Sie die dazugehoerige Pin ein:\n");
				while (zaehler <= 2)
				{
					scanf_s("%d", &tmp_PIN);

					if (Pruefen(kunden[SIDKunde].Kontonummer, tmp_PIN) == 1) //kunden[SIDKunde].PIN) == 1)
					{
						Status("Sie haben sich erfolgreich angemeldet!");
						isLogged = 1;
						break;
					}
					else
					{
						zaehler += 1; //Pin Eingabem�glichkeit wird um eins hoch gesetzt
						//Pr�fen, ob 3x hintereinander die falsche PIN eingegeben wurde!
						if (zaehler == 3)
						{
							Status("Sie haben 3x hintereinander\ndie falsche PIN eingegeben!\nSie sind nun blockiert!");
							kunden[SIDKunde].isBlocked = 1; //Kunde wird hiermit blockiert
						}
					}
					// <3, weil bis 2 gez�hlt wird
					if (zaehler < 3) printf("Bitte wiederholen (%d. Versuch)", zaehler + 1);
				}
			}				
			else
			{
				printf("\n\n----------------------------\n");
				printf("Der Kunde mit der Kontonummer %d \nkonnte nicht gefunden werden!\n", tmp_Kontonummer);
				printf("----------------------------\n");
			}

			break;
		}

		case 3:	//Einzahlung
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			//Variable muss unbedingt vorher initialisiert werden durch login!
			//kunden[SIDKunde].Guthaben += 300;
			Status("Einzahlung");
			double tmp_Einzahlung;
			while (1) {
				printf("Bitte geben Sie den Betrag ein, welcher eingezahlt werden soll:\n(Sie koennen max. 5000 Euro Einzahlen.)\n");
				scanf_s("%lf", &tmp_Einzahlung); while (getchar() != '\n');
				if (tmp_Einzahlung > 0 && tmp_Einzahlung <= 5000) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			Einzahlung(tmp_Einzahlung, SIDKunde);
			
			break;
		case 4:	 //Auszahlung
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			Status("Auszahlung");
			double tmp_Auszahlung = 0.0;
			printf("Bitte geben Sie den Betrag ein, welcher ausgezahlt werden soll:\n(Es koennen max. %.2lf Euro ausgezahlt werden)\n", kunden[SIDKunde].Guthaben);
			while (1) {
				scanf_s("%lf", &tmp_Auszahlung); while (getchar() != '\n');
				if (tmp_Auszahlung > 0 && tmp_Auszahlung <= 1000) break;
				else if (tmp_Auszahlung <= 0) printf("Bitte geben Sie mehr als 0 Euro ein!\n");
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			Auszahlung(tmp_Auszahlung, SIDKunde);

			break;
		case 5: //Ueberweisung
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			Status("Ueberweisung");
			int tmp_zuKontonummer;
			printf("Kontonummer:");
			while (1) {
				scanf_s("%d", &tmp_zuKontonummer); while (getchar() != '\n');
				if (tmp_zuKontonummer >= 1000 && tmp_zuKontonummer <= 9999) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			double tmp_Ueberweisung = 0.0;
			printf("Betrag:"); //\n(Es koennen max. %.2lf Euro ueberwiesen werden)\n", kunden[SIDKunde].Guthaben);
			while (1) {
				scanf_s("%lf", &tmp_Ueberweisung); while (getchar() != '\n');
				if (tmp_Ueberweisung > 0 && tmp_Ueberweisung <= 1000) break;
				else if (tmp_Ueberweisung <= 0) printf("Bitte geben Sie mehr als 0 Euro ein!\n");
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			Ueberweisung(tmp_Ueberweisung, SIDKunde, tmp_zuKontonummer);
			break;
	
		case 6:	 //Kontostand
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
	
			break;
		case 7:	 //4-stellige Pin aendern
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			int tmp_oldPIN, tmp_newPIN;
			//Alte PIN einlesen
			printf("Bitte geben Sie ihre aktuelle PIN ein:\n");
			while (1) {
				scanf_s("%d", &tmp_oldPIN); while (getchar() != '\n');
				if (tmp_oldPIN >= 1000 && tmp_oldPIN <= 9999) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}
			//neue PIN einlesen
			printf("Bitte geben Sie eine neue 4-stellige PIN ein:\n");
			while (1) {
				scanf_s("%d", &tmp_newPIN); while (getchar() != '\n');
				if (tmp_newPIN >= 1000 && tmp_newPIN <= 9999) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			//Pr�fen der PIN und der KONTONUMMER AUSLAGERN!!!
			if (kunden[SIDKunde].PIN == tmp_oldPIN)
			{
				kunden[SIDKunde].PIN = tmp_newPIN;
				printf("\n\n----------------------------\n");
				printf("Ihre PIN wurde erfolgreich auf %d geaendert.\n", tmp_newPIN);
				printf("----------------------------\n\n");

			}
			else
			{
				Status("Sie haben eine falsche PIN eingegeben");
			}

			break;
		case 8: //Kundendaten anzeigen
			if (!isLogged)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}

			printf("\n\n----------------------------\n");
			printf("Kontonummer...: %d\n", kunden[SIDKunde].Kontonummer);
			printf("Guthaben......: %.2lf Euro\n", kunden[SIDKunde].Guthaben);
			printf("Pin...........: %d\n", kunden[SIDKunde].PIN);
			printf("geblockt......: %d\n", kunden[SIDKunde].isBlocked);
			printf("----------------------------\n");
	
			break;
		case 9:	 //Abmelden
			if (isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			else
			{
				isLogged = 0; //abmelden
				Status("Sie haben sich erfolgreich abgemeldet.");
			}
			
			break;
		case 10: return 0; //Beenden
		default:
			Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");
	
		}
	} while (1); // (auswahl < 10); //Ende der Schleife bei Eingabe der Zahl 10


	return 0;


}


//*************************************
/*

for (int i = 0; i <= MAXKunde; i++)
{
	printf("\n\n----------------------------\n");
	printf("Kontonummer...: %d\n", kunden[i].Kontonummer);
	printf("Guthaben......: %.2lf Euro\n", kunden[i].Guthaben);
	printf("Pin...........: %d\n", kunden[i].PIN);
	printf("----------------------------\n");
}


printf("\n\n----------------------------\n");
printf("Erfolgreich!\nKunde: %d\n", SKunde.Kontonummer);
printf("----------------------------\n");

*/