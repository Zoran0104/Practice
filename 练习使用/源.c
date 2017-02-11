#include<stdio.h>
#include<math.h>
int to_ten(char num[], int jz);
int main()
{
	while (1)
	{
		char num[100];
		int jz;
		printf("请输入一个数：");
		scanf("%s", num);
		printf("请输入这个数的进制：");
		scanf("%d", &jz);
		to_ten(num, jz);
	}
}

int to_ten(char num[], int jz)
{
	int n=0;
	int temp = 0;
	for (int i = 0;; ++i)
	{
		if (num[i] == 0)
			break;
		else ++n;
	}
	int sum=0,p;
	for (int i = 0; i != n; ++i)
	{
		if (num[i] >= 'A')
			temp = num[i] - 'A'+10;
		else temp = num[i]-48;
		p = pow(jz, n - i - 1);
		sum += temp * p;
	}
	printf("%d\n", sum);
}
