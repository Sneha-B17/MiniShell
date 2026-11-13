#include "headers.h"
void execute_external_commands(char *input_string)
{
    //covert 1D array input into 2d array
    int i=0,j=0,k=0;
    int len = strlen(input_string);
    char *cmd_with_option[len];
    memset(cmd_with_option,0,sizeof(cmd_with_option));
    char buffer[15];

    while(input_string[i] != '\0')
    {
	if(input_string[i] != ' ' && input_string[i] != '\0')
        {
          buffer[j] =input_string[i];
	  i++;
          j++;	  
	}
	else 
	{   
	  buffer[j] = '\0';
	  cmd_with_option[k]  = calloc(strlen(input_string)+1,sizeof(char));
	  strcpy(cmd_with_option[k],buffer);
          k++;
	  i++;
	  j=0;
	  memset(buffer,0,15);

	} 
    }
    buffer[j] = '\0';
    cmd_with_option[k]  = calloc(strlen(input_string)+1,sizeof(char));
    strcpy(cmd_with_option[k],buffer);
     
    int count = pipe_count(cmd_with_option);
    if(count == 0)
    {
	execvp(cmd_with_option[0],cmd_with_option);
    }
    else
    {
	n_pipes(cmd_with_option,k+1);
    }
}
int pipe_count(char **cmd_with_option)
{
    int i,count=0;
    for(i=0;cmd_with_option[i];i++)
    {
	if(strcmp(cmd_with_option[i],"|")==0)
	{
             count++;
	}
    }
    return count;
}    



