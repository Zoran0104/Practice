#include<stdio.h>
int fun(int n);
int main()
{
	for (int i = 1; i != 13; ++i)
		printf("%d!=%d\n", i, fun(i));
	while (1);

}

int fun(int n)
{
	int i = n;
	if (n != 1)
		i *= fun(n - 1);
	if (n == 1)
		return 1;
	return i;
}
