#include<stdio.h>
void myswap1(int x, int y);
void myswap2(int *p, int *q);
int main(void)
{
	int x = 3;
	int y = 5;
	printf("before:x=%d,y=%d\n", x, y);
	myswap1(x, y);
	printf("after:x=%d,y=%d", x, y);
	myswap2(&x, &y);
	printf("after:x=%d,y=%d", x, y);
	system("pause");
}

void myswap1(int x, int y)
{
	int z = 0;
	z = x;
	x = y;
	y = z;

}

void myswap2(int *p, int *q)
{
	int z = 0;
	z = *p;
	*p = *q;
	*q = z;
}