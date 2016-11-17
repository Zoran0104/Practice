#include<stdio.h>
#include<math.h>
long loop1(int);
long loop2(int);
long loop3(int);
long digui(int);

int main(void)
{
	int thenum;
	printf("请输入一个小于12的数字：");
	while (scanf_s("%d", &thenum) == 1)
	{
		if (thenum <= 0 || thenum > 15)
		{
			printf("您输入的数字不符合规范，请重新输入：");
			continue;
		}
		printf("loop1:%ld,loop2:%ld,loop3:%ld\n"
			"digui1:%ld,digui2:",loop1(thenum),loop2(thenum),loop3(thenum),digui(thenum));
    }
}

long loop1(int a)
{
	int i = 1;
	long sum=1;
	while (i <= a)
	{
		sum *= i;
		i++;
	}
	return sum;
}

long loop2(int a)
{
	int i=1;
	long sum=1;
	do {
		sum *= i;
		i++;
	} while (i <= a);
	return sum;
}

long loop3(int a)
{
	int i;
	long sum=1;
	for (i = 1; i <= a; i++)
	{
		sum *= i;
	}
	return sum;
}

long digui(int a)
{
	long sum=a;
	if (a>0)
	{
		sum *= digui(a - 1);
	}
	else sum = 1;
	return sum;
}

