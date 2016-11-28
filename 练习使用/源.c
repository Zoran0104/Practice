#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{
	bool inword;
	char c;
	long chars = 0;
	int words = 0;
	int lines = 0;
	int prelines = 0;
	char pre = '\n';
	inword = false;
	while ((c = getchar()) != STOP)
	{
		chars++;
		c == '\n' ? lines++ : 1;
		if (!inword && !isspace(c))
		{
			inword = true;
			words++;
		}
		if (inword&&isspace(c))
		{
			inword = false;
		}
		pre = c;
	}
	pre = '\n' ? prelines = 1 : 1;
	printf("chars=%ld,lines=%d,words=%d,prelines=%d", chars, lines, words, prelines);
	system("pause");
}
