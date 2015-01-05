#include <stdio.h>
#include <math.h>

//berechnet Mittelwert und Standardabweichung
void f(int arr[], int len, double *MW, double *SA) {
 
  double sum = 0.0;
  double sum1 = 0.0;
  
  //Mittelwert
  for (int i = 0; i < len; i++)
 {
  sum += arr[i]; 
 }
 *MW = (1.0 / len) * sum;
 /*printf("%lf\n", (1.0 / len) * sum);*/
 
 //Standardabweichung
 for (int i = 0; i < len; i++)
 {
  sum1 += pow(arr[i] - *MW, 2);
 }
 *SA = sqrt(sum1/len);
}

void inc(int *p) {
	*p = *p + 1;
}



int main(void) {
	/*int a = 17;
	inc(&a);
	printf("%d\n", a);*/

	int arr[] = { 12, 11, 14, 16, 15 };
	int len = 5;

	double MW = 0.0;
	double SA = 0.0;

	f(arr, len, &MW, &SA);
	
	printf("%lf     %lf", MW, SA);

	getch();
	return 0;
}