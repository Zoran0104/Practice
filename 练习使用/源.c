#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{

	char c;
	int words=0;
	long chars=0;
	int lines = 0;
	int prelines = 0;
	bool inword = false;
	char pre = '\n';
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
	pre == '\n'? 1 : prelines++;
	printf("chars:%ld,lines:%d,words=%d,prelines=%d", chars, lines, words, prelines);


}