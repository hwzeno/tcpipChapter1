/*********************************
    > File Name: low_open.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月15日 星期二 10时17分21秒
 ********************************/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void error_handling(char *message);
int main(void)
{
	int fd;
	int wBytes = 0;
	char buf[] = "Let's go!\n";

	fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);//注意
	if(fd == -1)
		error_handling("open() error!");
	printf("file descriptor:%d \n", fd);

	if((wBytes = write(fd, buf, sizeof(buf))) == -1)
		error_handling("write() error!");
	printf("wBytes: %d\n", wBytes);//写入11个字节，一个换行，一个字符串结尾\0
	
	close(fd);
	return 0;
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

