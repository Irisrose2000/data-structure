#include<stdio.h>
# define MAX 100
int stack_arr[MAX],top=-1;
void push(int value);
int pop();
void display();
int isFull()
{
    return top ==MAX-1;
}
int isEmpty()
{
    return top ==-1;
}
int main()
{
    int choice,value;
     while(1)
     {
        printf("choose the operation\n");
        printf("1.push\t2.pop\t3.display\t4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
          printf("enter the value you wan to insert\n");
          scanf("%d",&value);
          push(value);
          break;
          case 2:
          value=pop();
          if(value!=-1)
          {
              printf("The elemnet %d is found\n",value);
          }
          else
          {
              printf("the element is not found\n");
          }
          break;
          case 3:
          display();
          break;
          case 4:
          printf("exiting...\n");
          default:
          printf("invalid choice\n");
        }
    }
}
void push(int value)
{
    if(isFull())
    printf("the stack is overflow\n");
    else
    {
        stack_arr[++top]=value;
        printf("the element is pushed succesfully\n");
    }
}
int pop()
{
if(isEmpty())
{
    printf("the tsack is underflow\n");
    return -1;
}
else
{
    return stack_arr[top--];
}
}
void display()
{
    if(isEmpty())
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elements are\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack_arr[i]);
        }
    }
}
