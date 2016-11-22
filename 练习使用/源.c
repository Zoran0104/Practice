#include<stdio.h>
#define timeeach 60
int main()
{
	int innum, hours, minute;
	printf("Please enter a number to deserb the time:");
	while (scanf_s("%d",&innum)==1)
	{
		if (innum <= 0)
		{
			printf("bye,bye!");
			break;
		}
		hours = innum / timeeach;
		minute = innum - hours*timeeach;
		printf("The time you have enter is %dhours%dninutes.\n",hours,minute);
	}
}