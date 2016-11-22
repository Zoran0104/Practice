#include<stdio.h>
int main(void)
{
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Type double has size of %zd bytes.\n", sizeof(double));
	printf("Type char has size of %zd bytes.\n", sizeof(char));
	printf("Type long long has size of %zd bytes.\n", sizeof(long long));
	printf("Type long double has size of %zd bytes.", sizeof(long double));
	getchar();
}