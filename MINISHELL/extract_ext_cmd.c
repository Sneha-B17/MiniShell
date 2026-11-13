#include"headers.h"
int ext_count;
void extract_external_commands(char**external_commands)
{
    int fd=open("external.txt",O_RDONLY,0666);
    if(fd==-1)
    {
	perror("open failed\n");
	exit(1);
    }

    char buf[20];
    char ch;
    int j=0;

    while(read(fd,&ch,1)!=0)
    {
	if(ch!='\n')
	{
	    buf[j++]=ch;
	}
	else
	{
	    buf[j]='\0';
	    external_commands[ext_count]=(char*)(calloc(strlen(buf)+1,sizeof(char)));
            strcpy(external_commands[ext_count],buf);
	    ext_count++;
	    j=0;
	}
    }
    close(fd);
}

