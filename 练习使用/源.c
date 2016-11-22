#include<stdio.h>
int main()
{
	char char1;
	printf("enter a num you want to show the char:________\b\b\b\b\b\b\b\b");
	while (scanf_s("%d",&char1)==1)
	{
		printf("%c\n", char1);
		printf("enter a num you want to show the char:________\b\b\b\b\b\b\b\b");
	}
}