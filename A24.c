#include <stdio.h>


void map2(int Anz[], double Preis[], int len, double OutputArr[]) {
	for (int i = 0; i < len; i++)
	{
		OutputArr[i] = Anz[i] * Preis[i];
	}
}

double SummeArr(double x[], int len) {
	double sum = 0.0;
	for (int i = 0; i < len; i++)
		sum += x[i];
	return sum;
}

int main() {

	int Anz[] = { 102, 55, 23, 76 };
	double Preis[] = { 36.4, 21.5, 15.8, 86.0 };
	int len = 4;
	

	double Out[] = {0,0,0,0};

	map2(Anz, Preis, len, Out);
	for (int i = 0; i < len; i++)
	{
		printf("%d. Artikel = %.2lf\n",i, Out[i]);
	}
	printf("-----------------------------\n");
	printf("Wert des Warenlagers = %.2lf\n", SummeArr(Out, len));

	//map2(EK, VK, 4, &Gewinn, Output);

	getch();
	return 0;
}