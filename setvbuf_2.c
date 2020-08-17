#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char buf[42];
	if(setvbuf(stdout,buf,_IOFBF,sizeof buf))
	{
		perror("Failed to change the buffer of stdout");
		return EXIT_FAILURE;
	}
	printf("He");
	/*The buffer contains "He"; nothing is written yet to stdout*/
	fflush(stdout);	/*"He" is actually written to stdout*/

	if(setvbuf(stdout,NULL,_IONBF,0))
	{
		perror("Failed to change the buffer of stdout");
		return EXIT_FAILURE;
	}
	printf("llo w");	/*"llo w" is written to stdout, there is no buffering*/

	if(setvbuf(stdout,buf,_IOLBF,sizeof buf))
	{
		perror("Failed to change the buffer of stdout");
		return EXIT_FAILURE;
	}
	printf("orld");	/*The buffer now contains "orld"; nothing is written yet to stdout*/
	putchar('\n');	/*stdout is line buffered; everything in the buffer is now written to stdout along with the newline*/

	return EXIT_SUCCESS;
}
