#include<stdio.h>
int loop(int);
int digui(int);
int main(void)
{
	int thenum;
	long di;
	printf("������һ��0~12֮������֣�");
	while (scanf_s("%d", &thenum) == 1)
	{
		if (thenum <= 0)
		{
			printf("�����������С��0�����������룺");
			continue;
		}
		else if (thenum > 12)
		{
			printf("����������ֹ������������룺");
			continue;
		}
		else
		{
			loop(thenum);
			di = digui(thenum);
		}
		printf("ʹ�õݹ���õ�ֵ�ǣ�%ld\n", di);
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
	printf("ʹ��ѭ����õ�ֵ�ǣ�%ld\n", sum);
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
