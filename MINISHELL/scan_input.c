#include"headers.h"

void scan_input(char*prompt_name,char*input_string)
{
    signal(SIGINT,signal_handler);
    signal(SIGTSTP,signal_handler);
    signal(SIGCHLD,signal_handler);
    while(1)
    {
	printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET":"ANSI_COLOR_CYAN"~"ANSI_COLOR_CYAN"%s"ANSI_COLOR_RESET"$",prompt_name,getcwd(path,sizeof(path)));
	scanf("%[^\n]",input_string);
	getchar();

	if(strncmp(input_string,"ps1=",4)==0)
	{
	    if(input_string[4]!=' ')
	    {
		strcpy(prompt_name,input_string+4);
		//memset(input_string,0,20);
	    }
	    else
	    {
		printf("ps1= command not found\n");
	    }
	}
	else
	{
	    char*cmd=get_command(input_string);
	    int ret=check_command_type(cmd);
	    if(ret==BUILTIN)
	    {
		execute_internal_commands(input_string);
	    }
	    else if(ret==EXTERNAL)
	    {
		int pid=fork();
		if(pid==0)
		{
		    signal(SIGINT,SIG_DFL);
		    signal(SIGTSTP,SIG_DFL);
		    execute_external_commands(input_string);
		}
		else
		{
		    waitpid(pid,&status,WUNTRACED);
		    if(WIFSTOPPED(status))
                   {
                        insert_first(&head);
                   }
		   pid = 0; 
		   //signal(SIGCHLD,signal_handler);
		}
	    }
	    else
	    {
		printf("command not found\n");
	    }
	}
	memset(input_string,0,20);
    }
}
