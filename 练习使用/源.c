#include<stdio.h>
int strlens(const char *s);
char strcpys(char *s, const char *ss);
int strcmps(const char *s, const char *ss);
char strcats(char *s, char *ss);

int main(void)
{
}
	


int strlens(const char *s)
{
	int len = 0;
	while (*s++)
		len++;
	return len+1;
}

char strcpys(char * s, const char * ss)
{
	while (*s++ = *ss++);
	return s;
}
int strcmps(const char *s, const char *ss)
{
	char *s3 = s, *s4 = ss;
	while (*s3++ != *s4++ && (*s3 || *s4))
	{
		if (*--s3<*--s4)
			return -1;
		else if (*s3>*s4) return 1;
		else return 0;
		s3++; s4++;
	}
}
char strcats(char *s, char *ss)  
{
	char *q = s;
	while (*(s++));
	s--;
	while ((*(s++) = *ss, *(ss++)));
	return q;
}

