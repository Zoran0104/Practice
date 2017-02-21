#include<stdio.h>
#include<stdbool.h>
void Prime(bool a[], int num);
int main()
{
	printf("Please enter the number you entered:");
	int num = 0;
	scanf("%d", &num);
	bool *p = 0;
	p = (bool *)malloc(sizeof(bool)*num);
	Prime(p, num);
	system("pause");
}

void Prime(bool a[], int num)
{
	a[0] = a[1] = false;
	for (int i = 2; i <= num; ++i)
		a[i] = true;
	for (int i = 2; i*i <= num; ++i)
	{
		if (a[i])
			for (int j = i*i; j <= num; ++j)
				if (j%i == 0)
					a[j] = false;
	}
	for (int i = 6; i <= num; i += 2)
	{
		for (int j = 2; j < i / 2; ++j)
		{
			if (a[j] && a[i - j])
			{
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
		}
	}
}
