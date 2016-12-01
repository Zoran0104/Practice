#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '@'
int  main(void)
{
	while (true)
	{
		char c;
		char prechar = '\n';
		int preline = 0;
		int lines = 0;
		int words = 0;
		long chars = 0;
		bool inword = false;
		while ((c = getchar()) != STOP)
		{
			chars++;
			c == '\n' ? lines++ : 1;
			if (!isspace(c) && !inword && !ispunct(c))
			{
				words++;
				inword = true;
			}
			if (isspace(c) && inword)
			{
				inword = false;
			}
			prechar = c;
		}
		prechar == '\n' ? 1 : preline++;
		printf("chars=%ld,words=%d,lines=%d", chars, words, lines);
		preline == 0 ? printf(".\n") : printf(",preline=1.\n");
	}
}
