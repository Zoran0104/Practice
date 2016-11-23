#include<stdio.h>
void replace(int *a, int *b);
int main(void) {
	int a, b;
	scanf_s("%d%d", &a, &b);
	replace(&a, &b);
	printf("%d %d", a, b);
	system("pause");
}
void replace(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}