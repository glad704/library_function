#include<stdio.h>

int main(void)
{
	int c;
	if(setvbuf(stdin,NULL,_IONBF,0))
	{
		fprintf(stderr,"Couldn't turn off stdin buffer\n");
	}

	if(setvbuf(stdout,NULL,_IONBF,0))
	{
		fprintf(stderr,"Couldn't turn off stdout buffer\n");
	}

	while((c=getchar()) != EOF)
	{
		putchar(c);
	}
}
