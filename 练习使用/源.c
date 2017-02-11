#include<stdio.h>
#include<math.h>
int to_ten(char num[], int jz);
void to_what(int n, int mjz);
int main()
{
	while (1)
	{
		char num[100];
		int jz=0,mjz=0;
		printf("请输入一个数：");
		scanf("%s", num);
		printf("请输入这个数的进制：");
		scanf("%d", &jz);
		printf("请输入目标进制：");
		scanf("%d", &mjz);
		to_what(to_ten(num, jz), mjz);
	}
}

int to_ten(char num[], int jz)
{
	int n=0;
	int temp = 0;
	for (int i = 0;; ++i)
	{
		if (num[i] == 0)
			break;
		else ++n;
	}
	int sum=0,p;
	for (int i = 0; i != n; ++i)
	{
		if (num[i] >= 'A')
			temp = num[i] - 'A'+10;
		else temp = num[i]-48;
		p = pow(jz, n - i - 1);
		sum += temp * p;
	}
	return sum;
}

void to_what(int n, int mjz)
{
	if (mjz == 10)
		return n;
	char num[100];
	int j=0;
	while (n > mjz)
	{
		if (n%mjz > 9)
			num[j++] = n%mjz - 10 + 'A';
		else
			num[j++] = n%mjz + 48;
		n /= mjz;
	}
	if (n > 9)
		num[j] = n - 10 + 'A';
	else num[j] = n + 48;
	for (int i = j; i != -1; i--)
		putchar(num[i]);
	putchar('\n');
}
