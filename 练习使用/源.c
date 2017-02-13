#include<stdio.h>
#include<stdbool.h>
#define NUM 1001
int main()
{
	bool prime[NUM] = { false };
	for (int i = 2; i < NUM; ++i)
	{
		prime[i] = true;
	}
	for (int i = 2; i*i < NUM; ++i)
	{
		if (!prime[i]) continue;
		for (int j = i*i; j < NUM; ++j)
			if (j%i == 0)
				prime[j] = false;
	}
	int n = 1;
	for (int i = 2; i < NUM; ++i)
	{
		if (prime[i])
		{
			printf("%5d", i);
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