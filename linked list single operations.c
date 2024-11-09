#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
}*head=NULL;
void insert(int location);
void delete(int location);
void display();
int main()
{
    int location,a;
    do
    {
        printf("choose the operation\n");
        printf("1.insert at the beggining\t2.insert at the end\t3.insert at any position\n");
         printf("4.delete at the beggining\t5.delete at the end\t6.delete at any position\n");
         printf("7.display\t8.exit\n");
         scanf("%d",&a);
         switch(a)
         {
             case 1:
             insert(1);
             break;
             case 2:
             insert(0);
             break;
             case 3:
             printf("enter the location you want to insert\n");
             scanf("%d",&location);
             insert(location);
             break;
             case 4:
             delete(1);
             break;
             case 5:
             delete(0);
             break;
             case 6:
             printf("enter the location you want to delete\n");
             scanf("%d",&location);
             delete(location);
             break;
             case 7:
             display();
             break;
             case 8:
             printf("exiting....\n");
             break;
             default:
             printf("invalid choice\n");
             break;
         }
        
    }while(a!=8);
}
void insert(int location)
{
   int data;
   printf("enter the data you want to insert\n");
   scanf("%d",&data);
   struct Node*new=(struct Node*)malloc(sizeof(struct Node));
   new->data=data;
   new-> next=NULL;
   if(head==NULL)
   {
       head=new;
       return;
   }
    if(location==1)
    {
        new->next=head;
        head=new;
        return;
    }
    else if(location==0)
    {
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        return;
    }
    else
    {
        int i=1;
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
        ptr=head;
        while(i<location-1&&ptr->next!=NULL)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr->next==NULL)
        {
            printf("Invalid position");
            return;
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}
void delete(int location)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node*));
    temp=NULL;
    if(location==1)
    {
        temp=head;
        head=head->next;
        free(temp);
        return;
    }
    else if(location==0)
    {
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
        return;
    }
    else
    {
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
        ptr=head;
        for(int i=1;(i<location-1&&ptr->next==NULL);i++)
        {
            ptr=ptr->next;
            
        }
        if(ptr->next=NULL)
        {
            printf("invalid position");
            return;
        }
        temp=ptr->next;
        ptr->next=temp->next;
        return;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
   struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
   ptr=head;
   while(ptr!=NULL)
   {
       printf("%d->",ptr->data);
       ptr=ptr->next;
   }
}
