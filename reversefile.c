#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mod 1000000007
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include<sys/file.h>
#include<sys/stat.h>
int main(int argc ,char *argv[])
{
	long long source,dest,n;
	char buf,name[256],temp[256];
	long long filesize,i,len;
	if(argc!=2)
	{
		strcpy(temp,"Input format should be of the form: ./a.out filename \n");
		len=strlen(temp);
		write(1,temp,len);
		exit(-1);
	}
	if((source=open(argv[1],0400))<0)
	{
		write(1,"can't open file\n",17);
		exit(-1);
	}
	else
	{
		mkdir("Assignment", S_IRWXU | S_IXGRP | S_IXOTH);
		strcpy(name,"Assignment/");
		strcat(strcat(name,"output_"),argv[1]);
		dest=creat(name,S_IREAD | S_IWRITE);
	}
	filesize=lseek(source,(off_t) 0, SEEK_END);
	for(i=filesize-2;i>=0;i--)
	{
		lseek(source, (off_t) i ,SEEK_SET);
		n=read(source, &buf, 1);
		if(n!=1)
		{
			write(1, "can't read 1 byte\n",19);
			exit(-1);
		}
		n=write(dest, &buf, 1);
		if(n!=1)
		{
			write(1, "can't write 1 byte\n",20);
			exit(-1);
		}
	}
	close(source);
	close(dest);
	return 0;
}

