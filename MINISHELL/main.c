#include"headers.h"
char  * external_commands[154];
int status=0;
int pid=0;
char prompt_name[20]="minishell";
char input_string[25];
struct node*head=NULL;
char path[50];

int main()
{
    system("clear");
    //char prompt_name[20]="minishell$";
    //char input_string[25];
    
    extract_external_commands(external_commands);
    scan_input(prompt_name,input_string);
    

}
