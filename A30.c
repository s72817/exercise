#include <stdio.h>
#include <string.h>
#define MAXArtikel = 30 

typedef struct {
	//char Artikel[30];
	int Artikel;
	double Preis;
	int Anz;
} Artikel[30];

Artikel A; //Init

double Gesamt() {
	double sum = 0.0;
	for (int i = 0; i < 30; i++)
	{
		sum += A[i].Preis * A[i].Anz;
	}
	return sum;
}



int main() {

	for (int i = 0; i < 30; i++)
	{
		//strcpy_s(A[i].Artikel, strlen(A[i].Artikel), "Artikel ");
		//strcpy(A[i].Artikel, "Artikel"); //strcpy_s("Artikel ", i));
		A[i].Artikel = i;
		A[i].Preis = 23.9 + i;
		A[i].Anz = 1 + i;
	}


	for (int j = 0; j < 30; j++)
	{
		//printf("Artikel = %s\n", A[j].Artikel);
		printf("Artikel %d\n", A[j].Artikel);
		printf("Preis = %lf\n", A[j].Preis);
		printf("Anzahl = %d\n", A[j].Anz);
		printf("********************\n\n");
	}

	printf("Gesamtwert = %.2lf Euro\n", Gesamt());
	printf("**************************\n");

	getch();
	return 0;
}