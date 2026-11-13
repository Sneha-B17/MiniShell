#include"headers.h"
char * get_command(char*input_string)
{
    char*cmd=malloc(strlen(input_string)+1);
    
    int i=0;
    while(input_string[i]!=' ' && input_string[i]!='\0')
    {
	cmd[i]=input_string[i];
	i++;
    }
    cmd[i]='\0';

    return cmd;
}
