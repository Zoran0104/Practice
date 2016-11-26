#include<stdio.h>
#include<ctype.h>												//为isspace()函数提供原型
#include<stdbool.h>												//为bool true、false提供定义
#define STOP '|'												
int main(void)
{
	char c;
	char prev;
	long n_chars = 0;											//字符数
	int n_lines = 0;											//行数
	int n_words = 0;											//单词数
	int p_lines = 0;											//不完整的行数
	bool inword = false;										 //如果在单词中，inword等于true
	printf("Enter text to be analyzed(| to terminate):\n");
	prev = '\n';												//初始化prev值
	while ((c = getchar()) != STOP)
	{
		n_chars++;												
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true;
			n_words++;
		}
		if (isspace(c) && inword)
			inword = false;
		prev = c;
	}
	if (prev != '\n')
		p_lines = 1;
	printf("characters=%ld,words=%d,lines=%d,", n_chars, n_words, n_lines);
	printf("partial lines=%d\n", p_lines);
	system("pause");
	return 0;
}