#include <stdio.h>

double Umsatzrendite(double g, double u) {
		return (g / u) * 100;
}

int main(){
	double g = 0.0, u = 0.0;

	//Eingabe
	printf("\nGeben Sie einen Gewinn ein: ");
	scanf_s("%lf", &g);

	printf("Geben Sie den umsatz ein: ");
	scanf_s("%lf", &u);
	//End Eingabe

		printf("Fuer einen Gewinn von %lf\n bei einem Umsatz von %lf\n betraegt die Umsatzrendite %lf%%.",g, u, Umsatzrendite(g, u));
		getch();
		return 0;
}