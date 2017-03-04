#include<stdio.h>
struct Famil
{
	char name[10];
	int age;
};
int main()
{
	FILE *p=NULL;
	int max = 0,min=0;
	struct Famil FAM[100];
	p=fopen("d:\\home.txt", "w");
	if (p == NULL) return -1;
	printf("请输入你的家庭成员信息：(以‘| 0’结束)\n");
	scanf("%s %d", FAM[0].name, &FAM[0].age);
	int i = 0;
	while(FAM[i].name[0]!='|')
	{
		fprintf(p, "%s %d\n", FAM[i].name, FAM[i].age);
		scanf("%s %d", FAM[++i].name, &FAM[i].age);
	}
	fclose(p);
	i = 0;
	p=fopen("d:\\home.txt", "r");
	if (p == NULL) return -1;
	while(!feof(p))
	{
		fscanf(p, "%s %d\n", FAM[i].name, &FAM[i].age);
		printf("%s %d\n", FAM[i].name, FAM[i].age);
		max = (FAM[max].age > FAM[i].age) ? max : i;
		min = (FAM[min].age > FAM[i].age) ? i : min;
		++i;
	}
	fclose(p);
	printf("年龄最大的是%s,TA的年龄是%d\n年龄最小的是%s,TA的年龄是%d\n"
		, FAM[max].name, FAM[max].age,FAM[min].name,FAM[min].age);
	system("pause");
}