#include<stdio.h>
int main(void)
{
	int i, j,k;
	for (i = 1; i <= 9; i=i+2)
	{
		for (j = 1; j <= (9-i)/2; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}
	for (i = 9; i > 0; i = i - 2)
	{
		for (j = 1; j <= (9 - i) / 2; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}
	system("pause");
}