#include <stdio.h>
#include <math.h>

//Rendite der banken
double Rendite(double a, double b, double c, double d)
{
	return ((1.0 + a)*(1.0 + b)*(1.0 + c)*(1.0 + d) - 1)*100;
	//Kap. nach 1 Jahr = Startkapital * (1.0 + Zinsen/100.0)
}


double Renditemax(double R1, double R2, double R3)
{
	double max = R1;
	if (max<R2) max = R2;
	if (max<R3) max = R3;
	return max;
}

char Bankmax(double R1, double R2, double R3)
{
	char Bank = 'A';
	double max = R1;
	if (R2 > max) { Bank = 'B'; }
	if (R3 > max) { Bank = 'C'; }
	return Bank;
}

void textx()
{
	/*char message[] = "HALLO";
	return message;*/
	int x = 100;
	return x;
}

int main()
{
	double A, B, C;
	A = Rendite(0.02, 0.03, 0.05, 0.06);
	B = Rendite(0.03, 0.04, 0.05, 0.05);
	C = Rendite(0.03, 0.04, 0.05, 0.06);

	printf("Die Bank A hat eine Rendite von %lf%%\n", A);
	printf("Die Bank B hat eine Rendite von %lf%%\n", B);
	printf("Die Bank C hat eine Rendite von %lf%%\n", C);


	printf("Die Bank %c hat die hoechste Rendite von %lf%%\n", Bankmax(A, B, C), Renditemax(A, B, C));
	
	
	//char string[] = "Hello World";
	//printf("%d", textx);
	getch();
	return 0;
}