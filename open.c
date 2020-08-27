#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	char buf[14];
	fd = open("myfile.txt",O_CREAT|O_WRONLY,0600);
	if(fd==-1)
	{
		perror("open\n");
		exit(1);
	}
	
	write(fd,"Hello world!!\n",14);

	close(fd);

	fd=open("myfile.txt",O_RDONLY);
	if(fd==-1)
	{
		perror("open\n");
		exit(1);
	}
	read(fd,buf,13);
	buf[13]='\0';
	printf("buf: %s\n",buf);

	close(fd);

	return 0;
}
