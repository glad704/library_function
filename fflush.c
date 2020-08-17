#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define BUF_SIZE (3)

char buf[BUF_SIZE];
FILE *stream;

int main()
{
	stream = fopen("Flush.txt","w");
	//setvbuf(stdout,NULL,_IOFBF,3);
	setvbuf(stream,buf,_IOFBF,BUF_SIZE);
	printf("rar\n");
	fprintf(stream,"RAR\n");
	fflush(stream);
	sleep(5);
	fclose(stream);
	return 0;
}
