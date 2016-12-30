#include<stdio.h>
#define SIZE 100
void mystrcpy(char *str1, char *str2);
int mystrcmp(char *str1, char *str2);
void mystrcat(char *str1, char *str2);
void mystrchr(char *str, char ch);
int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	char str[SIZE];
	char ch;
	printf("以下是第一题：\n请输入字符数组str2：");
	gets(str2);
	mystrcpy(str1, str2);
	printf("str1是：");
	puts(str1);
	printf("以下是第二题：\nstr2=%s,请输入字符数组str1：",str2);
	gets(str1);
	printf("str1与str2的比较结果：%d\n以下是第三题：", mystrcmp(str1, str2));
	mystrcat(str1, str2);
	printf("str1拼接str2后是");
	puts(str1);
	printf("以下是第四题：\n请输入str的值：");
	gets(str);
	printf("请输入含有字符的值：");
	scanf("%c", &ch);
	mystrchr(str, ch);
	system("pause");
}

void mystrcpy(char * str1, char * str2)
{
	while (*(str1++) = *(str2++))
		;
	str1 = 0;
}

int mystrcmp(char * str1, char * str2)
{
	int i;
	int a;
	char *p = str1;
	char *q = str2;
	for (i = 0; *(p+i)!=0&&*(q+i)!=0; i++)
	{
		if (*(p + i) > *(q + i))
			return 1;
		else if (*(p + i) < *(q + i))
			return -1;
	}
	if (*(p+i) != 0 && *(q+i) == 0)
		return 1;
	if (*(p+i) == 0 && *(q+i) != 0)
		return -1;
	return 0;
}

void mystrcat(char * str1, char * str2)
{
	int i;
	while (*(str1++));
	str1--;
	while ((*(str1++) = *str2, *(str2++)));
}

void mystrchr(char * str, char ch)
{
	int i;
	char *p = str;
	for(i=0;i<SIZE;i++)
		if (*(p + i) == ch)
		{
			printf("在第%d个位置", i+1);
			break;
		}
}
