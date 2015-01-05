#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxKunde 1000
#define MaxHash 10

typedef struct {
	int ID;
	int Kontonummer;
	double Guthaben;
	unsigned int PIN;
	int isblocked;

	struct kunde *next;
}kunde;


int hash_function(int Kontonummer) {
	//Für m sollten Sie idealerweise eine Primzahl so nahe wie möglich am höchsten Index wählen.*/
	return Kontonummer % 7;
}

kunde *hashtabelle[MaxHash];

//Add Kunde to Liste
kunde *add(kunde *pointer, int counter) {
	//kunde *pointer;
	//Hash Wert generienen
	int hashaddress = hash_function(1000 + counter); //verbesserungswürdig
	/* Zeiger auf errechnete Tabellenadresse durch hash_funktion */
	pointer = hashtabelle[hashaddress];

	/* Speicher für neues Element allozieren */
	pointer = malloc(sizeof(kunde));
	if (pointer == NULL) {
		printf("Kein Speicher für neues Element vorhanden\n");
		return NULL;
	}
	//Struct befüllen
	pointer->ID = counter;
	pointer->ID = counter;
	pointer->Kontonummer = 1000 + counter;
	pointer->Guthaben = 0.0;
	pointer->PIN = counter *5 +1;
	pointer->isblocked = 0;
	//Zeiger vom nächsten Element bekommt errechnete Hashadresse
	pointer->next = hashtabelle[hashaddress];
	//Wert zum Hash(Array) hinzufüen
	hashtabelle[hashaddress] = pointer;
	

	printf("\n----------------------------\n");
	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
	printf("KundenID......: %d\n", pointer->ID);
	printf("Kontonummer...: %d\n", pointer->Kontonummer);
	printf("Guthaben......: %.2lf Euro\n", pointer->Guthaben);
	printf("Pin...........: %d\n", pointer->PIN);
	printf("----------------------------\n"); 

	return pointer;
}

kunde *suche(kunde *pointer, int Kontonummer) {
	//kunde *pointer = NULL;//int result = 0;
	int hashaddress = hash_function(Kontonummer);
	pointer = hashtabelle[hashaddress];
	while (pointer != NULL) {
		if (pointer->Kontonummer == Kontonummer)
		{
			pointer = hashtabelle[hashaddress];
			break;
		}
		pointer = pointer->next;
	}
	return pointer;
}


void kunde_output_all(kunde *pointer) {
	for (int i = 0; i < MaxHash; i++)
	{
		pointer = hashtabelle[i];
		while (pointer != NULL) {
			printf("Kontonummer: %d\nHash: %d\n", pointer->Kontonummer, hash_function(pointer->Kontonummer));
			pointer = pointer->next;
		}
	}

}

//gibt die Entsprechenden Listenelemente mit demselben Hashwert aus!!
void kunde_output_hash(kunde *pointer, int KN) {
	int hashaddress = hash_function(KN);
	pointer = hashtabelle[hashaddress];
	
		//pointer = hashtabelle[hashaddress];
		while (pointer != NULL) {
			printf("Kontonummer: %d\nHash: %d\n", pointer->Kontonummer, hash_function(pointer->Kontonummer));
			pointer = pointer->next;
		}
}

void kunde_delete_hash(kunde *pointer, int KN) {

	kunde *zeiger, *zeiger1; //Hilfsstrukturen
	int hashaddress = hash_function(KN); //Hashadresse berechnen
	pointer = hashtabelle[hashaddress]; //Liste mit entsprechenden Elementen füllen

	//Wenn erstes Element
	if (pointer != NULL) { 
		if (pointer->Kontonummer == KN) { //1.Element
			zeiger = pointer->next; //Hilfsstruktur wird mit dem nächsten Zeiger befüllt
			free(pointer); //Element löschen
			hashtabelle[hashaddress] = zeiger; //
		}
		else {
			zeiger = pointer;
			while (zeiger->next != NULL) {
				zeiger1 = zeiger->next;
				if (zeiger1->Kontonummer == KN) {
					zeiger->next = zeiger1->next;
					free(zeiger1);
					hashtabelle[hashaddress] = pointer;
					break;
				}
				zeiger = zeiger1;
			}/* Ende while */
		}/* Ende else */
	}/* Ende if(anfang != NULL) */
	else
		printf("Es sind keine Daten zum Löschen vorhanden!!!\n");
}


int main() {
	kunde *k = NULL; //komplette Liste
	kunde this; //Aktuelles Object

	//kunde *hashtable[MaxHash]; //Hash-Tabelle


	int counter = 0;
	//int SID; //SessionID des aktuellen Kunden


	//Menu
	int auswahl;
	while (1) {
		printf("1 - Kunde anlegen\n");
		printf("2 - Kunde suchen\n");
		printf("3 - Kunden unsortiert ausgeben\n");
		printf("4 - Kunde loeschen\n");

		scanf_s("%d", &auswahl);
		switch (auswahl) {
		case 1:
			//kunde_add(&k, counter++);
			for (int i = 0; i < 20; i++)
			{
				add(k, counter++);
			}
				
			break;
		case 2:
		{
			int KNummer;
			printf("Kontonummer:");
			scanf_s("%d", &KNummer);
			if (suche(k, KNummer) != NULL)
			{
				printf("Nummer %d gefunden!\n", KNummer);
				this = *suche(k, KNummer);
				printf("%d\n", this.Kontonummer);
			}
			else
				printf("Nummer nicht gefunden!\n");
			break;
		}
		case 3:
			kunde_output_hash(k, 1000);
			//kunde_output_all(k);
			break;
		case 4:
		{
			int KN;
			printf("Kontonummer:");
			scanf_s("%d", &KN);
			kunde_delete_hash(k, KN);
		}
		}
	}
	getch();
	return 0;
}