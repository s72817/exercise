#include <stdio.h>
#include <math.h>

//----------------------------
// PQ-Formel
// ax^2+bx+c = 0
// by Richard Kerber
//----------------------------


//Public Sub
void PQ(double p, double q) {
	double A[2];
	double x1, x2;
	printf("p=%.2lf, q=%.2lf\n\n", p, q);
	x1 = -(p / 2);
	x2 = sqrt(pow(p / 2, 2) - q); //evtl. i beachten
	A[0] = x1 + x2;
	A[1] = x1 - x2;

	for (int i = 0; i < 2; i++)
	{
		printf("Erg %d = %.2lf\n",i, A[i]);
	}
}


int main() {
	PQ(-7,4);
	getch();
	return 0;
}