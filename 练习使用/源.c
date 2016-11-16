#include<stdio.h>
int loop(int);
int digui(int);
int main(void)
{
	int thenum;
	long di;
	printf("请输入一个0~12之间的数字：");
	while (scanf_s("%d", &thenum) == 1)
	{
		if (thenum <= 0)
		{
			printf("您输入的数字小于0，请重新输入：");
			continue;
		}
		else if (thenum > 12)
		{
			printf("您输入的数字过大，请重新输入：");
			continue;
		}
		else
		{
			loop(thenum);
			di = digui(thenum);
		}
		printf("使用递归求得的值是：%ld\n", di);
	}

	system("pause");
	
}

int loop(int a)
{
	int i;
	long sum = 1;
	for (i=1; i <=a; i++)
	{
		sum *= i;
	}
	printf("使用循环求得的值是：%ld\n", sum);
	return 0;
}

long digui(int a)
{
	long sum;
	if (a >1)
	{
		sum =a*digui(a - 1);
	}
	else sum = 1;
	return sum;
}
