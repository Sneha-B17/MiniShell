#include"headers.h"
void signal_handler(int sig_num)
{
    if( sig_num == SIGTSTP)
    {
        if(pid ==  0)
	{
	  write(1,"\n",1); 
         /* write(1,prompt_name,strlen(prompt_name));
          write(1,getcwd(path,sizeof(path)),strlen(path));*/
	}
	/*else if(pid>0)
	{
	    if(WIFSTOPPED(status))
            {
        	insert_first(&head);
    	    }
	    pid = 0;
       
        }*/
    }
    else  if( sig_num == SIGINT)
    {
        if(pid == 0)
	{
	  write(1,"\n",1);
	 /* write(1,prompt_name,strlen(prompt_name));
          write(1,getcwd(path,sizeof(path)),strlen(path));*/
	}
    }
    else if(sig_num == SIGCHLD)
    {
     while(waitpid(-1,&status,WNOHANG)>0)
     {
	 if(WIFEXITED(status) || WIFSIGNALED(status))
         {
	      delete_first(&head);
	 }
     }
    } 
}

