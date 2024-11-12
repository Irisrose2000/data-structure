#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*top=NULL;
struct node*createNode(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void push(int value);
int pop();
void display();
 int isEmpty()
{
    return top==NULL;
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1.push\t 2.pop\t3.display\t4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value you want to insert\n");
            scanf("%d",&value);
            push(value);
            break;
            case 2:
            value=pop();
            if(value!=-1)
            {
                printf("The element is deleted\n");
            }
            break;
            case 3:
            display();
            break;
            case 4:
            printf("EXITING\n");
            break;
            default:
            printf("Invalid choice\n");
        }
    }
}
void push(int value) {
    struct node* newnode = createNode(value);
    newnode->next = top;
    top = newnode;
    printf("The element %d is pushed successfully\n", value); // Corrected print message
}
int pop()
{
    if(isEmpty())
    {
        printf("the stack is underflow\n");
        return -1;
    }
   struct node*temp=top;
   top=top->next;
   int value =temp->data;
   free(temp);
   return value;
}
void display()
{
    if(isEmpty())
    {
        printf("the stack is empty\n");
    }
    struct node*temp=top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
