/*#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '@'
int main(void)
{
	while (1)
	{
		char c;
		int lines = 0;
		int words = 0;
		int chars = 0;
		char huancun = 0;
		int prelines = 0;
		bool inword = false;
		while ((c = getchar()) != STOP)
		{
			chars++;
			if (isspace(c) && inword)
			{
				inword = false;
			}
			if (!isspace(c) && !inword)
			{
				inword = true;
				words++;
			}
			if (c == '\n')
				lines++;
			huancun = c;
		}
		if (huancun != '\n')
			prelines++;
		printf("行数：%d；字符数：%d；单词数：%d；不完整行：%d\n", lines, chars, words, prelines);
	}
	system("pause");
}*/