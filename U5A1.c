#include <stdio.h>
#include <math.h>

//Fakultaet rekursiv
int rf(int k) {
	if (k == 0) return 1;
	else return k * rf(k - 1);
}


int main(void) {

	int x = 5;
	int zahl, potenz;
	double sum = 1.0;

	for (int i = 1; i <= 13; i++)
	{
		sum += pow(x,i) / (rf(i));
		//printf("%lf\n", sum);
	}

	printf("%lf\n", sum);

	printf("%lf\n", exp(5));
	getch();
	return 0;
}