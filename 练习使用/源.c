#include<stdio.h>
#include<stdbool.h>
#define NUMMAX 10001
int main()
{
	bool prime[NUMMAX] = { false };
	for (int i = 2; i < NUMMAX; ++i)
		prime[i] = true;
	for (int i = 2; i*i <= NUMMAX; ++i)
	{
		if (!prime[i]) continue;
		for (int j = i*i; j < NUMMAX; ++j)
			if (j%i == 0) prime[j] = false;
	}
	int n = 0,ls=0;
	for (int i = 2; i < NUMMAX; ++i)
	{
		if (prime[i])
		{
			++n;
			if (prime[i] && prime[i - 2])
			{
				printf("(%3d,%3d)     ", i-2, i);
				++ls;
				if (ls % 5 == 0)
					putchar('\n');
			}
		}
	}
	printf("\n%d数内有%d个素数，有%d个孪生素数。\n", NUMMAX - 1, n, ls);
	system("pause");
}