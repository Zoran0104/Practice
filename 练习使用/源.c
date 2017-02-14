#include<stdio.h>
#include<stdbool.h>
void isprime(int n, bool num[])
{
	num[0] = num[1] = false;
	for (int i = 2; i < n + 1; ++i)
		num[i] = true;
	for (int i = 2; i*i < n + 1; ++i)
		if (num[i])
			for (int j = i*i; j < n; ++j)
				if (j%i == 0)
					num[j] = false;
}
int main()
{
	int flag;
	printf("哥德巴赫猜想验证：");
	printf("\n请输入您想验证的最大整数：");
	int n=0;
	scanf("%d", &n);
	bool *p;
	if (!(p = (bool *)malloc(sizeof(bool)*n)))
	{
		printf("wrong to run");
		system("pause");
	}
	isprime(n, p);
	for (int i = 6; i <= n; i += 2)
	{
		flag = 1;
		for (int j = 2; j <= i / 2; ++j)
		{
			if (j % 2 == 0||(i-j)%2==0) continue;
			if (p[j] && p[i - j])
			{
				printf("%d=%d+%d\n", i, j, i - j);
				flag = 0;
			}
		}
		flag == 1 ? printf("found wrong number") : 1;
	}
	system("pause");
}