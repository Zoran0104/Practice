#include<stdio.h>
#include<stdbool.h>
void isprime(int n, bool num[]);
int main()
{
	int n = 0;
	printf("验证哥的猜想：\n请输入数的范围：");
	scanf("%d", &n);
	bool *p;
	p = (bool *)malloc(sizeof(bool)*n);
	isprime(n, p);
	for (int i = 6; i <= n; i += 2)
	{
		int flag = 1;
		for (int j = 2; j <= i / 2; ++j)
		{
			if (p[j] && p[i - j])
			{
				printf("%d=%d+%d\n", i, j, i - j);
				flag = 0;
			}
		}
		if (flag == 1)
			printf("wrong number!");
	}
	system("pause");
}
void isprime(int n, bool num[])
{
	num[1] = num[0] = false;
	for (int i = 2; i < n; ++i)
		num[i] = true;
	for (int i = 2; i*i <= n; ++i)
	{
		if (num[i])
		{
			for (int j = i*i; j < n; ++j)
			{
				if (j%i == 0) num[j] = false;
			}
		}
	}
}