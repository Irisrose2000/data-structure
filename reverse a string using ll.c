#include<stdio.h>
#include<stdlib.h>
// create a structure node with char data and next pointer
struct node
{
    char data;
    struct node*next;
};
void push(struct node**head_ref,char new_data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
void printReverse(struct node*head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
//in the  main function initialize the variable and make head=null 
// and ask the user to enter the input use the for loop to push each charachter to ll
int main()
{
    char a[100];
    struct node*head=NULL;
    printf("enter the string\n");
    fgets(a,sizeof(a),stdin);
    for(int i=0;(a[i]!='\0'&&a[i]!='\n');i++)
    {
        push(&head,a[i]);
    }
    printf("reverse string is:");
    printReverse(head);
}
