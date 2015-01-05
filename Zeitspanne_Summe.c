#include <stdio.h>




int main() {

	int row = 2, col = 5;
	int Time[2][5];

	int t, h, m, s, ms;

	
	while (1) {
		printf("Tag 1: \n");
		scanf_s("%d", &Time[0][0]); while (getchar() != '\n');
		if (Time[0][0] >= 0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Stunde 1: \n");
		scanf_s("%d", &Time[0][1]); while (getchar() != '\n');
		if (Time[0][1] >= 0 && Time[0][1] < 24)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Minute 1: \n");
		scanf_s("%d", &Time[0][2]); while (getchar() != '\n');
		if (Time[0][2] >= 0 && Time[0][2] < 60)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Sekunde 1: \n");
		scanf_s("%d", &Time[0][3]); while (getchar() != '\n');
		if (Time[0][3] >= 0 && Time[0][3] < 60)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Millisekunde 1: \n");
		scanf_s("%d", &Time[0][4]); while (getchar() != '\n');
		if (Time[0][4] >= 0 && Time[0][4] < 1000)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	//--------------------------------
	while (1) {
		printf("Tag 2: \n");
		scanf_s("%d", &Time[1][0]); while (getchar() != '\n');
		if (Time[1][0] >= 0)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Stunde 2: \n");
		scanf_s("%d", &Time[1][1]); while (getchar() != '\n');
		if (Time[1][1] >= 0 && Time[1][1] < 24)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Minute 2: \n");
		scanf_s("%d", &Time[1][2]); while (getchar() != '\n');
		if (Time[1][2] >= 0 && Time[1][2] < 60)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Sekunde 2: \n");
		scanf_s("%d", &Time[1][3]); while (getchar() != '\n');
		if (Time[1][3] >= 0 && Time[1][3] < 60)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}
	while (1) {
		printf("Millisekunde 2: \n");
		scanf_s("%d", &Time[1][4]); while (getchar() != '\n');
		if (Time[1][4] >= 0 && Time[1][4] < 1000)break;
		else printf("falsche Eingabe! Bitte wiederholen\n");
	}

	
	/*for (int i = 0; i < row; i++) {
		printf("\nZeit %d", i +1);
				for (int j = 0; j < col; j++) {
					printf("\t%4d ", Time[i][j]);
				}
				printf("\n\n\n");
			}*/

	
	ms = Time[0][4] + Time[1][4];
	s = Time[0][3] + Time[1][3];
	m = Time[0][2] + Time[1][2];
	h = Time[0][1] + Time[1][1];
	t = Time[0][0] + Time[1][0];

	if (ms >= 1000)
	{
		ms -= 1000;
		s += 1;
	}
	if (s >= 60)
	{
		s -= 60;
		m += 1;
	}
	if (m >= 60)
	{
		m -= 60;
		h += 1;
	}
	if (h >= 24)
	{
		h -= 24;
		t += 1;
	}
	printf("\nDie Summe betraegt:\n%d Tage\n%d Stunde(n)\n%d Minute(n)\n%d Sekunde(n)\n%d Millisekunde(n)", t,h,m,s,ms);
	
	
	
	getch();
	return 0;
}



//#include <stdio.h> 
//
//int main() {
//	int i, j;
//
//	int row = 2, col = 5;
//	int Time[2][5];
//
//	char *Werte[] = {"Tag", "Stunde", "Minute", "Sekunde", "Millisekunde"};
//
//	/*char *woerter[] = { "und", "jetzt", "komst", "du" };
//	woerter[2] = "kommst";
//	printf("%s", woerter[2]);*/
//	/*Time[1][4] = 5;
//	printf("%d\n", Time[1][4]);*/
//	/* Eingabe der Array-Elemente */
//	printf("Bitte geben Sie hintereinander: \nTag, Stunde, Minute, Sekunde und Millisekunde ein\n");
//	for (i = 0; i < row; i++) {
//		for (j = 0; j < col; j++) {
//			printf("%d. %s :",i + 1, Werte[j]);
//			//scanf_s("%d", &Time[i][j]);
//			//while (1) 
//			//{
//			//	scanf_s("%d", &Time[i][j]); while (getchar() != '\n');
//			//	if ((Time[i][j] = Time[0][0]) && (Time[0][0] >= 0)) break;
//			//	else printf("falsche Eingabe! Bitte wiederholen:\n");
//			//	/*{
//			//		if ((Time[0][0] || Time[1][0]) >= 0) break;
//			//		else printf("falsche Eingabe! Bitte wiederholen:\n");
//			//	}*/
//			//}
//
//			while (1) {
//						//printf("Minute: \n");
//						scanf_s("%d", &Time[i][j]); while (getchar() != '\n');
//						if (Time[i][j] >= 0 && &Time[i][j] < 24)break;
//						else printf("falsche Eingabe! Bitte wiederholen\n");
//					}
//		}
//	}
//	printf("\nAusgabe von myarray[%d][%d]...\n\n", row, col);
//	for (i = 0; i < row; i++) {
//		for (j = 0; j < col; j++) {
//			printf("\t%4d ", Time[i][j]);
//		}
//		printf("\n\n");
//	}
//
//	getch();
//	return 0;
//}