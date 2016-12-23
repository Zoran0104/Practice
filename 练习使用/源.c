#include<stdio.h>
int jia(int x, int y);
int jian(int x, int y);
int cheng(int x, int y);
int chu(int x, int y);
int main(void)
{
	while (1)
	{
		int x;
		int y;
		scanf("%d", &x);
		scanf("%d", &y);
		jia(x, y);
		jian(x, y);
		cheng(x, y);
		chu(x, y);
	}
}

int jia(int x, int y)
{
	printf("两个数相加的结果是：%d\n", x + y);
}

int jian(int x, int y)
{
	printf("两个数相减的结果为%d\n", x - y);
	return 0;
}

int cheng(int x, int y)
{
	printf("两个数相乘的结果为%d\n", x*y);
}

int chu(int x, int y)
{
	if (y)
		printf("两个数相除的结果为%.2lf\n", (double)x / (double)y);
	else printf("0不能作除数。\n");
}
