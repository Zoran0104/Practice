#include<stdio.h>
#define SIZE 1001
int main()
{
	int prime[SIZE] = { 0 };
	for (int i = 2; i != SIZE; ++i)
		prime[i] = 1;
	for (int i = 2; i*i < SIZE; ++i)
	{
		if (prime[i])
		{
			for (int j = i*i; j < SIZE; ++j)
			{
				if (!prime[i]) 
					continue;
				else if (j%i == 0) 
					prime[j] = 0;
			}
		}
	}
	int n = 1;
	for (int i = 2; i < SIZE; ++i)
	{
		if (prime[i])
		{
			printf("%6d", i);
			++n;
		}
		if (n > 10)
		{
			putchar('\n');
			n = 1;
		}
	}
	system("pause");
}