/*----------------------------
APL Programmierung 1, Teil 1
by Richard Kerber
17.11.2014
------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //boolesche Datentypen
//#pragma warning(disable:4996) //unterdrückt Fehler bei scanf_s
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
	int isBlocked;
} kunden[MAXKunde]; //Max 20 Kunden können angelegt werden


/*----------------------------
Formatierter Ausgabetext
------------------------------*/
void Status(char *text) {
	printf("\n-------------------------------\n");
	printf("%s\n", text);
	printf("-------------------------------\n\n");
}

/*----------------------------
Funktionen
------------------------------*/
int GetRandKontonummer(int KundeID) {
	int min = 1000, max = 9999;
	srand(KundeID); //Rand wird hier neu initialisiert
	return (rand() % (max - min + 1)) + min;
}

int GetRandPIN(int KundeID) {
	int min = 1000, max = 9999;
	return (rand() % (max - min + 1)) + min;
}

/*----------------------------
Suche nach Kunde mit gegebender Kontonummer
------------------------------*/
int Suche(struct kunde suche[], int Kontonummer, int *KundeID) {  //struct kunde *SKunde) {
	//Achtung: Hier bei der Suche darf kein else mit return 0 rein, da sonst nur erster Wert überprüft wird!!!
	int result = 0;
	int i;
	for (i = 0; i <= MAXKunde; i++) {
		if (suche[i].Kontonummer == Kontonummer) {
			*KundeID = i;
			result = 1;
			break;
		}
	}
	return result;
}

/*----------------------------
Prüfen der Kontonummer & PIN
------------------------------*/
int Pruefen(int Kontonummer, int PIN) {
	int result = 0;
	int i;
	for (i = 0; i <= MAXKunde; i++) {
		if ((kunden[i].Kontonummer == Kontonummer) && (kunden[i].PIN == PIN)) {
			result = 1;
		}
	}
	return result;
}

/*----------------------------
Einen nuene Kunden anlegen
------------------------------*/
void Kunde_anlegen(int KundeID, struct kunde neu[]) {
	if (KundeID < MAXKunde) {
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
	else Status("Sie koennen nicht mehr Kunden anlegen!");
}

/*----------------------------
Einzahlung
------------------------------*/
void Einzahlung(double Betrag, int KundeID) {
	kunden[KundeID].Guthaben += Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro eingezahlt.\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
Auszahlung
------------------------------*/
void Auszahlung(double Betrag, int KundeID) {
	double tmp_Guthaben = kunden[KundeID].Guthaben;
	//Verhindert, dass Konto überzogen werden kann
	if (tmp_Guthaben - Betrag < 0) {
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ausgezahlt werden,\nda sonst ihr Konto ueberzogen wird!\n", Betrag);
		printf("----------------------------\n\n");
		return;
	}
	kunden[KundeID].Guthaben -= Betrag;
	printf("\n\n----------------------------\n");
	printf("Sie haben erfolgreich %.2lf Euro abgehoben.\n", Betrag);
	printf("----------------------------\n\n");

}

/*----------------------------
Überweisung
------------------------------*/
void Ueberweisung(double Betrag, int KundeID, int zu_Kontonummer) {
	int Kunde2;
	double tmp_Guthaben = kunden[KundeID].Guthaben;
	//Verhindert, dass Konto überzogen werden kann
	if (tmp_Guthaben - Betrag < 0) {
		printf("\n\n----------------------------\n");
		printf("Der Betrag von %.2lf Euro kann nicht ueberwiesen werden,\nda sonst ihr Konto ueberzogen wird.\nSie koennen maximal %lf Euro Ueberweisen!\n", Betrag, kunden[KundeID].Guthaben);
		printf("----------------------------\n\n");
		return;
	}
	if (Suche(kunden, zu_Kontonummer, &Kunde2) == 1) {
		kunden[KundeID].Guthaben -= Betrag; //Den eigenen Kontostand minimieren
		kunden[Kunde2].Guthaben += Betrag; //Den Betrag dem anderen Konto gut schreiben
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

/*----------------------------
Alle Kunden anzeigen
------------------------------*/
void Ausgabe(struct kunde all[]) {
	if (all[1].Kontonummer == 0) {
		Status("Es sind noch keine Kunden angelegt!");
		return;
	}
	else {
		int i;
		for (i = 0; i < MAXKunde; i++) {

			printf("\n\n----------------------------\n");
			//printf("KundenID......: %d\n", i + 1);
			printf("Kontonummer...: %d\n", all[i].Kontonummer);
			printf("Guthaben......: %.2lf Euro\n", all[i].Guthaben);
			printf("Pin...........: %d\n", all[i].PIN);
			printf("Blockiert.....: %d\n", all[i].isBlocked);
			printf("----------------------------\n");
		}
	}
}

/*----------------------------
DB speichern
------------------------------*/
int saveDB(struct kunde k[]) {
	FILE *output;
	errno_t err;
	err = fopen_s(&output, "KundeDB.txt", "w"); // open the file to write
	if (err == 1) return 0;

	int i;
	for (i = 0; i < MAXKunde; i++) {
		fprintf(output, "%d %lf %d %d\n", k[i].Kontonummer, k[i].Guthaben, k[i].PIN, k[i].isBlocked);
	}
	fclose(output); // close
	return 1;
}

/*----------------------------
DB Laden
------------------------------*/
int readDB(struct kunde k[]) {
	FILE *input;
	errno_t err;
	err = fopen_s(&input, "KundeDB.txt", "r"); // open the file to write
	if (err == 1) return 0;

	int i;
	for (i = 0; i < MAXKunde; i++) {
		fscanf_s(input, "%d %lf %d %d", &k[i].Kontonummer, &k[i].Guthaben, &k[i].PIN, &k[i].isBlocked);
		//printf("%d %lf %d %d\n", k[i].Kontonummer, k[i].Guthaben, k[i].PIN, k[i].isBlocked);
	}
	fclose(input); // close
	KundeID = 30;
	return 1;
}

int main(void) {
	int SIDKunde; //Aktuelle SessionID eines Kunden

	//KundenDB laden
	if (readDB(kunden) == 1) Status("DB geladen");
	else Status("Die Datenbank konnte nicht gelesen werden!");

	int auswahl;
	/*Status("Das interaktive Banksystem\nby Richard Kerber");
	printf("Bitte waehlen Sie eine Option aus dem Menue,\nindem Sie die jeweilige Taste druecken:\n\n");*/

	while (1) { //1.Menu
			printf("\n");
			printf("1: Einen neuen Kunden anlegen\n");
			printf("2: Anmelden\n");
			printf("3: Beenden");

			printf("\nIhre Wahl:\n");
			scanf_s("%d", &auswahl);

			switch (auswahl) {
			case 1:	//Einen neuen Kunden anlegen
				Kunde_anlegen(KundeID++, kunden); //Laufindex wird immer um 1 erhöht
				break; //Wichtig, da sonst weiter abgearbeitet wird

			case 2:	//Anmelden
				//Klammern, weil in Switch Anweisungen keine Variaben am Anfang deklariert werden dürfen!!
				if (isLogged == 1) {
					Status("Sie sind bereits angemeldet.");
					break;
				}
				Status("Anmeldung");

				//Temporäre Variaben für Kontonummer und PIN anlegen
				int tmp_Kontonummer, tmp_PIN;
				//Zähler für PIN-Versuche initialisieren
				int zaehler = 0;

				while (1) {
					printf("Kontonummer: ");
					scanf_s("%d", &tmp_Kontonummer); //tmp_Kontonummer mit Benutzereingabe füllen
					while (getchar() != '\n'); //Auf Eingabe warten
					if (tmp_Kontonummer >= 1000 && tmp_Kontonummer <= 9999) break; //Wenn Kontonummer zwischen 1000 und 9999 liegt, dann weiter
					else printf("Bitte geben Sie Ihre 4-stellige Kontonummer an!\n");
				}

				if (Suche(kunden, tmp_Kontonummer, &SIDKunde) == 1) {
					//Abfrage, ob blockiert
					if (kunden[SIDKunde].isBlocked == 1) {
						printf("\n\n----------------------------\n");
						printf("Die Kontonummer %d ist blockiert.\nBitte wenden Sie sich an den naechsten\nfreien Service-Mitarbeiter.\n", kunden[SIDKunde].Kontonummer);
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

						if (Pruefen(kunden[SIDKunde].Kontonummer, tmp_PIN) == 1) { //kunden[SIDKunde].PIN) == 1)
							Status("Sie haben sich erfolgreich angemeldet!");
							isLogged = 1;
							break;
						}
						else {
							zaehler += 1; //Pin Eingabemöglichkeit wird um eins hoch gesetzt
							//Prüfen, ob 3x hintereinander die falsche PIN eingegeben wurde!
							if (zaehler == 3) {
								Status("Sie haben 3x hintereinander\ndie falsche PIN eingegeben!\nSie sind nun blockiert!");
								kunden[SIDKunde].isBlocked = 1; //Kunde wird hiermit blockiert
								saveDB(kunden); //Daten speichern
								break;
							}
						}
						// <3, weil bis 2 gezählt wird
						if (zaehler < 3) printf("Bitte wiederholen (%d. Versuch)\n", zaehler + 1);
					}
				}
				else Status("Kontonummer nicht gefunden!");
				break;
			case 3: return 0; //Beenden
			/*Sonstiges*/
			case 44:
				Ausgabe(kunden);
				break;
			default:
				Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");
			} //1.Menu ENDE
		
	

		//Wenn eingeloggt
		if (isLogged == 1)
		{
			while (1) { //2.Menue
				if (isLogged == 0) break; //Wenn nicht eingeloggt, dann zuruck zum 1.Menu
				printf("\n");
				printf("1: Einzahlung\n");
				printf("2: Auszahlung\n");
				printf("3: Ueberweisung\n");
				printf("4: Kontostand\n");
				printf("5: 4-stellige Pin aendern\n");
				printf("6: Kundendaten anzeigen\n");
				printf("7: Abmelden\n");
				printf("8: Beenden\n");

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
						if (tmp_Einzahlung > 0.0 && tmp_Einzahlung <= 5000.0) break;
						else printf("falsche Eingabe! Bitte wiederholen\n");
					}

					Einzahlung(tmp_Einzahlung, SIDKunde);
					saveDB(kunden); //Daten speichern
					break;
				case 2:	 //Auszahlung
					Status("Auszahlung");
					double tmp_Auszahlung = 0.0;
					printf("Bitte geben Sie den Betrag ein, welcher ausgezahlt werden soll:\n(Es koennen max. %.2lf Euro ausgezahlt werden)\n", kunden[SIDKunde].Guthaben);
					while (1) {
						printf("Betrag:");
						scanf_s("%lf", &tmp_Auszahlung);
						while (getchar() != '\n');
						if (tmp_Auszahlung > 0.0 && tmp_Auszahlung <= 1000.0) break;
						else if (tmp_Auszahlung <= 0) printf("Bitte geben Sie mehr als 0 Euro ein!\n");
						else printf("falsche Eingabe! Bitte wiederholen\n");
					}

					Auszahlung(tmp_Auszahlung, SIDKunde);
					saveDB(kunden); //Daten speichern

					break;
				case 3: //Ueberweisung
					Status("Ueberweisung");
					int tmp_zuKontonummer;
					printf("Kontonummer:");
					while (1) {
						scanf_s("%d", &tmp_zuKontonummer);
						while (getchar() != '\n');
						if (tmp_zuKontonummer >= 1000 && tmp_zuKontonummer <= 9999 && tmp_zuKontonummer != kunden[SIDKunde].Kontonummer) break;
						/*else if (tmp_zuKontonummer == kunden[SIDKunde].Kontonummer) {
						Status("Sie koennen nicht an Ihr eigenes Konto ueberweisen!");
						break;
						} */
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

					Ueberweisung(tmp_Ueberweisung, SIDKunde, tmp_zuKontonummer);
					saveDB(kunden); //Daten speichern
					break;

				case 4:	 //Kontostand
					printf("\n\n----------------------------\n");
					printf("Ihr Guthaben betraegt: %.2lf Euro\n", kunden[SIDKunde].Guthaben);
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
						else printf("falsche Eingabe! Bitte wiederholen\n");
					}

					//Prüfen der PIN und der KONTONUMMER AUSLAGERN!!!
					if (kunden[SIDKunde].PIN == tmp_oldPIN) {
						kunden[SIDKunde].PIN = tmp_newPIN;
						saveDB(kunden); //neue PIN speichern!
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
					printf("Kontonummer...: %d\n", kunden[SIDKunde].Kontonummer);
					printf("Guthaben......: %.2lf Euro\n", kunden[SIDKunde].Guthaben);
					printf("Pin...........: %d\n", kunden[SIDKunde].PIN);
					printf("geblockt......: %d\n", kunden[SIDKunde].isBlocked);
					printf("----------------------------\n");

					break;
				case 7:	 //Abmelden
					isLogged = 0; //abmelden
					Status("Sie haben sich erfolgreich abgemeldet.");
					//printf("%d", isLogged);
					break;
				case 8:
					return 0; //Beenden
				default:
					Status("Ihrer Eingabe konnte kein Menuepunkt zugeordnet werden!\nBitte versuchen Sie es erneut.");
				}

			} //while (1); //2.Menu ENDE
		} //IF ENDE
	} //while (1); //1.Menu ENDE

	//getch();
	return 0;
}