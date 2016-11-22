#include<stdio.h>
int main(void)
{
	char fname[40];
	char sname[40];
	printf("Please enter your first name:\n");
	scanf_s("%s", fname);
	printf("Please enter your second name:\n");
	scanf_s("%s", sname);
	printf("%s,%s", fname, sname);
	system("pause");
}