#include<stdio.h>
double loop(int a);
double loop2(int a);
double digui1(int a);
double digui2(int a);

int main(void)
{
	int innum;
	printf("请输入一个0-12的数字：");
	while (scanf_s("%d", &innum) == 1)
	{
		if (innum > 12 || innum < 0)
		{
			printf("您输入的数字有误，请重新输入：");
			continue;
		}
		printf("loop1:%-3.0lf,loop2:%-3.0lf,digui1=%-3.0lf", loop(innum), loop2(innum),digui1(innum));

	}


}

double loop(int a)
{
	double outnum = 1;
	while(a)
	{
		outnum *= a;
		a--;
	}
	return outnum;
}

double loop2(int a)
{
	double outnum = 1;
	for (; a > 0; a--)
		outnum *= a;
	return outnum;
}

double digui1(int a)
{
	double outnum=a;
	if (a > 0)
		outnum =outnum* digui1(a - 1);
	else outnum = 1;
	return outnum;
}

double digui2(int a)
{
	double sum = a;
	while (a)
	{
		sum *= digui2(a - 1);
	}
	return sum;
}
