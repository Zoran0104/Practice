#include<stdio.h>
#include<stdbool.h>
void isprime(int num, bool a[]);

int main()
{
	printf("Please enter a number the max");
	int num;
	scanf("%d", &num);
	bool *prime=0;
	prime = (bool *)malloc(sizeof(bool)*num);
	isprime(num, prime);
	system("pause");
}

void isprime(int num, bool a[])
{
	a[0] = a[1] = false;
	for (int i = 2; i <= num; ++i)
		a[i] = true;
	for (int i = 2; i*i <= num; ++i)
		if (a[i])
			for (int j = i*i; j <= num; ++j)
				if (j%i == 0)
					a[j] = false;
	for(int i=6;i<=num;i+=2)
	{
		int flag = 1;
		for (int j = 2; j <= i/2; ++j)
		{
			if (a[j] && a[i - j])
			{
				printf("%d=%d+%d\n", i, j, i - j);
				flag = 0;
				break;
			}
		}
	}
}