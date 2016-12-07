/*#include<stdio.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{
	while (1)
	{
		char a[50];
		char b[50];
		char c;
		int i = 0;
		int j = 0;
		printf("请输入您要筛选的字符串：以‘|’结束:\n");
		while ((c = getchar()) != STOP)
		{
			a[i] = c;
			i++;
		}
		a[i] = '\0';
		for (i = 0; i < 50, a[i] != '\0'; i++)
		{
			if (islower(a[i]))
			{
				b[j] = a[i];
				j++;
			}
		}
		b[j] = '\0';
		printf("a的数组里含有的字符是：%s\nb的数组里含有的字符是：%s。\n", a, b);
	}
	system("pause");
}*/
#include<stdio.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{
	int a[100];
	int b[100];
	char c;
	while ((c = getchar()) != STOP)
	{

	}
}