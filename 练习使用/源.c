#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	char b[100];
	int sa;
	int sb;
	int i;
	int k;
	int n=0;
	printf("������һ���ַ���");
	scanf("%s", a);
	printf("��������һ���ַ�����");
	scanf("%s", b);
	sa = strlen(a);
	sb = strlen(b);
	for (k=0;k<=sa;k++)
	{
		for (i = 0; b[i] != 0; i++)
			if (b[i] != a[k + 1])
				break;
		if (b[i] == 0)
			n++;
	}
	printf("%d", n);
	system("pause");
}
