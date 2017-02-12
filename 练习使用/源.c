#include<stdio.h>
#include<stdbool.h>
#define MAX_Lenth 1001
int main()
{
	bool prime[MAX_Lenth] = { false };
	for (int i = 2; i != MAX_Lenth; ++i)
		prime[i] = true;
	for (int i = 2; i*i < MAX_Lenth; ++i)
	{
		if (!prime[i]) continue;
		for (int j = i*i; j < MAX_Lenth; ++j)
			if (j%i == 0) prime[j] = false;
	}
	int n = 1;
	for (int i = 2; i < MAX_Lenth; ++i)
	{
		if (prime[i])
		{
			printf("%6d", i);
			++n;
		}
		if (n > 10)
		{
			printf("\n");
			n = 1;
		}
	}
	while (1);
}