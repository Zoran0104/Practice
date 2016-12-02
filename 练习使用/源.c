#include<stdio.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{
	char a[50];
	char b[50];
	char c;
	int i = 0;
	int j = 0;
	printf("请输入您要筛选的字符串：以‘|’结束");
	while ((c = getchar()) != STOP)
	{
		a[i] = c;
		i++;
	}
	a[i] = '\0';
	for (i = 0; i < 50; i++)
	{
		if (a[i]>='a'&&a[i]<='z')
		{
			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	printf("a的数组里含有的字符是：%s\nb的数组里含有的字符是：%s。", a, b);
	system("pause");
}