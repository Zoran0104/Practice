#include<stdio.h>
double loop(int a);
double loop2(int a);
double digui1(int a);

int main(void)
{
	int innum;
	printf("������һ��0-12�����֣�");
	while (scanf_s("%d", &innum) == 1)
	{
		if (innum > 12 || innum < 0)
		{
			printf("������������������������룺");
			continue;
		}
		printf("loop1:%-3.0lf,loop2:%-3.0lf,", loop(innum), loop2(innum));

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
	return 0.0;
}
