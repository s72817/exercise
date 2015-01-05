#include <stdio.h>   // gebrkonv.c
#include <math.h>

int  main(void)
{
    long double  n=0.0, hilf=0.0;
    int     basis=2,
            i=0, s=0, ziffer=0;

    printf("Umwandlung eines Dezimalbruchs in beliebiges System\n"
           "===================================================\n\n");
	do {
		 printf("\nUmzuwandelnder Dezimalbruch (0 < db < 1) = ");
		 scanf("%lf", &n); while(getchar() != '\n');
	} while((n<=0) || (n>=1));

    hilf = n;

	do {
		printf("Basis des Zielsystems [2,36] ? ");
		scanf("%d", &basis); while(getchar() != '\n');
	} while ((basis<2) || (basis>36)); 

	do {
		printf("\nAnzahl s (0, 100) der Nachkommastellen im Zielsystem ? ");
		scanf("%d", &s); while(getchar() != '\n');
	} while((s<0) && (s>=100));

    printf("\n(%g)10  =  (0.", n);

	/* Berechnung */
    for (i=1 ; (i<=s) && n; i++) {
       n=n*basis;
       ziffer=floor(n);  // oder: (int)n
       n-=ziffer;
       if (ziffer<10)
          printf("%d", ziffer);
       else
	      printf("%c", ziffer-10+'A');
    }
    printf(")%d\n", basis);

	/* Ausgabegestaltung */
    n = hilf;
    for (i=1 ; (i<=s) && (n+ziffer); i++) {
       printf("%20.10g * %2d = %16.10g Ueberlauf ",
              n, basis, n*basis);
       n=n*basis;
       ziffer=(int)n;
       n-=ziffer;
       if (ziffer<10)
          printf("%2d\n", ziffer);
       else
          printf("%2c\n", ziffer-10+'A');
    }
	getchar();
    return 0;
}
/*
Umwandlung eines Dezimalbruchs in beliebiges System
===================================================
Umzuwandelnder Dezimalbruch (0 < db < 1) = 0.125
Basis des Zielsystems [2,36] ? 16

Anzahl s (0, 100) der Nachkommastellen im Zielsystem ? 20

(0.125)10  =  (0.2)16
               0.125 * 16 =                2 Ueberlauf  2
                   0 * 16 =                0 Ueberlauf  0


Umwandlung eines Dezimalbruchs in beliebiges System
===================================================
Umzuwandelnder Dezimalbruch (0 < db < 1) = 0.123456789
Basis des Zielsystems [2,36] ? 16

Anzahl s (0, 100) der Nachkommastellen im Zielsystem ? 20

(0.123457)10  =  (0.1F9ADD3739635F)16
         0.123456789 * 16 =      1.975308624 Ueberlauf  1
         0.975308624 * 16 =      15.60493798 Ueberlauf  F
         0.604937984 * 16 =      9.679007744 Ueberlauf  9
         0.679007744 * 16 =       10.8641239 Ueberlauf  A
         0.864123904 * 16 =      13.82598246 Ueberlauf  D
         0.825982464 * 16 =      13.21571942 Ueberlauf  D
         0.215719424 * 16 =      3.451510783 Ueberlauf  3
        0.4515107833 * 16 =      7.224172533 Ueberlauf  7
        0.2241725326 * 16 =      3.586760521 Ueberlauf  3
        0.5867605209 * 16 =      9.388168335 Ueberlauf  9
         0.388168335 * 16 =      6.210693359 Ueberlauf  6
        0.2106933594 * 16 =       3.37109375 Ueberlauf  3
          0.37109375 * 16 =           5.9375 Ueberlauf  5
              0.9375 * 16 =               15 Ueberlauf  F
                   0 * 16 =                0 Ueberlauf  0
*/