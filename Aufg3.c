#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double Anlagendauer(double SK, double EK, double Zins) {

	return log(SK*(1+Zins))*EK;
}

int main() {
	double SK = 176.32;
	double EK = 0.66;
	double Zins = 0.5;

	printf("Fuer die Werte:\n Startkapital = %lf\n Endkapital = %lf und\n Zins = %lf\n konnte folgende Anlagendauer berechnet werden\n Anlagendauer = %lf\n", SK, EK, Zins, Anlagendauer(SK,EK,Zins));
	printf("%lf", M_PI);
	getch();

	return 0;
}