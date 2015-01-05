#include <stdio.h>
#include <math.h>

/*----------------------------
APL Programmierung 1, Teil 1
by Richard Kerber
17.11.2014
------------------------------*/

struct kunde {         /* deklariert den Strukturtyp kunde */
	int  Kontonummer;
	double Guthaben;
	int PIN;
	int isLogged;
	int isBlocked;
	//char History[];
};

//Initialisierung eines leeren Kunden 
struct kunde Kunde1 = { 0, 0.0, 0, 0, 0 };
struct kunde Kunde2 = { 3455, 9834.5, 6778, 0, 0 };
struct kunde Kunde3 = { 2233, 7623.23, 9933, 0, 0 };

/*----------------------------
Formatierter Ausgabetext
------------------------------*/
void Status(char *text) {
	printf("\n\n----------------------------\n");
	printf("%s\n", text);
	printf("----------------------------\n\n");
}



/*----------------------------
Prüfen von Kontonummer und dazugehöriger PIN
------------------------------*/
int Check_Data(int Kontonummer, int PIN) {
	if ((Kontonummer == Kunde1.Kontonummer) && (PIN == Kunde1.PIN)) return 1;
	else return 0;
}


/*----------------------------
Prüfen ob Kunde angemeldet
------------------------------*/
int isLogged() {
	if (Kunde1.isLogged == 1) return 1;
	else return 0;
}


/*----------------------------
Einen nuene Kunden anlegen
------------------------------*/
void Kunde_anlegen() {
	
	//Kunde mit Daten anlegen
	Kunde1.Kontonummer = 5664;
	Kunde1.Guthaben = 0.0;
	Kunde1.PIN = 3344;

	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
	printf("Kontonummer: %d\n", Kunde1.Kontonummer);
	printf("Guthaben = %.2lf Euro\n", Kunde1.Guthaben);
	printf("Pin: %d\n", Kunde1.PIN);
	printf("----------------------------\n");
}

/*----------------------------
Kunde anmelden
------------------------------*/
void Kunde_anmelden() {
	//Prüfen ob Kunde schon angemeldet ist
	if (Kunde1.isLogged == 1)
	{
		Status("Sie sind bereits angemeldet.");
		return;
	}
	//Zähler für PIN-Versuche initialisieren
	int zaehler = 0;

	//Temporäre Variaben für Kontonummer und PIN anlegen
	int tmp_Kontonummer, tmp_PIN;

	printf("Bitte geben Sie ihre Kontonummer ein:\n");
	scanf_s("%d", &tmp_Kontonummer);
	//Nach eingabe der Kontonummer prüfen, ob gesperrt
	if (tmp_Kontonummer == Kunde1.Kontonummer && Kunde1.isBlocked == 1)
	{
		Status("Sie sind blockiert und duerfen sich nicht mehr anmelden!");
		return;
	}
	//Wenn nicht blockiert, dann wird PIN abgefragt
	printf("Bitte geben Sie die dazugehoerige Pin ein:\n");
	//<=2, weil 0,1,2 = 3 Versuche insgesamt
	while (zaehler <= 2)
	{
		scanf_s("%d", &tmp_PIN);
		
		if (Check_Data(tmp_Kontonummer, tmp_PIN) == 1)//if ((tmp_Kontonummer == Kunde1.Kontonummer) && (tmp_PIN == Kunde1.PIN))
		{
			Status("Erfolgreich angemeldet!");
			Kunde1.isLogged = 1;
			break;
		}
		else zaehler += 1;
		// <3, weil bis 2 gezählt wird
		if (zaehler < 3) printf("Bitte wiederholen (%d. Versuch)", zaehler +1);
		
	}
	//Prüfen, ob 3x hintereinander die falsche PIN eingegeben wurde!
	if (zaehler == 3)
	{
		Status("Sie haben 3x hintereinander die falsche PIN eingegeben!\nSie sind nun blockiert!");
		Kunde1.isBlocked = 1; //Kunde wird hiermit blockiert
	}
}


/*----------------------------
Kunde abmelden
------------------------------*/
void Kunde_abmelden() {
	Kunde1.isLogged = 0;
	Status("Sie haben sich erfolgreich abgemeldet.");
}


/*----------------------------
Einzahlung
------------------------------*/
void Einzahlung(double Betrag){
	Kunde1.Guthaben += Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro eingezahlt\n", Betrag);
	printf("----------------------------\n\n");
	
}

/*----------------------------
Auszahlung
------------------------------*/
void Auszahlung(double Betrag){
	double tmp_Guthaben = Kunde1.Guthaben;
	if (tmp_Guthaben - Betrag < 0)
	{
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ausgezahlt werden,\nda sonst ihr Konto ueberzogen wird.\n", Betrag);
		printf("----------------------------\n\n");
		return;
	}
	Kunde1.Guthaben -= Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %lf Euro abgehoben\n", Betrag);
	printf("----------------------------\n\n");
	
}


void TEST(struct kunde *Test) {
	printf("%s\n", (*Test).Guthaben);
}


int main(void) {

	int menuezahl;

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
		scanf_s("%d", &menuezahl);

		switch (menuezahl)
		{
		case 1:	//Einen neuen Kunden anlegen
			Kunde_anlegen();
			break; //Wichtig, da sonst weiter abgearbeitet wird
		case 2:	//Anmelden
			Kunde_anmelden();
			break;
		case 3:	//Einzahlung
			if (Kunde1.isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			
			double tmp_Einzahlung;
			while (1) {
				printf("Bitte geben Sie den Betrag ein, welcher eingezahlt werden soll:\n");
				scanf_s("%lf", &tmp_Einzahlung); while (getchar() != '\n');
				if (tmp_Einzahlung >= 0 && tmp_Einzahlung <= 5000) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			Einzahlung(tmp_Einzahlung);

			break;
		case 4:	 //Auszahlung
			if (Kunde1.isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}

			double tmp_Auszahlung = 0.0;
			while (1) {
				printf("Bitte geben Sie den Betrag ein, welcher ausgezahlt werden soll:\n");
				scanf_s("%lf", &tmp_Auszahlung); while (getchar() != '\n');
				if (tmp_Auszahlung >= 0 && tmp_Auszahlung <= 1000) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}
			
			Auszahlung(tmp_Auszahlung);

			break;
		case 5:

			TEST(&Kunde1);

			break;

		case 6:	 //Kontostand
			if (Kunde1.isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}

			printf("\n\n----------------------------\n");
			printf("Ihr aktuelles Guthaben betraegt: %.2lf Euro\n", Kunde1.Guthaben);
			printf("----------------------------\n\n");
			
			break;
		case 7:	 //4-stellige Pin aendern
			if (Kunde1.isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}

			int tmp_oldPIN, tmp_newPIN;
			//Alte PIN einlesen
			while (1) {
				printf("Bitte geben Sie ihre aktuelle PIN ein:\n");
				scanf_s("%d", &tmp_oldPIN); while (getchar() != '\n');
				if (tmp_oldPIN >= 0 && tmp_oldPIN <= 9999) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}
			//neue PIN einlesen
			while (1) {
				printf("Bitte geben Sie eine neue 4-stellige PIN ein:\n");
				scanf_s("%d", &tmp_newPIN); while (getchar() != '\n');
				if (tmp_newPIN >= 0 && tmp_newPIN <= 9999) break;
				else printf("falsche Eingabe! Bitte wiederholen\n");
			}

			//Prüfen der PIN und der KONTONUMMER AUSLAGERN!!!
			if (Kunde1.PIN == tmp_oldPIN)
			{
				Kunde1.PIN = tmp_newPIN;
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
			if (Kunde1.isLogged == 0)
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			printf("\n\n----------------------------\n");
			printf("Kontonummer: %d\n", Kunde1.Kontonummer);
			printf("Guthaben: %.2lf\n", Kunde1.Guthaben);
			printf("PIN: %d\n", Kunde1.PIN);
			printf("Angemeldet: %d\n", Kunde1.isLogged);
			printf("Blockiert: %d\n", Kunde1.isBlocked);
			printf("----------------------------\n\n");

			break;
		case 9:	 //Abmelden
			if (Kunde1.isLogged == 0) //Kunde nicht angemeldet
			{
				Status("Sie muessen sich erst anmelden!");
				break;
			}
			else //Kunde angemeldet
			{
				Kunde_abmelden();
			}
			
			break;
		case 10: return 0; //Beenden
		default:  // bei falscher Eingabe
			Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");

		}

	} while (menuezahl != 10); //Ende der Schleife bei Eingabe der Zahl 8

	

	getch();
	return 0;
}





/*AUSLAGERUNG



Kontonummer = 5664;
Guthaben = 0;
PIN = 4516;


//int Kontonummer;
//double Guthaben;
//int PIN;
//int isKundeOnline = 0;

if (isLogged == 1) printf("geht");
else Status("Sie muessen sich erst anmelden!");

*/