#include<stdio.h>
int main(void)
{
	int i;
	int a[10];
	int max;
	int temp=0;
	int tempnum;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	max = a[0];
	for (i = 1; i < 10; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			temp = i;
		}
	}
	printf("max=%d\n", max);
	tempnum = a[temp];
	a[temp] = a[9];
	a[9] = tempnum;
	printf("重新排序后的数组为：");
	for (i = 0; i < 10; i++)
		printf("%-3d", a[i]);
	system("pause");
}