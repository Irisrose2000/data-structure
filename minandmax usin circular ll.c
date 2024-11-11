#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*createNode(int data)
{
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=new_node;
    return new_node;
}
void MinandMax(struct node*head)
{
    if(head==NULL)
    {
        printf("the list is empty\n");
    }
    struct node*temp=head;
    int min=temp->data;
    int max=temp->data;
    do
    {
        if(temp->data<min)
        {
            min=temp->data;
        }
        if(temp->data>max)
        {
            max=temp->data;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("the maximim is:%d",max);
    printf("the minimum is:%d",min);
}
int main()
{
    int i, n,value;
    struct node*head=NULL;
    struct node*tail=NULL;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the data of the node \t%d",i+1);
        scanf("%d",&value);
        struct node*new_node=createNode(value);
        if(head==NULL)
        {
            head=new_node;
            tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail=new_node;
        }
       tail->next=head;
    }
    MinandMax(head);
}
