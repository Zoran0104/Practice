#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
void home();
void Add_info();
void Add_One_info();
void Find_Home();
void Find_Base_Num();
void Find_Base_Name();
void Find_Base_Tel();
void Find_Base_Sex();
void Find_Base_Birth();
void Delete_Home();
void Delete_Base_Num();
void Delete_Base_Name();
void Delete_Base_Tel();
void Delete_Base_Birth();
void Sort_Home();
void Sort_Base_Num();
void Sort_Base_Name();
void Sort_Base_Tel();
void Sort_Base_Sex();
void Sort_Base_Birth();
void print_Info();
void print_one_info(struct Stu_info info);
void title();
bool Check_Num(char a[]);
bool Check_Name(char a[]);
bool Check_Sex(char a[]);
bool Check_Tel(char a[]);
bool Check_Birth(int years, int months, int days);
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

void home()
{
	system("cls");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("      1.批量增加信息\n");
	printf("      2.增加一条信息\n");
	printf("      3.查找信息\n");
	printf("      4.删除信息\n");
	printf("      5.信息排序\n");
	printf("      6.输出信息\n");
	printf("      0.退出程序\n");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("       请输入您要进行的操作：");
	int i = 0;
start:
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Add_info();
		break;
	case 2:
		Add_One_info();
		break;
	case 3:
		Find_Home();
		break;
	case 4:
		Delete_Home();
		break;
	case 5:
		Sort_Home();
		break;
	case 6:
		print_Info();
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Add_info()
{
	system("cls");
	struct Stu_info Info[10000];
	printf("请输入您要录入的信息的人数：");
	int stunum = 0;
	int n = 0;
	while (scanf("%d", &stunum) == 1 && (stunum <= 0 || stunum > 1000))
		printf("您输入的数小于等于0或大于1000，请重新输入：");
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
	FILE *fp = fopen("D:\\information.txt", "a");
	if (fp == NULL)
		printf("录入数据发生错误！");
	for (int i = 0; i < stunum; ++i)
	{
		fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, Info[i].birth.years, Info[i].birth.months, Info[i].birth.days,
			Info[i].Tel);
	}
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}


void Add_One_info()
{
	system("cls");
	struct Stu_info Info;
	int n = 0;
	printf("请输入这位同学的学号：");
	while (scanf("%s", Info.cNum) == 1 && !Check_Num(Info.cNum))
		printf("您输入的学号不符合要求，请重新输入：");
	printf("请输入这位同学的姓名：");
	while (scanf("%s", Info.cName) == 1 && !Check_Name(Info.cName))
		printf("您输入的姓名不符合要求，请重新输入：");
	printf("请输入这位同学的性别：");
	while (scanf("%s", Info.sex) && !Check_Sex(Info.sex))
		printf("您输入的性别不符合要求，请重新输入：");
	printf("请输入这位同学的出生年月日：（请按xxxx-xx-xx格式输入）");
	while (scanf("%d-%d-%d", &Info.birth.years,
		&Info.birth.months,
		&Info.birth.days) && !Check_Birth(Info.birth.years,
			Info.birth.months, Info.birth.days))
		printf("您输入的日期不符合要求，请重新输入：");
	printf("请输入这位同学的手机号码：");
	while (scanf("%s", Info.Tel) && !Check_Tel(Info.Tel))
		printf("您输入的手机号码不符合要求，请重新输入：");

	FILE *fp = fopen("D:\\information.txt", "a");
	if (fp == NULL)
		printf("录入数据发生错误！");
	fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info.cNum, Info.cName,
		Info.sex, Info.birth.years, Info.birth.months, Info.birth.days,
		Info.Tel);
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Find_Home()
{
	system("cls");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("      1.学号模糊查找\n");
	printf("      2.姓名模糊查找\n");
	printf("      3.根据生日查找\n");
	printf("      4.手机号码模糊查找\n");
	printf("      5.性别查找\n");
	printf("      6.回到首页\n");
	printf("      0.退出程序\n");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("       请输入您要进行的操作：");
	int i = 0;
start:
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Base_Num();
		break;
	case 2:
		Find_Base_Name();
		break;
	case 3:
		Find_Base_Birth();
		break;
	case 4:
		Find_Base_Tel();
		break;
	case 5:
		Find_Base_Sex();
		break;
	case 6:
		home();
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Delete_Home()
{
	system("cls");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("      1.按学号删除\n");
	printf("      2.按姓名删除\n");
	printf("      3.按生日删除\n");
	printf("      4.按手机号码删除\n");
	printf("      5.回到首页\n");
	printf("      0.退出程序\n");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("       请输入您要进行的操作：");
	int i = 0;
start:
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Delete_Base_Num();
		break;
	case 2:
		Delete_Base_Name();
		break;
	case 3:
		Delete_Base_Birth();
		break;
	case 4:
		Delete_Base_Tel();
		break;
	case 5:
		home();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Home()
{

	system("cls");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("      1.按照学号排序\n");
	printf("      2.按照姓名排序\n");
	printf("      3.按照生日排序\n");
	printf("      4.按照手机号码排序\n");
	printf("      5.按照性别排序\n");
	printf("      6.回到首页\n");
	printf("      0.退出程序\n");
	printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("       请输入您要进行的操作：");
	int i = 0;
start:
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Sort_Base_Num();
		break;
	case 2:
		Sort_Base_Name();
		break;
	case 3:
		Sort_Base_Birth();
		break;
	case 4:
		Sort_Base_Tel();
		break;
	case 5:
		Sort_Base_Sex();
		break;
	case 6:
		home();
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Base_Num()
{
	system("cls");
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	struct Stu_info temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(Info[i].cNum, Info[j].cNum) > 0)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; ++i)
	{
		print_one_info(Info[i]);
	}
	printf("【1】查找数据  【2】添加数据  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Add_info();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Base_Name()
{
	system("cls");
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	struct Stu_info temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(Info[i].cName, Info[j].cName) > 0)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; ++i)
	{
		print_one_info(Info[i]);
	}
	printf("【1】查找数据  【2】添加数据  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Add_info();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Base_Tel()
{
	system("cls");
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	struct Stu_info temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(Info[i].Tel, Info[j].Tel) > 0)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; ++i)
	{
		print_one_info(Info[i]);
	}
	printf("【1】查找数据  【2】添加数据  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Add_info();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Base_Sex()
{
	system("cls");
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	struct Stu_info temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(Info[i].sex, Info[j].sex) > 0)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; ++i)
	{
		print_one_info(Info[i]);
	}
	printf("【1】查找数据  【2】添加数据  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Add_info();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Sort_Base_Birth()
{
	system("cls");
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	struct Stu_info temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (Info[i].birth.years>Info[j].birth.years)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
			else if (Info[i].birth.years == Info[j].birth.years&&Info[i].birth.months >
				Info[j].birth.months)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
			else if (Info[i].birth.years == Info[j].birth.years&&Info[i].birth.months ==
				Info[j].birth.months&&Info[i].birth.days>Info[i].birth.days)
			{
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; ++i)
	{
		print_one_info(Info[i]);
	}
	printf("【1】查找数据  【2】添加数据  【3】回到首页   【4】查看所有数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Add_info();
		break;
	case 3:
		home();
		break;
	case 4:
		print_Info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void print_Info()
{
	system("cls");
	int n;
	struct Stu_info Info[10000];
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int i = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, &Info[i].birth.years, &Info[i].birth.months, &Info[i].birth.days,
			Info[i].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++i;
	}
	fclose(fp);
	title();
	for (int j = 0; j < i; ++j)
	{
		printf("%d.  ", j + 1);
		print_one_info(Info[j]);
	}
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void print_one_info(struct Stu_info info)
{
	printf("%s %s %s %d-%d-%d %s\n", info.cNum, info.cName, info.sex, info.birth.years, info.birth.months,
		info.birth.days, info.Tel);
}

void title()
{
	printf("序号  学号  姓名 性别  生日  手机号码\n");
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

void Find_Base_Num()
{
	system("cls");
	struct Stu_info Info[10000];
	char num[15];
	printf("请输入您想查找的学号：");
	scanf("%s", num);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	title();
	int m = 0;
	for (int i = 0; i<n; ++i)
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
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}
void Find_Base_Name()
{
	system("cls");
	struct Stu_info Info[10000];
	char name[15];
	printf("请输入您想查找的名字：");
	scanf("%s", name);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	for (int i = 0; i<n; ++i)
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
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Find_Base_Tel()
{
	system("cls");
	struct Stu_info Info[10000];
	char tel[15];
	printf("请输入您想查找的电话号码：");
	scanf("%s", tel);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j <= strlen(Info[i].Tel) - strlen(tel); ++j)
		{
			for (k = 0; tel[k] != 0; ++k)
			{
				if (Info[i].Tel[j + k] != tel[k])
					break;
			}
			if (tel[k] == 0)
			{
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Find_Base_Sex()
{
	system("cls");
	struct Stu_info Info[10000];
	char sex[3];
	printf("请输入您想筛选的性别：");
	scanf("%s", sex);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	for (int i = 0; i<n; ++i)
	{
		if (Info[i].sex[0] == sex[0])
		{
			printf("%d.  ", m++ + 1);
			print_one_info(Info[i]);
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}
void Find_Base_Birth()
{
	system("cls");
	struct Stu_info Info[10000];
	struct Stu_birth b;
	struct Stu_birth c;
	printf("请输入您想搜索的起始日期：(按照xxxx-xx-xx格式输入)");
	scanf("%d-%d-%d", &b.years, &b.months, &b.days);
	printf("请输入您想搜索的终止日期：(按照xxxx-xx-xx格式输入)");
	scanf("%d-%d-%d", &c.years, &c.months, &c.days);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	title();
	for (int i = 0; i<n; ++i)
	{
		if (Info[i].birth.years > b.years&&Info[i].birth.years < c.years)
		{
			printf("%d.  ", m++ + 1);
			print_one_info(Info[i]);
			continue;
		}
		else if (Info[i].birth.years == b.years)
		{
			if (Info[i].birth.months > b.months)
			{
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
			else if (Info[i].birth.months == b.months&&Info[i].birth.days >= b.days)
			{
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
		}
		else if (Info[i].birth.years == c.years)
		{
			if (Info[i].birth.months < c.months)
			{
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
			else if (Info[i].birth.months == c.months&&Info[i].birth.days <= b.days)
			{
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Delete_Base_Num()
{
	system("cls");
	struct Stu_info Info[10000];
	char num[15];
	int address[10000];
	printf("请输入您想删除的学号：");
	scanf("%s", num);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	title();
	int m = 0;
	for (int i = 0; i<n; ++i)
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
				address[m] = i;
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("请问您要删除序号为几的数据？");
	scanf("%d", &k);
	for (int i = address[k - 1]; i < n - 1; ++i)
	{
		Info[i] = Info[i + 1];
	}
	fp = fopen("D:\\information.txt", "w");
	if (fp == NULL)
		printf("录入数据发生错误！");
	for (int i = 0; i < n - 1; ++i)
	{
		fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, Info[i].birth.years, Info[i].birth.months, Info[i].birth.days,
			Info[i].Tel);
	}
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}
void Delete_Base_Name()
{
	system("cls");
	struct Stu_info Info[10000];
	char name[15];
	int address[10000];
	printf("请输入您想删除的名字：");
	scanf("%s", name);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	for (int i = 0; i<n; ++i)
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
				address[m] = i;
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("请问您要删除序号为几的数据？");
	scanf("%d", &k);
	for (int i = address[k - 1]; i < n - 1; ++i)
	{
		Info[i] = Info[i + 1];
	}
	fp = fopen("D:\\information.txt", "w");
	if (fp == NULL)
		printf("录入数据发生错误！");
	for (int i = 0; i < n - 1; ++i)
	{
		fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, Info[i].birth.years, Info[i].birth.months, Info[i].birth.days,
			Info[i].Tel);
	}
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

void Delete_Base_Tel()
{
	system("cls");
	struct Stu_info Info[10000];
	char tel[15];
	int address[10000];
	printf("请输入您想删除的电话号码：");
	scanf("%s", tel);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j <= strlen(Info[i].Tel) - strlen(tel); ++j)
		{
			for (k = 0; tel[k] != 0; ++k)
			{
				if (Info[i].Tel[j + k] != tel[k])
					break;
			}
			if (tel[k] == 0)
			{
				address[m] = i;
				printf("%d.  ", m++ + 1);
				print_one_info(Info[i]);
				break;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("请问您要删除序号为几的数据？");
	scanf("%d", &k);
	for (int i = address[k - 1]; i < n - 1; ++i)
	{
		Info[i] = Info[i + 1];
	}
	fp = fopen("D:\\information.txt", "w");
	if (fp == NULL)
		printf("录入数据发生错误！");
	for (int i = 0; i < n - 1; ++i)
	{
		fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, Info[i].birth.years, Info[i].birth.months, Info[i].birth.days,
			Info[i].Tel);
	}
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}


void Delete_Base_Birth()
{
	system("cls");
	struct Stu_info Info[10000];
	int address[10000];
	struct Stu_birth b;
	struct Stu_birth c;
	printf("请输入您想删除的起始日期：(按照xxxx-xx-xx格式输入)");
	scanf("%d-%d-%d", &b.years, &b.months, &b.days);
	printf("请输入您想删除的终止日期：(按照xxxx-xx-xx格式输入)");
	scanf("%d-%d-%d", &c.years, &c.months, &c.days);
	int k;
	FILE *fp = fopen("D:\\information.txt", "r");
	if (fp == NULL)
		printf("关联文件失败！");
	int n = 0;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s %s %d-%d-%d %s\n", Info[n].cNum, Info[n].cName,
			Info[n].sex, &Info[n].birth.years, &Info[n].birth.months, &Info[n].birth.days,
			Info[n].Tel);            //起初这里每处都用了i++ 所以同一句不应该对同一个变量同时使用多次i++操作
		++n;
	}
	fclose(fp);
	int m = 0;
	title();
	for (int i = 0; i<n; ++i)
	{
		if (Info[i].birth.years > b.years&&Info[i].birth.years < c.years)
		{
			address[m] = i;
			printf("%d.  ", m++ + 1);
			print_one_info(Info[i]);
			continue;
		}
		else if (Info[i].birth.years == b.years)
		{
			if (Info[i].birth.months > b.months)
			{
				address[m] = i;
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
			else if (Info[i].birth.months == b.months&&Info[i].birth.days >= b.days)
			{
				address[m] = i;
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
		}
		else if (Info[i].birth.years == c.years)
		{
			if (Info[i].birth.months < c.months)
			{
				address[m] = i;
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
			else if (Info[i].birth.months == c.months&&Info[i].birth.days <= b.days)
			{
				address[m] = i;
				printf("%d.  ", m++);
				print_one_info(Info[i]);
				continue;
			}
		}
	}
	if (m == 0)
		printf("没有从数据中找到相应的结果！");
	printf("请问您要删除序号为几的数据？");
	scanf("%d", &k);
	for (int i = address[k - 1]; i < n - 1; ++i)
	{
		Info[i] = Info[i + 1];
	}
	fp = fopen("D:\\information.txt", "w");
	if (fp == NULL)
		printf("录入数据发生错误！");
	for (int i = 0; i < n - 1; ++i)
	{
		fprintf(fp, "%s %s %s %d-%d-%d %s\n", Info[i].cNum, Info[i].cName,
			Info[i].sex, Info[i].birth.years, Info[i].birth.months, Info[i].birth.days,
			Info[i].Tel);
	}
	fclose(fp);
	printf("【1】查找数据  【2】数据排序  【3】回到首页   【4】批量增加数据 【0】退出程序\n请输入您要继续的操作：");
start:
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Find_Home();
		break;
	case 2:
		Sort_Home();
		break;
	case 3:
		home();
		break;
	case 4:
		Add_info();
		break;
	default:
		printf("您输入的序号无效，请重新输入：");
		goto start;
	}
}

int main()
{
	FILE *fp = NULL;
	fp = fopen("D:\\information.txt", "a");
	fclose(fp);
	home();
}
