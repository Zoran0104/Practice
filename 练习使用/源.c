#include<stdio.h>
int main(void)
{
	int i, j, n;
	printf("Please Enter n: "); 
	scanf_s("%d", &n); 
	for (i = 1;i <= n;i++)
	{
		for (j = 1; j <= n + i - 1; j++)
			if (j > n - i) 
				printf("*"); 
			else printf(" "); 
			printf("\n");
	}
	for (i = 1;i<n;i++)
	{
		for (j = 1; j <= 2 * n - i - 1; j++) 
			if (j > i) 
				printf("*"); 
			else printf(" "); 
			printf("\n");
	}
	system("pause");
}