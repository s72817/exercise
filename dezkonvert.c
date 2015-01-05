#include  <stdio.h>
#define N 128

int  main(void) 
{
    int  zahl, hilf, basis, zaehler=0, i;
    int  ziel[N];               // int-Vektor ziel

    while (1) {
       printf("Basis des Zielsystems (2<=Basis<=36): ");
       scanf("%d", &basis); while ( getchar() != '\n' );
	  
       if (basis>=2 && basis<=36)
          break;
    }

    printf("Zu wandelnde Zahl aus Dezimalsystem : ");
    scanf("%d", &zahl); while ( getchar() != '\n' );
    hilf = zahl;

    while (zahl>0)  {
       printf("%5d : %2d = %5d Rest %2d", zahl, basis, 
		      zahl/basis, ziel[zaehler] = zahl % basis);
       if (ziel[zaehler] >=10)
          printf(" (%c)", ziel[zaehler]-10+'A');
       printf("\n");
       zahl /= basis;
       ++zaehler;
    }

    printf("     ---> %d(10) = ", hilf);
    for (i=zaehler-1 ; i>=0 ; i--)
       if (ziel[i] < 10)
          printf("%d", ziel[i]);
       else
          printf("%c", ziel[i]-10+'A');

    printf("(%d)\n",basis);
	getc(stdin);
    return 0;
}

/*
Basis des Zielsystems (2<=Basis<=36): 2
Zu wandelnde Zahl aus Dezimalsystem : 10
   10 :  2 =     5 Rest  0
    5 :  2 =     2 Rest  1
    2 :  2 =     1 Rest  0
    1 :  2 =     0 Rest  1
     ---> 10(10) = 1010(2)
----------------------------------------

Basis des Zielsystems (2<=Basis<=36): 16
Zu wandelnde Zahl aus Dezimalsystem : 123
  123 : 16 =     7 Rest 11 (B)
    7 : 16 =     0 Rest  7
     ---> 123(10) = 7B(16)
*/