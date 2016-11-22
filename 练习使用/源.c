#include<stdio.h>
int main()
{
	int i = 2147483647;
	unsigned int j = 4294967200;
	printf("%.10d%.10d%.10d\n", i, i + 1, i + 2);
	printf("%.10d%.10d%.10d\n", j, j++, j + 2);
	getchar();
}