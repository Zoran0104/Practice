#include<stdio.h>
double loop1(int a);
double loop2(int a);
double loop3(int a);
int main(void)
{
	int num;
	printf("Please enter a number between 1 to 12:");
	while (scanf_s("%d", &num) == 1)
	{
		if (num > 12 || num <= 0) 
		{
			printf("Rewrite a number:");
			continue;
		}
		printf("loop1:%11.2lf;loop2:%11.2lf;loop3:%11.2lf",loop1(num),loop2(num),loop3(num));
	}

}
double loop1(int a)
{
	double sum=1;
	for (; a>0; a--)
	{
		sum *= a;
	}
	return sum;
}
double loop2(int a)
{
	double sum = 1;
	while (a)
	{
		sum *= a;
		a--;
	}
	return sum;
}
double loop3(int a)
{
	double sum=a;
	if (a)
		sum *= loop3(a - 1);
	else sum = 1;
	return sum;
}
