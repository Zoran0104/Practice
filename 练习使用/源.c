#include<stdio.h>
double loop1(int a);
double loop2(int a);
double loop3(int a);
double digui(int a);
int main(void)
{
	int a;
	printf("Please enter a num to loop:");
	while (scanf_s("%d", &a) == 1)
	{
		printf("loop1:%-20.2lf,loop:%-20.2lf,loop3:%-20.2lf,loop4:%-20.2lf\n", loop1(a), loop2(a), loop3(a), digui(a));
		printf("Please enter a num to loop:");
	}
	
}
double loop1(int a)
{
	double i=1;
	while (a > 0)
	{
		i *= a;
		a--;
	}
	return i;
}
double loop2(int a)
{
	int i;
	double sum=1;
	for (i = 1; i <= a; i++)
	{
		sum *= i;
	}
	return sum;
}
double loop3(int a)
{
	double sum=1;
	do
	{
		sum *= a;
		a--;
	} while (a > 0);
	return sum;
}
double digui(int a)
{
	double sum=a;
	if (a > 0)
		sum *= digui(a - 1);
	else sum = 1;
	return sum;
}