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
	printf("��������Ҫɸѡ���ַ������ԡ�|������:\n");
	while ((c = getchar()) != STOP)
	{
		a[i] = c;
		i++;
	}
	a[i] = '\0';
	for (i = 0; i < 50,a[i]!='\0'; i++)
	{
		if (islower(a[i]))
		{
			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	printf("a�������ﺬ�е��ַ��ǣ�%s\nb�������ﺬ�е��ַ��ǣ�%s��", a, b);
	system("pause");
}