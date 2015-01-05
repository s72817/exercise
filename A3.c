#include <stdio.h>
#include <math.h>

double Anlagendauer(double SK, double EK, double Zins) {
	//return log(SK*(1 + Zins))*EK;
	//return (((EK / SK) - 1) * 1 / Zins);
	return log(1 + Zins) * (EK / SK);
}

//char stext(char text){
//	printf("%c", text);
//}
double log_vbasis(double basis, double arg) {
	return log(arg) / log(basis);
}

double adauer(double SK, double EK, double Zins) {
	return log_vbasis(10 + Zins, EK / SK);
}

int main() {

	double SK = 0.0, EK = 0.0, Zins = 0.01;
	/*char TEXT = "Hallo Welt";

	printf("%c", TEXT);*/

	//Eingabe
	printf("\nGeben Sie ein Startkapital ein: ");
	scanf_s("%lf", &SK);

	printf("Geben Sie das Endkapital ein: ");
	scanf_s("%lf", &EK);
	//End Eingabe

	printf("\nFuer das Startkapital = %lf\n Endkapital = %lf und\n Zins %lf\n konnte folgende Anlagendauer berechnet werden\n Anlagendauer = %lf.", SK, EK, Zins, adauer(SK, EK, Zins));
	
	printf("\nFuer das Startkapital = %lf\n Endkapital = %lf und\n Zins %lf\n konnte folgende Anlagendauer berechnet werden\n Anlagendauer = %lf.", SK, EK, Zins, Anlagendauer(SK, EK, Zins));
	

	getch();  //Anhalten der Ausgabe
	
	return 0;
	
}