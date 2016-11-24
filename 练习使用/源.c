#include<stdio.h>
#define SIZE 3
int main(void)
{
	int score[SIZE];
	int i,sum=0;
	double ave;
	for (i = 0; i < SIZE; i++)
		scanf_s("%d", &score[i]);
	printf("您输入的分数如下：\n");
	for (i = 0; i <SIZE; i++)
	{
		printf("%5d", score[i]);
		sum += score[i];
	}
	ave = (double)5 / 6;
	printf("\n您输入的成绩的总和为%d平均值为%.2lf", sum,ave);
	system("pause");
	
	
}