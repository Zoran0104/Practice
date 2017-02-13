#include<stdio.h>
#include<math.h>
int to_ten(char num[], int  jz);
void to_mjz(int n, int mjz);
int main()
{
	int num[100], jz = 0, mjz = 0;
	printf("请输入一个数：");
	scanf("%s", num);
	printf("请输入这个数的进制：");
	scanf("%d", &jz);
	printf("请输入您想要转换成的进制：");
	scanf("%d", &mjz);
	to_mjz(to_ten(num, jz), mjz);
	system("pause");
}

int to_ten(char num[], int jz)
{
	int n = 0;
	int ten_num = 0;
	for (; num[++n] != 0;);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		if (num[i] > 'A') temp = num[i] - 'A' + 10;
		else temp = num[i] - '0';
		ten_num += temp*pow(jz, n - 1 - i);
	}
	return ten_num;
}

void to_mjz(int n, int mjz)
{
	if (mjz == 10)
	{
		printf("%d", n);
		return;
	}
	int mjznum[100];
	int j = 0;
	while (n > mjz)
	{
		if (n%mjz > 9) mjznum[j++] = n%mjz + 'A' - 10;
		else mjznum[j++] = n%mjz + '0';
		n /= mjz;
	}
	if (n > 9) mjznum[j] = n + 'A' - 10;
	else mjznum[j] = n + '0';
	for (int i = j; i != -1; --i)
	{
		putchar(mjznum[i]);
	}
}