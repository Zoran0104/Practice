#include<stdio.h>
#include<math.h>
int to_ten(char num[], int yjz);
void to_mjz(int n, int mjz);
int main()
{
	char num[100];
	int yjz = 0, mjz = 0;
	scanf("%s", num);
	scanf("%d%d", &yjz,&mjz);
	to_mjz(to_ten(num, yjz), mjz);
	system("pause");
}

int to_ten(char num[], int yjz)
{
	int n = 0;
	for (; num[++n] != 0;);
	int ten_num=0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		if (num[i] >= 'A')temp = num[i] - 'A' + 10;
		else temp = num[i] - '0';
		ten_num += temp * pow(yjz, n - 1 - i);
	}
	return ten_num;
}

void to_mjz(int n, int mjz)
{
	int num[100];
	int j = 0;
	if (mjz == 10)
	{
		printf("%d", n);
		return;
	}
	while (n / mjz)
	{
		int temp = n%mjz;
		num[j++] = (temp > 9) ? temp + 'A' - 10 : temp + '0';
		n /= mjz;
	}
	num[j] = (n%mjz > 9) ? n % mjz + 'A' - 10 : n % mjz + '0';
	for (int i = j; i != -1; --i)
	{
		printf("%c", num[i]);
	}
}
