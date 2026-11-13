#include"headers.h"

void execute_internal_commands(char*input_string)
{
    if((strcmp(input_string,"exit"))==0)
    {
	exit(0);
    }

    else if((strcmp(input_string,"pwd"))==0)
    {
	char path[50];
	getcwd(path,sizeof(path));
	printf("%s\n",path);
    }
    else if((strncmp(input_string,"cd",2))==0)
    {
	int i=3;
	while(input_string[i]==' ')
	{
	    i++;
	}
	chdir(input_string+i);
    }
    else if((strcmp(input_string,"echo $$"))==0)
    {
	printf("%d\n",getpid());
    }
    else if((strcmp(input_string,"echo $?"))==0)
    {
	if(WIFEXITED(status))
	{
	    printf("%d\n",WEXITSTATUS(status));
	}
    }
    else if((strcmp(input_string,"echo $SHELL"))==0)
    {
	char*buf=getenv("SHELL");
	printf("%s\n",buf);
    }
    else if(strcmp(input_string,"jobs")==0)
    {
	print_list(head);
    }
    else if(strcmp(input_string,"fg")==0)
    {
	 kill(head->child_pid, SIGCONT);

         waitpid(head->child_pid, &status, WUNTRACED);

         if(WIFEXITED(status) || WIFSIGNALED(status))
         {
              delete_first(&head);
	 }
    }
      else if(strcmp(input_string,"bg")==0)
    {
	kill(head->child_pid,SIGCONT);

    }	
}
