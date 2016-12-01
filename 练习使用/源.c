#include<stdio.h>
int main(void)
{
	int i;
	for (i = 'A'; i < 'A'+26; i++)
		printf("%c", i);
	putchar('\n');
	for (i = 'Z'; i >= 'A'; i--)
		printf("%c", i);
	putchar('\n');
	system("pause");
}