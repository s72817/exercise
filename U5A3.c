#include <stdio.h>



double RabattX(int Ax, double Px) {
	if (Ax > 49) Ax = 49;
	if (Ax >= 10 && Ax <= 19) return (Px / 100 * 10.0) * Ax;
	else if (Ax >= 20 && Ax <= 39) return (Px / 100 * 15.0) * Ax;
	else if (Ax >= 40 && Ax <= 49) return (Px / 100 * 5.0) * Ax;
	else if (Ax >= 50) return 0.0;
	else return 0.0;
	
}

double RabattY(int Ay, double Py) {
	double Gesamt = 0.0;
	if (Ay >= 6 && Ay <=9)
	{
		Py -= 5.0;
		Gesamt = Py * Ay;
	}
	else if (Ay >= 10)
	{
		Py -= 10.0;
		Gesamt = Py * Ay;
	}
	else return 0.0; //wenn irgendetwas nicht stimmt

	if (Gesamt > 140.0)
	{
		return 140.0;
	}
	else return 0.0;
	
	
}

double RabattZ(int Az, double Pz) {
	if (Az > 25) Az = 25;
	if (Az <= 25)
	{
		return Az * (Pz / 100.0 * 8.0);
	}
	else return 0.0;
}



int main(void) {

	//Anzahl
	int Ax, Ay, Az;
	
	 //Preis
	double Px, Py, Pz;
	

	//Ax
	while (1) {
		printf("Anzahl Produkt X: ");
		scanf_s("%d", &Ax); while (getchar() != '\n');
		if (Ax >= 0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	//Ay
	while (1) 
	{
		printf("Anzahl Produkt Y: ");
		scanf_s("%d", &Ay); while (getchar() != '\n');
		if (Ay >= 0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	//Az
	while (1) {
		printf("Anzahl Produkt Z: ");
		scanf_s("%d", &Az); while (getchar() != '\n');
		if (Az >= 0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}

	//Px
	while (1) {
		printf("Preis X: ");
		scanf_s("%lf", &Px); while (getchar() != '\n');
		if (Px > 0.0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	//Py
	while (1) {
		printf("Preis Y: ");
		scanf_s("%lf", &Py); while (getchar() != '\n');
		if (Py > 0.0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	//Pz
	while (1) {
		printf("Preis Z: ");
		scanf_s("%lf", &Pz); while (getchar() != '\n');
		if (Pz > 0.0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}

	double Gesamtrabatt = 0;
	Gesamtrabatt += RabattX(Ax, Px) + RabattY(Ay, Py) + RabattZ(Az, Pz);
	if (Gesamtrabatt > 500.0) Gesamtrabatt = 500.0;

	double Gesamtpreis = Ax * Px + Ay * Py + Az * Pz;
	printf("Gesamtpreis o. Rabatt = %.2lf Euro\n", Gesamtpreis);
	printf("Gesamtpreis m. Rabatt = %.2lf Euro\n", Gesamtpreis - Gesamtrabatt);

	printf("Rabatt fuer X %.2lf\n", RabattX(Ax, Px));
	printf("Rabatt fuer Y %.2lf\n", RabattY(Ay, Py));
	printf("Rabatt fuer Z %.2lf\n", RabattZ(Az, Pz));

	getch();
	return 0;
}