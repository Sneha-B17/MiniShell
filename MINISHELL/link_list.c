#include"headers.h"
int insert_first(struct node **head)
{
    struct node * new = malloc(sizeof(struct node));
    if(new == NULL)
    {
	printf("failed to create new node\n");
	return  0;
    }
    new->child_pid = pid;
    strcpy(new->cmd_name,input_string);
    new->link = NULL;
    if(*head == NULL)
    {
      *head = new;
    }
   else
   {
       new->link = *head;
       *head = new;
   } 
}
int delete_first(struct node **head)
{
   struct  node * temp = *head;
    if(*head == NULL)
	return FAILURE;
    else
    {
	*head = temp->link;
	free(temp);

	return SUCCESS;
    }
}

void print_list(struct node *head)
{
    struct node *temp = head;
  int  i=1;
    while(temp != NULL)
    {
	printf("[%d]      Stopped               %s \n",i++, temp->cmd_name);
	temp = temp->link;
	
    }
}
