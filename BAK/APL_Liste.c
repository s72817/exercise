#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define MaxKunde 1000
#define MaxHash 10
#define KN_len 10

/// <summary>
/// Kundenstruktur
/// </summary>
typedef struct {
	int ID;
	int Kontonummer[10]; //10-stellig
	double Guthaben;
	unsigned int PIN;
	int isblocked;

	struct kunde *next;
}kunde;

kunde *hashtabelle[MaxHash];

/// <summary>
/// Die Hashtabelle (Hash-Array) mit den max. Einträgen
/// </summary>
//kunde *hashtabelle[MaxHash];

//void get_acc_no(int *Arr);
//void num_to_arr(int arr[], int len, long long int num);
//long long int arr_to_num(int *arr, int len);
//void show_KN(int *KN);
//int hash_function(long long int Kontonummer);
//kunde *add(kunde *konto, int counter);
//kunde *suche(kunde *konto, long long int Kontonummer);
//void kunde_output_all(kunde *konto);
//void kunde_output_hash(kunde *konto, long long int KN);
//void kunde_delete_hash(kunde *konto, long long int KN);
//int check_acc_no_digit(int acc_no[]);
//int check_acc_no(long long int Kontonummer);


/// <summary>
/// Generiert eine 10-stellige Kontonummer. 
/// 1.u.2. Ziffer = Bankcode, 3.-9.Ziffer = Kundencode,
/// 10.Ziffer = Prüfziffer (vgl. ISBN)
/// </summary>
/// <param name="Arr">The arr.</param>
void get_acc_no(int *Arr) {
	//1. und 2. Stellle = Bankcode
	Arr[0] = 2; Arr[1] = 4;
	do {
		//3.-9. Ziffer = Kundencode
		for (int i = 2; i < 9; i++)
			Arr[i] = rand() % 10;
		//Algorithmus für 10.Ziffer = Prüfziffer (vgl. ISBN)
		long sum = 0;
		for (int i = 0; i < 9; i++)
			sum += ((i + 1)*Arr[i]);
		Arr[9] = sum % 11;
	} while (Arr[9] >= 10); //als Prüfziffer darf keine Zahl größer 9 herauskommen
}


/// <summary>
/// Long Long Integer -> int Array
/// </summary>
/// <param name="arr">int Array</param>
/// <param name="len">Länge des Arrays</param>
/// <param name="num">Zahl</param>
void num_to_arr(int arr[], int len, long long int num) {
	for (int i = 10 - 1; i >= 0; --i) {
		arr[i] = num % 10;
		num /= 10;
	}
}

/// <summary>
/// int Array -> Integer
/// </summary>
/// <param name="arr">int Array</param>
/// <param name="len">Länge des Arrays</param>
/// <returns>long long Integer</returns>
long long int arr_to_num(int *arr, int len) {
	long long int k = 0;
	for (int i = 0; i < len; i++)
		k = 10 * k + arr[i];
	return k;
}


void show_KN(int *KN) {
	for (int i = 0; i < KN_len; i++)
		printf("%d", KN[i]);
	printf("\n");
}


/// <summary>
/// Die Hashfunktion. 
/// </summary>
/// <param name="Kontonummer">Kontonummer als unsigned long int</param>
/// <returns>Gibt einen Wert zwischen 0 und MaxHash zurück.</returns>
int hash_function(long long int Kontonummer) {
	//Für m sollten Sie idealerweise eine Primzahl so nahe wie möglich am höchsten Index wählen.*/
	return Kontonummer % 7;
}




/// <summary>
/// Initialisiert und fügt einen Kunden der Liste hinzu.
/// </summary>
/// <param name="konto">Zeiger auf Konto-Liste</param>
/// <param name="counter">Zähler als int</param>
/// <returns>Kunde-Struktur</returns>
kunde *add(kunde *konto, kunde **hashtabelle, int counter) {
	int KN_Arr[10];
	get_acc_no(KN_Arr);

	//Hash Wert generienen
	int hashaddress = hash_function(arr_to_num(KN_Arr, KN_len)); //verbesserungswürdig
	/* Zeiger auf errechnete Tabellenadresse durch hash_funktion */
	konto = hashtabelle[hashaddress];

	/* Speicher für neues Element allozieren */
	konto = malloc(sizeof(kunde));
	if (konto == NULL) {
		printf("Kein Speicher für neues Element vorhanden\n");
		return NULL;
	}
	//Struct befüllen
	
	konto->ID = counter;
	for (int i = 0; i < KN_len; i++)
		konto->Kontonummer[i] = KN_Arr[i];
	konto->Guthaben = 0.0;
	konto->PIN = counter * 5 + 1; //TODO: PIN Generator
	konto->isblocked = 0;
	//Zeiger vom nächsten Element bekommt errechnete Hashadresse
	konto->next = hashtabelle[hashaddress];
	//Wert zum Hash(Array) hinzufüen
	hashtabelle[hashaddress] = konto;
	

	printf("\n----------------------------\n");
	printf("Sie haben erfolgreich einen neuen Kunden angelegt!\n");
	printf("KundenID......: %d\n", konto->ID);
	printf("Kontonummer...: %lld", arr_to_num(konto->Kontonummer, KN_len));
	printf("\nGuthaben......: %.2lf Euro\n", konto->Guthaben);
	printf("Pin...........: %d\n", konto->PIN);
	printf("----------------------------\n"); 

	return konto;
}

/// <summary>
/// Suche nach Listenelement mit kontonummer
/// </summary>
/// <param name="konto">kundenliste</param>
/// <param name="Kontonummer">Kontonummer als long long</param>
/// <returns>struct kunde</returns>
kunde *suche(kunde *konto, kunde **hashtabelle, long long int Kontonummer) {
	int hashaddress = hash_function(Kontonummer);
	konto = hashtabelle[hashaddress];
	kunde *me = NULL;
	while (konto != NULL) {
		if (arr_to_num(konto->Kontonummer, KN_len) == Kontonummer) {
			me = konto;
			break;
		}
		konto = konto->next;
	}
	return me;
}


void kunde_output_all(kunde *konto, kunde **hashtabelle) {
	for (int i = 0; i < MaxHash; i++){
		konto = hashtabelle[i];
		while (konto != NULL) {
			printf("Kontonummer: %d\nHash: %d\n", konto->Kontonummer, hash_function(konto->Kontonummer));
			konto = konto->next;
		}
	}
}

//gibt die Entsprechenden Listenelemente mit demselben Hashwert aus!!
void kunde_output_hash(kunde *konto, kunde **hashtabelle, long long int KN) {
	int hashaddress = hash_function(KN);
	konto = hashtabelle[hashaddress];
	
		//pointer = hashtabelle[hashaddress];
	while (konto != NULL) {
		show_KN(konto->Kontonummer);
		printf("Hash: %d\n", hash_function(konto->Kontonummer));
		konto = konto->next;
		}
}

void kunde_delete_hash(kunde *konto, kunde **hashtabelle, long long int KN) {
	kunde *zeiger, *zeiger1; //Hilfsstrukturen
	int hashaddress = hash_function(KN); //Hashadresse berechnen
	konto = hashtabelle[hashaddress]; //Liste mit entsprechenden Elementen füllen

	//Wenn erstes Element
	if (konto != NULL) {
		if (arr_to_num(konto->Kontonummer, KN_len) == KN) { //1.Element
			zeiger = konto->next; //Hilfsstruktur wird mit dem nächsten Zeiger befüllt
			free(konto); //Element löschen
			hashtabelle[hashaddress] = zeiger; //
		}
		else {
			zeiger = konto;
			while (zeiger->next != NULL) {
				zeiger1 = zeiger->next;
				if (arr_to_num(zeiger1->Kontonummer, KN_len) == KN) {
					zeiger->next = zeiger1->next;
					free(zeiger1);
					hashtabelle[hashaddress] = konto;
					break;
				}
				zeiger = zeiger1;
			}/* Ende while */
		}/* Ende else */
	}/* Ende if(anfang != NULL) */
	else
		printf("Es sind keine Daten zum Löschen vorhanden!!!\n");
}


/// <summary>
/// Zählt Ziffern eines Long Long Integer
/// </summary>
/// <param name="x">Zahl</param>
/// <returns>Anzahl der Ziffern</returns>
//int digits(long long int x) { return log10(x) + 1; }
int digits(long long int x) {
	int count = 0;
	while (x != 0)
	{
		x /= 10;             /* n=n/10 */
		++count;
	}
	return count;
}


/// <summary>
/// Prüft die angegebene Kontonummer inkl. Prüfziffer
/// </summary>
/// <param name="acc_no">Kontonummer als int Array</param>
/// <returns>0 = False, 1 = True</returns>
int check_acc_no_digit(int acc_no[]) {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += (i + 1)*acc_no[i];
	if ((sum % 11) == acc_no[9]) return 1;
	else return 0;
}

/// <summary>
/// Prüft die angegebene Kontonummer
/// </summary>
/// <param name="Kontonummer">Kontonummer als Long Long</param>
/// <returns>
/// 0 = weniger als 10 Ziffern
/// 1 = Prüfziffer stimmt nicht
/// 2 = Richtig
///</returns>
int check_acc_no(long long int Kontonummer) {
	if (digits(Kontonummer) < 10) return 0;
	int KN[KN_len];
	num_to_arr(KN, KN_len, Kontonummer);
	if (check_acc_no(Kontonummer) == 0) return 1;
	else return 2;
}


int main() {
	kunde *k = NULL; //komplette Liste
	/*kunde *hashtabelle[MaxHash];*/
	kunde me; //Aktuelles Object

	//kunde *hashtable[MaxHash]; //Hash-Tabelle

	int counter = 0;


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
				add(k, &hashtabelle, counter++);
				
			break;
		case 2:
		{
			long long int tmp_KN;
			printf("Kontonummer:");
			scanf_s("%lld", &tmp_KN);
			while (getchar() != '\n');

			if (tmp_KN >= 1000000000 && tmp_KN <= 9999999999) {
				//int res = check_acc_no(tmp_KN);
				/*if (res == 0) printf("Die eingegebene kontonummer hat weniger als 10 Zeichen!\n");
				else if (res == 1) printf("Die eingegebene Kontonummer ist falsch!\n");
				else printf("Allgemeiner Fehler!\n");*/

				if (suche(k, &hashtabelle, tmp_KN) != NULL) {
					me = *suche(k, &hashtabelle, tmp_KN);
					printf("Nummer %lld gefunden!\n", arr_to_num(me.Kontonummer, KN_len));
				}
				else
					printf("Nummer nicht gefunden!\n");
				break;
			}
			else printf("Falsche Eingabe!\n");
			
		}
			break;
		case 3:
			kunde_output_hash(k, &hashtabelle, 2417409488);
			//kunde_output_all(k);
			break;
		case 4:
		{
			long long int KN;
			printf("Kontonummer:");
			scanf_s("%lld", &KN);
			kunde_delete_hash(k, &hashtabelle, KN);
		}
		}
	}

	//getch();
	return 0;
}



/// <summary>
/// String_to_uls the specified string.
/// </summary>
/// <param name="string">The string.</param>
/// <returns></returns>
//unsigned long int string_to_ul(char string[]) {return atol(string);}

/*int KN[10];

long long int into;
scanf_s("%lld", &into);
printf("Eingabe: %lld\n", into);

num_to_arr(KN, 10, into);

for (int i=0;i<10;i++) {
printf("%d", KN[i]);
}*/

/*for (int i = 0; i<10; i++)
printf("%ld\n", GetRand);*/

/*int Arr[10] = { 3, 8, 2, 7, 4, 1, 8, 2, 6, 7 };
int B[10];
for (int i = 0; i < 10; i++) {
B[i] = Arr[i];
printf("%d", B[i]);
}*/

/*int Arr[10];
for (int i = 0; i < 10; i++) {
get_acc_no(Arr);
for (int i = 0; i < 10; i++)
printf("%d", Arr[i]);
if (check_acc_no(Arr) == 1) printf(" Richtig!");
printf("\n");
}*/

/*int KN[KN_len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1 };
int KN1[KN_len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1 };
if (memcmp(KN, KN1, sizeof(KN)) == 0)
printf("gleich");
else
printf("ungleich");*/

//int i;
//int array1[KN_len] = { 2, 4, 1, 7, 4, 0, 9, 4, 8, 8 };
//int array2[KN_len] = { 2, 4, 1, 7, 4, 0, 9, 4, 8, 8 };

/////*for (i = 0; i < KN_len; i++) {
////	array1[i] = i;
////	array2[i] = i;
////}*/
//////array2[5] = 100; /* Verändert array2 an Pos. 5. */

//if (memcmp(array1, array2, sizeof(array1)) == 0)
//	printf("Beide Arrays haben den gleichen Inhalt\n");
//else
//	printf("Die Arrays sind unterschiedlich\n");

/*long long int KNummer;
printf("Kontonummer:");
scanf_s("%lld", &KNummer);
printf("%d", digits(KNummer));*/