#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	char b[100];
	int i;
	printf("������һ���ַ���");
	scanf("%s", a);
	printf("��������һ���ַ�����");
	scanf("%s", b);
	for (i = 1; i <= strlen(a); i++)
	{
		if(strncmp(a,b,5)==0)
	}
}
#include<stdio.h>
#include<string.h>
int main(void)
{
	while (1)
	{
		char a[100];
		char b[100];
		int i;
		printf("������һ���ַ�����");
		scanf_s("%s", a, 100);
		for (i = 0; i < strlen(a); i++)
		{
			b[i] = a[strlen(a) - 1 - i];
		}
		b[i] = '\0';
		if (strcmp(a, b) == 0)
			printf("��������ַ����ǻ����ַ�����\n");
		else printf("��������ַ������ǻ����ַ�����\n");
	}

}