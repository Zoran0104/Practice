#include<stdio.h>
#define SIZE 10;
int main(void)
{
	int score[10];
	int i,sum=0;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &score[i]);
	printf("您输入的分数如下：\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5d", score[i]);
		sum += score[i];
	}
	printf("\n您输入的成绩的总和为%d平均值为%d", sum, (double)sum /10);
	system("pause");
	
	
}