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