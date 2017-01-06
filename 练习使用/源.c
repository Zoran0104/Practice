四、实验结果与分析（含程序、数据记录及分析和实验总结等）：


#include<stdio.h>
#include<math.h>
void get_x_y(struct ex2 a[]);
void max_x_y(struct ex2 a[]);
struct ex2
{
	int x;
	int y;
};
int main(void)
{
	struct ex2 xy[10];
	printf("请输入坐标值，x与y空格，一个坐标后回车：");
	get_x_y(xy);
	max_x_y(xy);

	system("pause");
}

void get_x_y(struct ex2 a[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i].x);
		scanf("%d", &a[i].y);
	}
}

void max_x_y(struct ex2 a[])
{
	double num[10];
	int i, j = 0;
	double max;
	for (i = 0; i < 10; i++)
	{
		num[i] = sqrt(a[i].x*a[i].x + a[i].y*a[i].y);
	}
	max = num[0];
	for (i = 1; i < 10; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			j = i;
		}
	}
	printf("最远的坐标为(%d,%d)，距离为%.2f", a[j].x, a[j].y, max);
}


