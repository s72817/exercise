#include <stdio.h>



int main() {
	int aus;
	int islog = 0;
	while (1)
	{
		printf("Menu1\n");
		scanf_s("%d", &aus);

		switch (aus)
		{
		case 1: islog = 1;
		}

		while (1)
		{
			if (islog == 0) break;

				printf("Menu2\n");
				scanf_s("%d", &aus);
				switch (aus)
				{
				case 1: islog = 0;
			}
		}


	}



}