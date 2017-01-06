#include<stdio.h>
void gets_intro(struct me a[]);
void dosome(struct me a[]);
struct me
{
	char num[10];
	char name[20];
	int score[3];
};

int main(void)
{
	struct me student[10];
	gets_intro(student);
	dosome(student);
	system("pause");
}
void gets_intro(struct me a[])
{
	int i,j;
	for (i = 0; i < 10; i++)
	{
		scanf("%s", &a[i].num);
		scanf("%s", &a[i].name);
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i].score[j]);
	}
}
void dosome(struct me a[])
{
	double ave[10];
	int i,j,sum;
	double temp; 
	int b[10];
	int n;
	for (i = 0; i < 10; i++)
		b[i] = i;
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
			sum += a[i].score[j];
		ave[i] = sum / 3.0;
	}
	for (i = 0; i < 10; i++)
		{
			n = i;
			for (j = i; j < 10; j++)
			{
				if (ave[i] > ave[j])
				{
					temp = b[n];
					b[n] = b[j];
					b[j] = temp;
					temp = ave[i];
					ave[i] = ave[j];
					ave[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("学号：%s 姓名：%s 成绩1：%d 成绩2：%d 成绩3：%d 平均分：%.2lf\n", a[b[i]].num, a[b[i]].name, 
			a[b[i]].score[0], a[b[i]].score[1], a[b[i]].score[2], ave[i]);
}