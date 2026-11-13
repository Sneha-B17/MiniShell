#include"headers.h"
void n_pipes(char **argv ,int argc)
{

    //Checking sufficient argument passed or not
    if(argc < 3)
    {
        printf("Error: No arguments passed Usage:./pipe <command1> '|' <command2> \n");
        printf("Error: No arguments passed Usage:./pipe <command1> '|' <command2> '|' <command3> etc\n");
        return ;
    }
    //Finding any options is there and after last pipe any command is there or not
    int cmdpos[argc];
    cmdpos[0]=0;
    int count =0,status;
    for(int i=0;argv[i];i++)
    {
       if(strcmp(argv[i],"|")==0)
       {
           count++;
           cmdpos[count] = i+1;
           argv[i] = NULL;

           if(argv[i+1] == NULL)
           {
               printf("Error: Insufficient arguments passed Usag:./pipe <command1> '|' <command2>\n");
               return ;
           }
       }
    }
    //Creating child process
    int fd[2],ret,j,prev_fd=-1;
    for(int i = 0; i<=count;i++)
    {
        if(i < count)
	{
            ret = pipe(fd);
           if(ret == -1)
           {
              printf("Failed to pipe\n");
              return ;
           }
        
	}

        int pid = fork();
        if(pid == -1)
        {
            printf("failed to creat child %d\n",i);
            return ;
        }
        else if (pid > 0)
        {
	    //parent process
	    if(i>0)
		close(prev_fd);
	   
            if(i < count)
            {
              prev_fd=fd[0];
              close(fd[1]);
            }
	}
        else
        {
	    //child process
	    if(i>0)
	    {
		dup2(prev_fd,0);
		close(prev_fd);
	    }

            if(i < count)
            {
               close(fd[0]);
               dup2(fd[1],1);
	       close(fd[1]);
            }
            j = cmdpos[i];
            execvp(argv[j],argv+j);
        }
    }
    //wait untill all child terminates
    for(int k = 0;k<=count;k++)
    {
        wait(&status);
    }
}
