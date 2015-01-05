#include <stdio.h>
#include <math.h>
#define Quadrat(x) ((x)*(x))


double SkalarPr(int V1[], int V2[])
{
	double sum = 0.0;
	for (int i = 0; i < 3; i++)
	{
		sum += V1[i] * V2[i];
	}
	return sum;
}

double VSumme(int V1[], int V2[])
{
	double sum = 0.0;
	for (int i = 0; i < 3; i++)
	{
		//printf("%lf", );
		sum += Quadrat(V1[i] + V2[i]); //Warum nicht Zeiger -> *VA[i]?
	}
	return sqrt(sum);
}

void MultiMV(int *matrix, int V[], int z, int s) { //Matrix Vektor
	int vektor[3] = { 0, 0, 0 };
	int x1 = 0;
	//for (int j = 0; j < s; j++) //zeile
		for (int i = 0; i < (z * s); i++) //spalte
		{
		//x1 += M1[2][i] * V[i];
		//vektor[j] += *(matrix + i);// * V[j];
			printf("%i", *(matrix + i));
		}
			

	//printf("%d", x1);

	//printf("\n%d\n", x1);

	/*for (int x = 0; x < 3; x++)
	{
		printf("%d\n", vektor[x]);
	}*/
}


int main(void) {

	int Vektor1[] = { 1, 3, 5 };
	int Vektor2[] = { 2, 0, 4 };

	int VektorOut[] = { 0, 0, 0 };

	int MatA[3][3] = { { 3, 2, 1 }, { 1, 0, 7 }, { 3, -1, -1 } };
	int MatB[3][3] = { { 2, 3, 1 }, { 5, 3, 3 }, { 5, -1, 2 } };
	int z = 3, s = 3; //z=Zeilen, s=Spalten

	//printf("Skalarprodukt = %lf\n", SkalarPr(Vektor1, Vektor2));
	//printf("Summe Vektor A + Vektor B = %lf\n\n",VSumme(Vektor1, Vektor2, &VektorOut));
	//
	//printf("MatrixA\n");
	///*for (int i = 0; i < s; i++)
	//{*/
	//	for (int j = 0; j < z; j++)
	//	{
	//		printf("%d\t", MatA[0][j]);
	//	}
	//	//printf("\n");
	////}

	//for (int i = 0; i < z; i++) //spalte
	//{
	//	//x1 += M1[2][i] * V[i];
	//	//vektor[j] += M1[j][i] * V[i];
	//	//printf("%d\n", MatA[1][i]);// * V[i]);
	//}


	//	printf("\n");
	MultiMV(MatA, Vektor1, z, s);

	//printf("MatrixA");

	/*printf("Sie Summe aus beiden Vektoren ist:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", VektorOut[i]);
	}*/



	getch();
	return 0;
}



