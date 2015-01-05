#include <stdio.h>

int anztagemonat(int m) {
	if ((m >= 1) && (m <= 12)) //wenn Monat zwischen 1 und 12 liegt
	{
		//if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
		if (m == (1 || 3 || 5)) return 31;
		else if (m == 2) return 28; // Wenn Februar
		else return 30;
		//if ((m % 2 != 0) && (m >= 1 && m <= 7) || m == 8 || m == 10 || m == 11)
	}
	else return 0; // Wenn Monat nicht zwischen 1 und 12 liegt dann return 0;
}

int main() {

	//int monat = 11;

	for (int i = 1; i <= 12; i++)
	{
		printf("Die Anzahl der tage fuer den Monat %d betraegt %d\n", i, anztagemonat(i));
	}

	//printf("%d", anztagemonat(monat));

	getch();
	return 0;
}