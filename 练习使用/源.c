#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
void Find();
bool Check_Num(char a[]);
bool Check_Name(char a[]);
void Get_info();
struct Stu_birth
{
	int years;
	int months;
	int days;
};
struct Stu_info
{
	char cNum[20];
	char cName[10];
	char sex;
	struct Stu_birth birth;
	char Tel[11];
};
typedef struct Stu_info info;
int main()
{
		
}

bool Check_Num(char a[])
{
	for (int i = 0; a[i] != 0; ++i)
		if (a[i] > '9'&&a[i] < '0')
			return false;
	return true;
}

bool Check_Name(char a[])
{
	for(int i=0;a[i]!=0;++i)
		if(a[])
	return false;
}

void Get_info()
{
	printf("请输入您要录入的信息的人数：");
	int stunum = 0;
	while (scanf("%d", &stunum) == 1 && stunum <= 0)
		printf("您输入的数小于0，请重新输入：");
	info Info[1000];
	for (int i = 0; i < stunum; ++i)
	{
		pritnf("请输入第%d位同学的学号：", i + 1);
		while (scanf("%s", Info[i].cNum) == 1 && !Check_Num(Info[i].cNum))
			printf("您输入的学号不符合要求，请重新输入：");
		pritnf("请输入第%d位同学的姓名：", i + 1);
		while (scanf("%s", Info[i].cName) == 1 && !Check_Name(Info[i].cName))
			printf("您输入的学号不符合要求，请重新输入：");
	}
}
