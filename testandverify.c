#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mod 1000000007
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include<sys/file.h>
#include<sys/stat.h>
struct stat sb;
int main(int argc ,char *argv[])
{
	long long source,dest,n,m;
	char buf,name[256],temp[512],buf1;
	long long filesize,i,len,j;
	if(argc!=2)
	{
		strcpy(temp,"Input format should be of the form: ./a.out filename \n");
		len=strlen(temp);
		write(1,temp,len);
		exit(-1);
	}


//directory creation checking:	
	strcpy(temp,"Checking whether the directory has been created: ");
	len=strlen(temp);
	write(1,temp,len);
	if(stat("Assignment", &sb)==0 && S_ISDIR(sb.st_mode))
	{
		write(1,"Yes\n",5);
	}
	else
	{
		write(1,"No\n",4);
	}



//file creation checking:


	strcpy(temp,"Checking whether the file has been created: ");
	len=strlen(temp);
	write(1,temp,len);
	strcpy(name,"Assignment/");
	strcat(strcat(name,"output_"),argv[1]);
	if( access(name, F_OK) != -1)
	{
		write(1,"Yes\n",5);
	}
	else
	{
		write(1,"No\n",4);
	}

//file reverse checking:


	strcpy(temp,"Checking whether file contents have been reversed: ");
	len=strlen(temp);
	write(1,temp,len);
	if((source=open(argv[1],0400))<0)
	{
		write(1,"can't open file\n",17);
		exit(-1);
	}
	else
	{
		strcpy(name,"Assignment/");
		strcat(strcat(name,"output_"),argv[1]);
		if((dest=open(name,0400))<0)
		{
			write(1,"can't open file\n",17);
			exit(-1);
		}
	}
	filesize=lseek(source,(off_t) 0, SEEK_END);
	int flag=0;
	for(i=filesize-2,j=0;i>=0,j<filesize-1;i--,j++)
	{
		lseek(source, (off_t) i ,SEEK_SET);
		n=read(source, &buf, 1);
		lseek(dest, (off_t) j ,SEEK_SET);
		m=read(dest,&buf1,1);
		if(n!=1||m!=1)
		{
			write(1, "Error\n",7);
			exit(-1);
		}
		if(buf != buf1)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		write(1,"Yes\n",5);
	}
	else
	{
		write(1,"No\n",4);
	}
	close(source);
	close(dest);



//checking directory permissions:

	struct stat fs;
	int dire;
	if((dire=open("Assignment",O_RDONLY))<-1)
		return 1;
	if(fstat(dire,&fs)<0)
		return 1;
	strcpy(temp,"Checking directory Permissions: ");
	len=strlen(temp);
	write(1,temp,len);
	write(1,( S_ISDIR(fs.st_mode) ? "d" : "-"),1);
	write(1,( (fs.st_mode & S_IRUSR) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWUSR) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXUSR) ? "x" : "-"),1);
	write(1,( (fs.st_mode & S_IRGRP) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWGRP) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXGRP) ? "x" : "-"),1);
	write(1,( (fs.st_mode & S_IROTH) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWOTH) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXOTH) ? "x" : "-"),1);
	write(1,"\n",2);


	
//checking file permissions:
//	struct stat fs;
	int file;
	if((file=open(name,O_RDONLY))<-1)
		return 1;
	if(fstat(file,&fs)<0)
		return 1;
	strcpy(temp,"Checking file Permissions: ");
	len=strlen(temp);
	write(1,temp,len);
	write(1,( S_ISDIR(fs.st_mode) ? "d" : "-"),1);
	write(1,( (fs.st_mode & S_IRUSR) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWUSR) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXUSR) ? "x" : "-"),1);
	write(1,( (fs.st_mode & S_IRGRP) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWGRP) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXGRP) ? "x" : "-"),1);
	write(1,( (fs.st_mode & S_IROTH) ? "r" : "-"),1);
	write(1,( (fs.st_mode & S_IWOTH) ? "w" : "-"),1);
	write(1,( (fs.st_mode & S_IXOTH) ? "x" : "-"),1);
	write(1,"\n",2);


	return 0;
}

