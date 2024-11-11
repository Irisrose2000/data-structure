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
    new_node->next=NULL;
    return new_node;
}
void calculateSumandAdittion(struct node*head)
{
    struct node*temp;
    int sum=0,count=0;
    while(temp!=NULL)
    {
        sum+=temp->data;
        count++;
        temp=temp->next;
    }
    if(count>0)
    {
        float average=(float)sum/count;
        printf("sum:%d\n",sum);
        printf("average:%f\n",average);
    }
    else
    {
        printf("the list is empty\n");
    }
}
int main()
{
    int i, n,value;
    struct node*head=NULL;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the data of the node \t%d",i+1);
        scanf("%d",&value);
        struct node*new_node=createNode(value);
        new_node->next=head;
        head=new_node;
    }
    calculateSumandAdittion(head);
}
