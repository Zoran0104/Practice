#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{
	int words=0;
	long chars = 0;
	int lines = 0;
	int prelines = 0;
	char c;
	char pre = '\n';
	bool inword = false;
	while ((c = getchar()) != STOP)
	{
		chars++;
		c == '\n' ? lines++ :1;
		if (!inword && !isspace(c))
		{
			words++;
			inword = true;
		}
		if (inword&&isspace(c))
			inword = false;
		pre = c;
	}
	if (pre != '\n')
		prelines++;
	printf("字符数：%ld，单词数：%d，行数：%d，未完成行数：%d。", chars, words, lines, prelines);
	system("pause");
}