#include <stdio.h>


void map2(double Arr1[], double Arr2[], int len, double(*f)(double, double), double OutputArr[]) {
	for (int i = 0; i < len; i++)
	{
		OutputArr[i] = (*f)(Arr1[i], Arr2[i]);
	}
}

double Gewinn(double EK, double VK) {
	return VK-EK;
}

double Gewinnspanne(double EK, double VK) {
	return ((VK - EK) / VK) * 100;
}

int main(void) {


	double EK[] = { 3.4, 2.5, 5.8, 6.0 };
	double VK[] = { 3.6, 3.0, 6.8, 6.1 };

	double GArr[] = { 0,0,0,0 };
	double GSArr[] = { 0,0,0,0 };
	//double GArr[] = { 0 };


	map2(EK, VK, 4, &Gewinn, GArr);
	for (int k = 0; k < 4; k++)
		printf("Der Gewinn betraegt: %.2lf \n", GArr[k]);

	map2(EK, VK, 4, &Gewinnspanne, GSArr);
	for (int i = 0; i < 4; i++)
		printf("Die Gewinnspanne betraegt: %.2lf%% \n", GSArr[i]);

	getch();
	return 0;
}