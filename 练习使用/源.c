#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	char b[100];
	int i;
	int j;
	int min;
	printf("������һ�������ַ�����");
	gets(a);
	printf("��������һ�������ַ�����");
	gets(b);
	strcat(a, b);
	for (i=0;i<=strlen(a);i++)
	{
		min = a[i];
		for (j = i; j <strlen(a); j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				a[j] = a[i];
				a[i] = min;
			}
		}
	}
	puts(a);
	system("pause");
}
