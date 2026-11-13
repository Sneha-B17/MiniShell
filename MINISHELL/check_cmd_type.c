#include"headers.h"
extern char * external_commands[154];

char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
                                                "set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
                                                "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", "fg", "bg" , "jobs" ,NULL};

int check_command_type(char*cmd)
{
    for(int i=0;builtins[i]!=NULL;i++)
    {
	if(strcmp(cmd,builtins[i])==0)
	    return BUILTIN;
    }


    for(int i=0;external_commands[i]!=NULL;i++)
    {
	if(strcmp(cmd,external_commands[i])==0)
	    return EXTERNAL;
    }

    return NO_COMMAND;
}
