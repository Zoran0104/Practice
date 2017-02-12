#include<stdio.h>
int main()
{
	int isprime[1001] = { 0 };
	for (int i = 2; i != 1001; ++i)
		isprime[i] = 1;
	for (int i = 2; i*i<1001; ++i)
	{
		if (isprime[i] == 1)
		{
			for (int j = i* i; j < 1001; ++j)
			{
				if (!isprime[i]) continue;
				else if (j%i == 0) isprime[j] = 0;
			}
		}
	}
	int n = 1;
	for (int i = 1; i != 1001; ++i)
	{
		
		if (isprime[i] == 1)
		{
			printf("%4d", i);
			++n;
		}
		if (n > 10) {
			putchar('\n');
			n = 1;
		}
	}
	while (1);
}