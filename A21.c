#include <stdio.h>


int square(int x) {
	return x*x;
}


int mypow(int x, int n) {
	int sum = 0;
	if (n == 0) return 1;
	if (n%2 == 0) //n gerade
	{
		sum += square(mypow(x, n / 2));
	}
	if (n % 2 == 1) //n ungerade
	{
		sum += x * square(mypow(x, (n - 1) / 2));
	}
	return sum;
}

int potenz(int x, int n)
{
	if (n>0)
		return (x*potenz(x, --n));  /* rekursiver Aufruf */
	else
		return (1);
}

int rec_pow(int x, int c){
	return c ? (c % 2 ? x : 1) * rec_pow(x*x, c / 2) : 1;
}

int main(void){

	int x = 9;
	int n = 5;

	printf("1: %d\n", mypow(x,n));
	
	printf("2: %d\n", potenz(x,n));
	
	printf("3: %d\n", rec_pow(x,n));


	getch();
	return 0;
}