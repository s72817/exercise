#include <stdio.h>

// Klasse Kaffeemaschine

typedef struct {
	double Wasserstand;
	double Kaffepulver;
	int iskochen;
} Kaffemaschine;


void KM_Wasser(Kaffemaschine *this, double Wasser) {
	this->Wasserstand = Wasser;
}

void KM_Pulver(Kaffemaschine *this, double Pulver) {
	this->Kaffepulver = Pulver;
}


typedef enum { Ein, Aus } Zustand;

int KM_kochen(Kaffemaschine *this, Zustand Z) { // int Z) { //
	if (Z == Ein) this->iskochen = 1;
	else this->iskochen = 0;
}

int main() {
	Kaffemaschine KM;

	double Wasser, Pulver;
	printf("Fuellmenge Wasser?\n");
	scanf_s("%lf", &Wasser);
	printf("Pulvermenge?\n");
	scanf_s("%lf", &Pulver);

	KM_Wasser(&KM, Wasser);
	KM_Pulver(&KM, Pulver);
	KM_kochen(&KM, Aus);
	

	printf("Wassermenge=%.2lf, Pulvermenge=%.2lf\n", Wasser, Pulver);
	if (KM.iskochen == 1) printf("Kaffemaschine kocht!\n");
	else printf("Kaffemaschine kocht nicht!\n");



	getch();
	return 0;
}