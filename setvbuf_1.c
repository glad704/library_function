#include<stdio.h>
#include<unistd.h>

int main()
{
	setvbuf(stdout,NULL,_IOLBF,3);
	printf("rar");
	sleep(5);
	return 0;
}
