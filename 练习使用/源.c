#include<stdio.h>
int main(void)
{
	int i, k;
	for (i = 1; i <= 9; i++)
	{
		for (k = 1; k <= i; k++)
			{
				printf("%d¡Á%d=%-2d   ", k, i, k*i);
			}
			printf("\n");
		
	}
	system("pause");
}