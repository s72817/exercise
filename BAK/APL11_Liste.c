#include <stdio.h>
#include <time.h>
#define MaxKunde 100
#define MaxHash 10

/*
int GetRandPIN(int KundeID);

void kunde_init(kunde all[], int counter);
bool kunde_suchen(kunde all[], int *SID, int Kontonummer);
bool kunde_pruefen(kunde all[], int SID, int Kontonummer, int PIN);
void Einzahlung(kunde all[], int SID, double Betrag);
void Auszahlung(kunde all[], int SID, double Betrag);
void Ueberweisung(kunde all[], int SID, double Betrag, int zu_Kontonummer);

void Status(char *text);
void menu1();
void menu2();
*/


/**********************************************************************
***********************************************************************/

//Boolsche Vriable verfügbar machen
typedef int bool;
enum { false, true };

int GetRandPIN(int KundeID) {
	int min = 1000, max = 9999;
	return (rand() % (max - min + 1)) + min;
}

/**********************************************************************
***********************************************************************/

//Klasse Kunde

typedef struct {
	int ID;
	int Kontonummer;
	double Guthaben;
	unsigned int PIN;
	bool isblocked;

	struct kunde *next;
}kunde;


//Add Kunde to Liste
void kunde_init(kunde **all, int counter) {
	//kunde *pointer;
	////Hash Wert generienen
	//int hash_address = hash_function(1000 + counter); //verbesserungswürdig
	//



	kunde *top = (kunde*)malloc(sizeof(kunde)); //ein neuer Kunde wird an den Anfang der Liste gesetzt
	if (!top){
		printf("stack_push: out of memory\n");
		return;
	}
	top->ID = counter;
	top->Kontonummer = 1000 + counter;
	top->Guthaben = 0.0;
	top->PIN = GetRandPIN(counter);
	top->isblocked = 0;
	top->next = *all;
	*all = top;

	/*printf("\n----------------------------\n");
	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
	printf("KundenID......: %d\n", counter);
	printf("Kontonummer...: %d\n", top->Kontonummer);
	printf("Guthaben......: %.2lf Euro\n", top->Guthaben);
	printf("Pin...........: %d\n", top->PIN);
	printf("----------------------------\n");*/
}

/*----------------------------
Suche nach Kunde mit gegebender Kontonummer
------------------------------*/
bool kunde_suchen(kunde *s, int Kontonummer) {
	int result = 0;
	while (s != NULL) {
		if (s->Kontonummer == Kontonummer)
			result = 1;
		s = s->next;
	}
	return result;
}


/*----------------------------
Prüfen der Kontonummer & PIN
------------------------------*/
bool kunde_pruefen(kunde all[], int SID, int Kontonummer, int PIN) {
	return ((all[SID].Kontonummer == Kontonummer) && (all[SID].PIN == PIN));
}

/*----------------------------
Einzahlung
------------------------------*/
void Einzahlung(kunde all[], int SID, double Betrag) {
	all[SID].Guthaben += Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro eingezahlt.\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
Auszahlung
------------------------------*/
void Auszahlung(kunde all[], int SID, double Betrag) {
	double tmp_Guthaben = all[SID].Guthaben;
	//Verhindert, dass Konto überzogen werden kann
	if ((tmp_Guthaben - Betrag) < 0) {
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ausgezahlt werden,\nda sonst ihr Konto ueberzogen wird!\n", Betrag);
		printf("----------------------------\n\n");
		return;
	}
	all[SID].Guthaben -= Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro abgehoben.\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
Überweisung
------------------------------*/
void Ueberweisung(kunde all[], int SID, double Betrag, int zu_Kontonummer) {
	int Kunde2;
	double tmp_Guthaben = all[SID].Guthaben;
	//Verhindert, dass Konto überzogen werden kann
	if (tmp_Guthaben - Betrag < 0) {
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ueberwiesen werden,\nda sonst ihr Konto ueberzogen wird.\nSie koennen maximal %lf Euro Ueberweisen!\n", Betrag, all[SID].Guthaben);
		printf("----------------------------\n\n");
		return;
	}
	if (kunde_suchen(all, &Kunde2, zu_Kontonummer) == 1) {
		all[SID].Guthaben -= Betrag; //Den eigenen Kontostand minimieren
		all[Kunde2].Guthaben += Betrag; //Den Betrag dem anderen Konto gut schreiben
		printf("\n\n----------------------------\n");
		printf("Sie haben erfolgreich %.2lf Euro\nan das Konto %d ueberwiesen\n", Betrag, zu_Kontonummer);
		printf("----------------------------\n\n");
	}
	else {
		printf("\n\n----------------------------\n");
		printf("Die Kontonummer: %d konnte nicht gefunden werden!\n", zu_Kontonummer);
		printf("----------------------------\n\n");
	}
}

/**********************************************************************
***********************************************************************/

/*----------------------------
Formatierter Ausgabetext
------------------------------*/
void Status(char *text) {
	printf("\n-------------------------------\n");
	printf("%s\n", text);
	printf("-------------------------------\n\n");
}

/**********************************************************************
***********************************************************************/

/*----------------------------
1.Menu
------------------------------*/

void menu1() {
	printf("1: Einen neuen Kunden anlegen\n");
	printf("2: Anmelden\n");
	printf("3: Beenden");
}

/*----------------------------
2.Menu
------------------------------*/

void menu2() {
	printf("1: Einzahlung\n");
	printf("2: Auszahlung\n");
	printf("3: Ueberweisung\n");
	printf("4: Kontostand\n");
	printf("5: 4-stellige Pin aendern\n");
	printf("6: Kundendaten anzeigen\n");
	printf("7: Abmelden\n");
	printf("8: Beenden\n");
}

/**********************************************************************
***********************************************************************/

/*----------------------------
Alle Kunden anzeigen
------------------------------*/
void Ausgabe(kunde *all) {
	if (all == NULL)//Wenn Liste NULL ist
	{
		Status("Kein Kunde angelegt!"); 
		return;
	}
	else {
		while (all != NULL)
		{
			printf("\n\n----------------------------\n");
			printf("KundenID......: %d\n", all->ID);
			printf("Kontonummer...: %d\n", all->Kontonummer);
			printf("Guthaben......: %.2lf Euro\n", all->Guthaben);
			printf("Pin...........: %d\n", all->PIN);
			printf("Blockiert.....: %d\n", all->isblocked);
			printf("----------------------------\n");
			all = all->next;
		}
	}
}

/**********************************************************************
***********************************************************************/

/*----------------------------
DB speichern
------------------------------*/
int saveDB(kunde all[]) {
	FILE *output;
	errno_t err;
	err = fopen_s(&output, "KundeDB.txt", "w"); // open the file to write
	if (err == 1) return 0;

	int i;
	for (i = 0; i < MaxKunde; i++) {
		fprintf(output, "%d %lf %d %d\n", all[i].Kontonummer, all[i].Guthaben, all[i].PIN, all[i].isblocked);
	}
	fclose(output); // close
	return 1;
}

/*----------------------------
DB Laden
------------------------------*/
int readDB(kunde all[], int *KundeID) {
	FILE *input;
	errno_t err;
	err = fopen_s(&input, "KundeDB.txt", "r"); // open the file to write
	if (err == 1) return 0;

	int i;
	for (i = 0; i < MaxKunde; i++) {
		fscanf_s(input, "%d %lf %d %d", &all[i].Kontonummer, &all[i].Guthaben, &all[i].PIN, &all[i].isblocked);
		//printf("%d %lf %d %d\n", k[i].Kontonummer, k[i].Guthaben, k[i].PIN, k[i].isBlocked);
	}
	fclose(input); // close
	*KundeID = MaxKunde;
	return 1;
}

/**********************************************************************
***********************************************************************/
int hash_function(int Kontonummer) {
	/*key = key mod m
	Für m sollten Sie idealerweise eine Primzahl so nahe wie möglich am höchsten Index wählen.*/
	return Kontonummer % 7;
}

/**********************************************************************
***********************************************************************/


int main(void) {
	//Initialsierung
	kunde *k = NULL; //Liste
	kunde *hash_table[MaxHash]; //Hash-Tabelle


	bool islogged = false;
	int counter = 0;
	int SID; //Aktuelle SessionID eines Kunden
	int auswahl;

	//Datenbank laden
	//readDB(k, &counter);

	/*********************************************************************/
	while (1) { //1.Menu
		menu1(); //Ausgabe Menü1

		printf("\nIhre Wahl:\n");
		scanf_s("%d", &auswahl);

		switch (auswahl) {
		case 1:
			if (counter < MaxKunde)
				kunde_init(&k, counter++); //Kunde anlegen
			else
				Status("Es koennen keine weiteren Kunden angelegt werden!");
			break;
		case 2:
			Status("Anmeldung");

			//Temporäre Variablen für Kontonummer und PIN anlegen
			int tmp_Kontonummer, tmp_PIN;
			//Zähler für PIN-Versuche initialisieren
			int zaehler = 0;

			while (1) {
				printf("Kontonummer: ");
				scanf_s("%d", &tmp_Kontonummer); //tmp_Kontonummer mit Benutzereingabe füllen
				while (getchar() != '\n'); 
				if (tmp_Kontonummer >= 1000 && tmp_Kontonummer <= 9999) break; //Wenn Kontonummer zwischen 1000 und 9999 liegt, dann weiter
				else printf("Bitte geben Sie Ihre 4-stellige Kontonummer an!\n");
			}

			if (kunde_suchen(k, tmp_Kontonummer) == true) {
				SID = tmp_Kontonummer - 1000;
				//Abfrage, ob blockiert
				if (k[SID].isblocked == true) {
					printf("\n\n----------------------------\n");
					printf("Die Kontonummer %d ist blockiert.\nBitte wenden Sie sich an den naechsten\nfreien Service-Mitarbeiter.\n", k[SID].Kontonummer);
					printf("----------------------------\n");
					break;
				}

				while (1) { //zaehler <= 2
					//abfrage nach PIN
					while (1) {
						printf("PIN: ");
						scanf_s("%d", &tmp_PIN);
						while (getchar() != '\n');
						if (tmp_PIN >= 1000 && tmp_PIN <= 9999) break;
						else printf("Bitte geben Sie Ihre 4-stellige PIN an!\n");
					}
					if (kunde_pruefen(k, SID, tmp_Kontonummer, tmp_PIN) == true) { //kunden[SIDKunde].PIN) == 1)
						Status("Sie haben sich erfolgreich angemeldet!");
						islogged = 1;
						break;
					}
					else {
						zaehler += 1; //Pin Eingabemöglichkeit wird um eins hoch gesetzt
						//Prüfen, ob 3x hintereinander die falsche PIN eingegeben wurde!
						if (zaehler == 3) {
							Status("Sie haben 3x hintereinander\ndie falsche PIN eingegeben!\nSie sind nun blockiert!");
							k[SID].isblocked = 1; //Kunde wird hiermit blockiert
							//saveDB(k); //Daten speichern
							break;
						}
					}
					// <3, weil bis 2 gezählt wird
					if (zaehler < 3) printf("Bitte wiederholen (%d. Versuch)\n", zaehler + 1);
				}
			}
			else Status("Kontonummer nicht gefunden!");
			break;
		case 44:
		{
			//********************
			clock_t prgstart, prgende; //Definierung der Variablen
			prgstart = clock(); //CPU-Zeit zu Beginn des Programmes
			//********************
			for (int i = 0; i < MaxKunde; i++)
				kunde_init(&k, counter++);
			//********************
			prgende = clock();//CPU-Zeit am Ende des Programmes
			printf("\nLaufzeit %.2f Sekunden\n", (float)(prgende - prgstart) / CLOCKS_PER_SEC);
			//********************
			break;
		}
		case 45:
			Ausgabe(k);
			break;
		case 46:
			for (int i = 1000; i < 1500; i++)
				printf("Hash aus %d: %d\n", i, hash_function(i));
			break;
		case 55: 
			//saveDB(k);
			Status("Erfolgreich geladen!");
			break;
		case 56: 
			readDB(k, &counter);
			counter = MaxKunde; //counter auf Max setzen, da keine weiteren Kunden angelegt werden können
			Status("Erfolgreich gespeichert!");
			break;
		default:
			Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");
			break;
		}

		/*********************************************************************/
		while (1) { //2.Menu
			if (islogged == false) break; //Wichtig, da sonst nicht zurück
			menu2(); //Ausgabe Menü2

			printf("\nIhre Wahl:\n");
			scanf_s("%d", &auswahl);

			switch (auswahl) {

			case 1:	//Einzahlung

				//Variable muss unbedingt vorher initialisiert werden durch login!
				Status("Einzahlung");
				double tmp_Einzahlung;
				printf("Bitte geben Sie den Betrag ein, welcher eingezahlt werden soll:\n(Sie koennen max. 5000 Euro Einzahlen.)\n");
				while (1) {
					printf("Betrag: ");
					scanf_s("%lf", &tmp_Einzahlung);
					while (getchar() != '\n');
					if (tmp_Einzahlung > 0.00 && tmp_Einzahlung <= 5000.0) break;
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}

				Einzahlung(k, SID, tmp_Einzahlung );
				//saveDB(k); //Daten speichern
				break;

			case 2:	 //Auszahlung
				Status("Auszahlung");
				double tmp_Auszahlung = 0.0;
				printf("Bitte geben Sie den Betrag ein, welcher ausgezahlt werden soll:\n(Es koennen max. %.2lf Euro ausgezahlt werden)\n", k[SID].Guthaben);
				while (1) {
					printf("Betrag:");
					scanf_s("%lf", &tmp_Auszahlung);
					while (getchar() != '\n');
					if (tmp_Auszahlung > 0.0 && tmp_Auszahlung <= k[SID].Guthaben) break;
					else if (tmp_Auszahlung <= 0) printf("Bitte geben Sie mehr als 0 Euro ein!\n");
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}

				Auszahlung(k, SID, tmp_Auszahlung);
				//saveDB(k); //Daten speichern
				break;

			case 3: //Ueberweisung
				Status("Ueberweisung");
				int tmp_zuKontonummer = 0;
				while (1) {
					printf("Kontonummer:"); //!!!!!!
					scanf_s("%d", &tmp_zuKontonummer);
					while (getchar() != '\n');
					if (tmp_zuKontonummer >= 1000 && tmp_zuKontonummer <= 9999 && tmp_zuKontonummer != k[SID].Kontonummer) break; //Eingabe der eigenen Kontonummer kann schöner abgefangen werden
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}

				double tmp_Ueberweisung = 0.0;
				printf("Betrag:"); //\n(Es koennen max. %.2lf Euro ueberwiesen werden)\n", kunden[SIDKunde].Guthaben);
				while (1) {
					scanf_s("%lf", &tmp_Ueberweisung);
					while (getchar() != '\n');
					if (tmp_Ueberweisung > 0.0) break; //if (tmp_Ueberweisung > 0 && tmp_Ueberweisung <= 1000) break;
					else if (tmp_Ueberweisung <= 0) printf("Bitte geben Sie mehr als 0 Euro ein!\n");
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}

				Ueberweisung(k, SID, tmp_Ueberweisung, tmp_zuKontonummer);
				//saveDB(k); //Daten speichern
				break;

			case 4:	 //Kontostand
				printf("\n\n----------------------------\n");
				printf("Ihr Guthaben betraegt: %.2lf Euro\n", k[SID].Guthaben);
				printf("----------------------------\n");
				break;
			case 5:	 //4-stellige Pin aendern
				Status("4-stellige Pin aendern");
				int tmp_oldPIN, tmp_newPIN;
				//Alte PIN einlesen
				printf("Bitte geben Sie ihre aktuelle PIN ein:\n");
				while (1) {
					scanf_s("%d", &tmp_oldPIN);
					while (getchar() != '\n');
					if (tmp_oldPIN >= 1000 && tmp_oldPIN <= 9999) break;
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}
				//neue PIN einlesen
				printf("Bitte geben Sie eine neue 4-stellige PIN ein:\n");
				while (1) {
					scanf_s("%d", &tmp_newPIN);
					while (getchar() != '\n');
					if (tmp_newPIN >= 1000 && tmp_newPIN <= 9999) break;
					else if (tmp_newPIN < 1000) Status("Bitte geben Sie eine Pin groesser gleich 1000 an!");
					else printf("falsche Eingabe! Bitte wiederholen\n");
				}

				//Prüfen der PIN und der KONTONUMMER AUSLAGERN!!!
				if (k[SID].PIN == tmp_oldPIN) {
					k[SID].PIN = tmp_newPIN;
					//saveDB(kunden); //neue PIN speichern!
					printf("\n\n----------------------------\n");
					printf("Ihre PIN wurde erfolgreich auf %d geaendert.\n", tmp_newPIN);
					printf("----------------------------\n\n");

				}
				else {
					Status("Sie haben eine falsche PIN eingegeben!");
				}

				break;
			case 6: //Kundendaten anzeigen

				printf("\n\n----------------------------\n");
				printf("Kontonummer...: %d\n", k[SID].Kontonummer);
				printf("Guthaben......: %.2lf Euro\n", k[SID].Guthaben);
				printf("Pin...........: %d\n", k[SID].PIN);
				printf("geblockt......: %d\n", k[SID].isblocked);
				printf("----------------------------\n");

				break;
			case 7:	 //Abmelden
				islogged = 0; //abmelden
				Status("Sie haben sich erfolgreich abgemeldet.");
				//printf("%d", isLogged);
				break;
			case 8:
				return 0; //Beenden
			default:
				Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");
				break;
				
			}//switch ENDE
			//Status("ENDE");
			//saveDB(k); //"Global" speichern
		}//while ENDE
		//saveDB(k); //"Global" speichern
	}//while ENDE
	
	
}




////Add Kunde to Liste
//void kunde_init(kunde **all, int counter) {
//
//
//
//
//	kunde *top = (kunde*)malloc(sizeof(kunde)); //ein neuer Kunde wird an den Anfang der Liste gesetzt
//	if (!top){
//		printf("stack_push: out of memory\n");
//		return;
//	}
//	top->ID = counter;
//	top->Kontonummer = 1000 + counter;
//	top->Guthaben = 0.0;
//	top->PIN = GetRandPIN(counter);
//	top->isblocked = 0;
//	top->next = *all;
//	*all = top;
//
//	/*printf("\n----------------------------\n");
//	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
//	printf("KundenID......: %d\n", counter);
//	printf("Kontonummer...: %d\n", top->Kontonummer);
//	printf("Guthaben......: %.2lf Euro\n", top->Guthaben);
//	printf("Pin...........: %d\n", top->PIN);
//	printf("----------------------------\n");*/
//}