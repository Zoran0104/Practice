#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '|'
int main()
{
	char c;
	int chars = 0;
	int words = 0;
	int lines = 0;
	int sentens = 0;
	bool inword = false;
	while ((c = getchar()) != STOP)
	{
		++chars;
		if (!inword && !isspace(c))
		{
			++words;
			inword = true;
		}
		if (c == '\n')
			++lines;
		if (c == '.')
			++sentens;
		if (inword&&isspace(c))
			inword = false;
	}
	printf("chars:%d,words=%d,lines=%d,sentens=%d", chars, words, lines, sentens);
	while (1);
}
