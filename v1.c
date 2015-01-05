#include <stdio.h>


double Umsatzrendite(double g, double u)
{
	return (g / u)*100;
}

int main() 
{
	double g = 12.9;
	double u = 20.4;
	printf("Bei einem Umsatz von %lf und einem Gewinn von %lf betraegt die Umsatzrendite %lf %%\n", u, g, Umsatzrendite(g, u));
	getch();

	return 0;
}

