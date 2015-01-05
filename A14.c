#include <stdio.h>

int check_ISBN(int ISBN[]) {
	int sum = 0;
	
	for (int i = 0; i < 9; i++)
	{
		//printf("%d\n", k);
		//if ((i*ISBN[i]) % 11) return 1; //wahr
		//else return 0; //falsch
		sum += ((i+1)*ISBN[i]);
		//printf("%d\n", sum);
	}
	//printf("%d\n", sum);
	//printf("%d-%d\n", sum % 11, ISBN[9]);

	if ((sum % 11) == ISBN[9]) return 1;
	else return 0;
	//printf("%d", sum);
}


int main(void) {

	int ISBN[] = { 3,8,2,7,4,1,8,2,6,7 };

	printf("Die ISBN ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d", ISBN[i]);
	}
	
	printf(" ist: ");

	if (check_ISBN(ISBN) == 1) printf("Wahr\n");
	else printf("Falsch\n");

	getch();
	return 0;
}