#include <stdio.h>
#include <math.h>


double CO2_Ausstoss(int Typ, double Verbrauch) {

	if (Typ == 0) //Benziner
	{
		return Verbrauch * 23.7;
	}
	else if (Typ == 1) //Diesel
	{
		return Verbrauch * 26.5;
	}
	else
	{
		return 0.0;
	}

}

double CO2_Besteuerung(double CO2_Wert) {
	if (CO2_Wert > 120.0)
	{
		return (CO2_Wert - 120) * 2;
	}
	else
	{
		return 0.0;
	}

}

//Runden!!
double Hubraum_Besteuerung(int Typ, double Hubraum) {
	if (Typ == 0) //Benziner
	{
		return ceil(Hubraum / 100 * 2); //ceil rundet auf
	}
	else if (Typ == 1) //Diesel
	{
		return ceil(Hubraum / 100 * 9.5); //ceil rundet auf
	}
	else
	{
		return 0.0;
	}
}

double KFZ_Steuer(double Hubraum_Besteruerung, double CO2_Besteuerung) {
	return Hubraum_Besteruerung + CO2_Besteuerung;
}




int main() {

	int Typ = 0; //0 = Benziner, 1 = Diesel
	double Verbrauch = 6.5;
	double Hubraum = 1390;

	printf("\n--------------------------------");
	printf("\n---------CO2-Verbrauch----------\n");
	printf("--------------------------------\n\n");

	printf("Das Fahrzeug emittiert %.2lf Gramm CO2 je gefahrenen Kilometer.\n", CO2_Ausstoss(Typ, Verbrauch));

	printf("\n--------------------------------");
	printf("\n---------CO2-Steuer-------------\n");
	printf("--------------------------------\n\n");

	printf("\nFuer das Fahrzeug muss folgende CO2-Steuer bezahlt werden: %.2lf Euro\n", CO2_Besteuerung(CO2_Ausstoss(Typ, Verbrauch)));

	printf("\n--------------------------------");
	printf("\n---------Hubraum-Steuer---------\n");
	printf("--------------------------------\n\n");

	printf("\nFur einen Hubraum von %.0lf ccm \nmuss folgende Hubraum-Steuer bezahlt werden: \n%.2lf Euro\n", Hubraum, Hubraum_Besteuerung(Typ, Hubraum));

	printf("\n--------------------------------");
	printf("\n---------KFZ-Steuer-------------\n");
	printf("--------------------------------\n\n");

	printf("Die KFZ-Steuer betraegt: %.2lf Euro.", KFZ_Steuer(Hubraum_Besteuerung(Typ, Hubraum), CO2_Besteuerung(CO2_Ausstoss(Typ, Verbrauch))));



	getch();
	return 0;
}