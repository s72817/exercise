#include <stdio.h>

void KA(int KN[], double GH[], int PIN[]){
	KN[0] = 6657;
	GH[0] = 0.0;
	PIN[0] = 1234;
}

int main(void) {

	int KN[] = { 0 };
	double GH[] = {0};
	int PIN[] = { 0 };


	KA(KN, GH, PIN);
	printf("%d, %lf, %d\n", KN[0], GH[0], PIN[0]);

	getch();
	return 0;
}