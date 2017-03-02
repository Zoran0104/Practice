#include<stdio.h>
#include<stdbool.h>
void Prime(bool *p, int n);
int main()
{
	bool *p;
	int n;
	printf("Please enter the max number you wanted:");
	scanf("%d", &n);
	p = (bool *)malloc(sizeof(bool)*n);
	Prime(p, n);
	system("pause");
}
void Prime(bool *p, int n)
{
	p[1] = p[0] = false;
	for (int i = 2; i <= n; ++i)
		p[i] = true;
	for (int i = 2; i*i <= n;++i)
		for (int j = i*i; j <= n; ++j)
			if (p[j])
				if (j%i == 0)
					p[j] = false;
	for (int i = 2; i <= n; ++i)
		if (p[i])
			printf("%5d", i);

}