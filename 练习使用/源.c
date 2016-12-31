#include<stdio.h>
#define SIZE 100
void mystrcat(char *str1, char *str2);
int main(void)
{
	char str1[100];
	char str2[100];
	gets(str1);
	gets(str2);
	mystrcat(str1, str2);
	puts(str1);
	system("pause");
}
void mystrcat(char * str1, char * str2)
{
	int i;
	for (i = strlen(str1); i < (strlen(str1) + strlen(str2)); i++)
	{
		*(str1 + i) = *str2++;
	}
	str1 = 0;
}
