#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	char b[100];
	int i;
	int k;
	int n=0;
	printf("������һ���ַ���");
	scanf("%s", a);
	printf("��������һ���ַ�����");
	scanf("%s", b);
	for (k=0;k<=strlen(a)-strlen(b);k++)
	{
		for (i = 0; b[i] != 0; i++)
			if (b[i] != a[k+i])
				break;
		if (b[i] == 0)
			n++;
	}
	printf("%d", n);
	system("pause");
}
