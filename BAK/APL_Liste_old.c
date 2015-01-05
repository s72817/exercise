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
kunde *next = NULL;
kunde *anfang = NULL;

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

//int stack_pop(kunde **s) {
//	kunde *top = *s;
//	if (!*s) {
//		printf("stack_pop: empty stack\n");
//		abort();
//	}
//	int item = top->Kontonummer;
//	*s = top->next;
//	//free(top); //soll nicht gelöscht werden!
//	return item;
//}

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

void Ausgabe(kunde *all) {
	if (all == NULL)//Wenn Liste NULL ist
	{
		printf("Kein Kunde angelegt!\n");
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

void A(kunde *zeiger) {
	//kunde *zeiger = anfang;
	while (zeiger != NULL)
	{
		printf("KN: %d, PIN: %d", zeiger->Kontonummer, zeiger->PIN);
		zeiger = zeiger->next;
	}
	if (zeiger == NULL)
		printf("No Kunde\n");

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
			//A(k);
			//printf("%d", k[0].Kontonummer);
			if (k == NULL)
				printf("NULL\n");
			else
				printf("nicht NULL\n");
			break;
		}
	}
	getch();
	return 0;
}