#include <stdio.h>
#include <ctype.h>
#define STOP '|'
int main(void)
{
    while (1)
	{
	char a[100];
	char b[100];
	char c;
	int i = 0;
	int j = 0;
		printf("请输入您要筛选的字符串（以‘|’结束）：\n");
		while ((c = getchar()) != STOP)
		{
			a[i] = c;
			i++;
			if (i == 50)
				break;
		}
		a[i] = '\0';
		for (i = 0; i < 100,a[i]!='\0'; i++)
		{
			if (islower(a[i]))
			{
				b[j] = a[i];
				j++;
			}
		}
		b[j] = '\0';
		printf("%s", b);
	}
}
