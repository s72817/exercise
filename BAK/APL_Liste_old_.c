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
	/*key = key mod m
	Für m sollten Sie idealerweise eine Primzahl so nahe wie möglich am höchsten Index wählen.*/
	return Kontonummer % 7;
}

//int kunde_pop(kunde **all, int KundeID) {
//	kunde *top = *all;
//	if (!*all) {
//		printf("stack_pop: empty stack\n");
//		abort();
//	}
//
//	
//}

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
	pointer->PIN = counter;
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

int stack_pop(kunde **s) {
	kunde *top = *s;
	if (!*s) {
		printf("stack_pop: empty stack\n");
		abort();
	}
	int item = top->Kontonummer;
	*s = top->next;
	//free(top); //soll nicht gelöscht werden!
	return item;
}

int suche(kunde *pointer, int Kontonummer) {
	int result = 0;
	int hashaddress = hash_function(Kontonummer);
	pointer = hashtabelle[hashaddress];
	while (pointer != NULL) {
		if (pointer->Kontonummer == Kontonummer)
			result = 1;
		pointer = pointer->next;
	}
	return result;
}


int main() {
	kunde *k = NULL;
	kunde *SIDx;
	//kunde *hashtable[MaxHash]; //Hash-Tabelle


	int counter = 0;
	int SID; //SessionID des aktuellen Kunden


	//Menu
	int auswahl;
	while (1) {
		printf("1 - Kunde anlegen\n");
		printf("2 - Kunde suchen\n");

		scanf_s("%d", &auswahl);
		switch (auswahl) {
		case 1:
			//kunde_add(&k, counter++);
			add(k, counter++);
			break;
		case 2:
		{
			int KNummer;
			printf("Kontonummer:");
			scanf_s("%d", &KNummer);
			if (suche(k, KNummer) == 1)
			{
				printf("Nummer %d gefunden!\n", KNummer);
				SID = KNummer - 1000;
				printf("Aktuelle ID: %d\n", SID);
			}
			else
				printf("Nummer nicht gefunden!\n");
			break;
		}
		}
	}
	getch();
	return 0;
}