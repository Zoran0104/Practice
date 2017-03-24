#include<stdbool.h>
#include<stdio.h>
#include<string.h>
int Get_Length();
void Find_Base_Num(char num[]);
void Find_Base_Name(char num[]);
void Find_Base_Tel(char num[]);
void Find_Base_Sex(char num[]);
void Find_Base_Birth(struct Stu_birth b, struct Stu_birth c);
void Delete_Main();
void Delete_Base_Num();
void Add_One_info();
bool Check_Num(char a[]);
bool Check_Name(char a[]);
bool Check_Sex(char a[]);
bool Check_Tel(char a[]);
bool Check_Birth(int years, int months, int days);
void Get_info();
void Print_Only1_info(struct Stu_info a);
void Print_info();

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
	char sex[20];
	struct Stu_birth birth;
	char Tel[11];
};
struct Stu_info Info[1000];
int main()
{
	Get_info();
}

int Get_Length()
{
	int i=0;
	for (; Info[i].sex == "T" || Info[i].sex == "F"; ++i);
	return i;
}

void Find_Base_Num(char num[])
{
	int k;
	int flag = 0;
	int n = Get_length();
	for (int i = 0; i<n ; ++i)
	{
		for (int j = 0; j <= strlen(Info[i].cNum) - strlen(num); ++j)
		{
			for (k = 0; num[k] != 0; ++k)
			{
				if (Info[i].cNum[j + k] != num[k])
					break;
			}
			if (num[k] == 0)
			{
				Print_Only1_info(Info[i]);
				break;
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("没有从数据中找到相应的结果！");
}
void Find_Base_Name(char name[])
{
	int k;
	int flag = 0;
	int n = Get_length();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= strlen(Info[i].cName) - strlen(name); ++j)
		{
			for (k = 0; name[k] != 0; ++k)
			{
				if (Info[i].cName[j + k] != name[k])
					break;
			}
			if (name[k] == 0)
			{
				flag = 1;
				Print_Only1_info(Info[i]);
				break;
			}
		}
	}
	if (flag == 0)
		printf("没有根据搜索条件找到结果！");
}

void Find_Base_Tel(char Tel[])
{
	int k;
	int flag = 0;
	int n = Get_length();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= strlen(Info[i].Tel) - strlen(Tel); ++j)
		{
			for (k = 0; Tel[k] != 0; ++k)
			{
				if (Info[i].Tel[j + k] != Tel[k])
					break;
			}
			if (Tel[k] == 0)
			{
				flag = 1;
				Print_Only1_info(Info[i]);
				break;
			}
		}
	}
	if (flag == 0)
		printf("没有根据搜索条件找到结果！");
}

void Find_Base_Sex(char Sex[])
{
	int flag = 0;
	int n = Get_length();
	for (int i = 0; i < n; ++i)
	{
		if (Info[i].sex[0] == Sex[0])
		{
			flag = 1;
			Print_Only1_info(Info[i]);
		}
	}
	if (flag == 0)
		printf("没有根据搜索条件找到结果！");
}
void Find_Base_Birth(struct Stu_birth b, struct Stu_birth c)
{
	int flag = 0;
	int n = Get_length();
	for (int i = 0; i < n; ++i)
	{
		if (Info[i].birth.years > b.years&&Info[i].birth.years < c.years)
		{
			flag = 1;
			Print_Only1_info(Info[i]);
			continue;
		}
		else if (Info[i].birth.years == b.years)
		{
			if (Info[i].birth.months > b.months)
			{
				Print_Only1_info(Info[i]);
				flag = 1;
				continue;
			}
			else if (Info[i].birth.months == b.months&&Info[i].birth.days >= b.days)
			{
				Print_Only1_info(Info[i]);
				flag = 1;
				continue;
			}
		}
		else if (Info[i].birth.years == c.years)
		{
			if (Info[i].birth.months < c.months)
			{
				Print_Only1_info(Info[i]);
				flag = 1;
				continue;
			}
			else if (Info[i].birth.months == c.months&&Info[i].birth.days <= b.days)
			{
				Print_Only1_info(Info[i]);
				flag = 1;
				continue;
			}
		}
	}
	if (flag == 0)
		printf("没有根据搜索条件找到结果！");
}
void Delete_Main()
{
	int i;
	printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("     1.根据学号删除\n");
	printf("     2.根据姓名删除\n");
	printf("     3.根据手机号码删除\n");
	printf("     4.根据出生日期删除\n");
	printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("请选择您的删除方式：\n");
	start:
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		Delete_Base_Num();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		printf("您输入的选择无效，请重新输入：");
		goto start;
	}



}
void Delete_Base_Num()
{
	printf("请输入要删除的学号：");
	char Num[100];
	scanf("%s", Num);
	int n = Get_Length();
	int i;
	for (i= 0; i < n; ++i)
	{
		
	}
}
void Add_One_info()
{
	int i =	Get_Length();
	printf("请输入这位同学的学号：");
	while (scanf("%s", Info[i].cNum) == 1 && !Check_Num(Info[i].cNum))
		printf("您输入的学号不符合要求，请重新输入：");
	printf("请输入这位同学的姓名：");
	while (scanf("%s", Info[i].cName) == 1 && !Check_Name(Info[i].cName))
		printf("您输入的姓名不符合要求，请重新输入：");
	printf("请输入这位同学的性别：");
	while (scanf("%s", Info[i].sex) && !Check_Sex(Info[i].sex))
		printf("您输入的性别不符合要求，请重新输入：");
	printf("请输入这位同学的出生年月日：（请按xxxx-xx-xx格式输入）");
	while (scanf("%d-%d-%d", &Info[i].birth.years,
		&Info[i].birth.months,
		&Info[i].birth.days) && !Check_Birth(Info[i].birth.years,
			Info[i].birth.months, Info[i].birth.days))
		printf("您输入的日期不符合要求，请重新输入：");
	printf("请输入这位同学的手机号码：");
	while (scanf("%s", Info[i].Tel) && !Check_Tel(Info[i].Tel))
		printf("您输入的手机号码不符合要求，请重新输入：");
}
bool Check_Num(char a[])
{
	if (strlen(a) != 10)
		return false;
	for (int i = 0; a[i] != 0; ++i)
		if (a[i] > '9' || a[i] < '0')
			return false;
	return true;
}

bool Check_Name(char a[])
{
	if (strlen(a) > 50)
		return false;
	for (int i = 0; a[i] != 0; ++i)
		if (a[i] > 'z' || a[i] < 'A')
			return false;
	return true;
}

bool Check_Sex(char c[])
{
	if (c[0] != 'F'&&c[0] != 'M')
		return false;
	return true;
}

bool Check_Tel(char a[])
{
	if (strlen(a) != 11)
		return false;
	for (int i = 0; a[i] != 0; ++i)
		if (a[i] > '9' || a[i] < '0')
			return false;
	return true;
}

bool Check_Birth(int years, int months, int days)
{
	if (years < 1900 || years>2100 || months > 12 || months < 1 || days < 1 || days>32)
		return false;
	else if ((months == 1 || months == 3 || months == 5 ||
		months == 7 || months == 8 || months == 10 || months == 12) && days > 31)
		return false;
	else if ((months == 4 || months == 6 || months == 9 || months == 11) && days > 30)
		return true;
	else if (months == 2)
	{
		if ((years % 4 == 0) && (years % 100 != 0) || (years % 400 == 0) && days > 29)
			return false;
		else if (days > 28)
			return false;
	}
	return true;
}

void Get_info()
{
	printf("请输入您要录入的信息的人数：");
	int stunum = 0;
	while (scanf("%d", &stunum) == 1 && (stunum <= 0 || stunum > 1000))
		printf("您输入的数小于0或大于1000，请重新输入：");

	for (int i = 0; i < stunum; ++i)
	{
		printf("请输入第%d位同学的学号：", i + 1);
		while (scanf("%s", Info[i].cNum) == 1 && !Check_Num(Info[i].cNum))
			printf("您输入的学号不符合要求，请重新输入：");
		printf("请输入第%d位同学的姓名：", i + 1);
		while (scanf("%s", Info[i].cName) == 1 && !Check_Name(Info[i].cName))
			printf("您输入的姓名不符合要求，请重新输入：");
		printf("请输入第%d位同学的性别：", i + 1);
		while (scanf("%s", Info[i].sex) && !Check_Sex(Info[i].sex))
			printf("您输入的性别不符合要求，请重新输入：");
		printf("请输入第%d位同学的出生年月日：（请按xxxx-xx-xx格式输入）", i + 1);
		while (scanf("%d-%d-%d", &Info[i].birth.years,
			&Info[i].birth.months,
			&Info[i].birth.days) && !Check_Birth(Info[i].birth.years,
				Info[i].birth.months, Info[i].birth.days))
			printf("您输入的日期不符合要求，请重新输入：");
		printf("请输入第%d位同学的手机号码：", i + 1);
		while (scanf("%s", Info[i].Tel) && !Check_Tel(Info[i].Tel))
			printf("您输入的手机号码不符合要求，请重新输入：");
	}
}

void Print_Only1_info(struct Stu_info a)
{
	printf("%s %s %s %d-%d-%d %s", a.cNum, a.cName, a.sex, a.birth.years,
		a.birth.months, a.birth.days, a.Tel);
}

void Print_info()
{
	int i = 0;
	for (i = 0; Info[i].sex == "T" || Info[i].sex == "F"; ++i)
	{
		Print_Only1_info(Info[i]);
	}
	if (i == 0)
	{
		printf("系统中没有任何一条数据。");
	}
}


