#include <stdio.h>;


int isEbola(double fieber, int temp, int symptome, int menschkontakt, int berufkontakt, int tierkontakt) {
	if (fieber > 38.5 || (temp == 1 && symptome == 1))
	{
		if (menschkontakt == 1 || berufkontakt == 1 || tierkontakt == 1) return 1;
		else return 0;
	}
	else return 0;

}


int main() {
	double fieber = 40.0;
	int temp = 1;
	int symptome = 0;
	int menschkontakt = 0;
	int berufkontakt = 0;
	int tierkontakt = 0;

	if (isEbola(fieber, temp, symptome, menschkontakt, berufkontakt, tierkontakt) == 1)
	{
		printf("****************************************\nAchtung!\n****************************************\nDer Patient hat Ebola!");
	}
	else printf("Der Patient ist gesund!");

	getch();
	return 0;
}
