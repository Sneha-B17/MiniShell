#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
 

#define BUILTIN		1
#define EXTERNAL	2
#define NO_COMMAND  3
#define FAILURE -1
#define SUCCESS 0


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct node
{
    int child_pid;
    char cmd_name[20];
    struct node * link;
};

extern char path[50];
extern struct node *head;
extern char prompt_name[20];
extern int status;
extern int pid;
extern char * external_commands[154];
extern char * builtin[31];
extern char input_string[25];

void scan_input(char *prompt, char *input_string);
char *get_command(char *input_string);
//void copy_change(char *prompt, char *input_string);
int check_command_type(char *command);
//void echo(char *input_string, int status);
void execute_internal_commands(char *input_string);
void signal_handler(int sig_num);
void extract_external_commands(char **external_commands);
void execute_external_commands(char*input_string);
void execute_internal_commands(char*input_string);
void print_list(struct node *head);
int delete_first(struct node **head);
int insert_first(struct node **head);
int pipe_count(char **cmd_with_option);
void n_pipes(char **cmd_with_option,int k);

#endif
