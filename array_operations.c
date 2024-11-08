#include<stdio.h>
int array_insertion(int a[],int n);
int array_deletion(int a[],int n);
void display(int a[],int n);
int main()
{
  int a[100],i,n,ch;
  printf("enter the size of the array\n");
  scanf("%d",&n);
  printf("enter the elements in the array\n");
  for(int i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
  do
  {
      printf("choose your operation\n 1.Insert \n2.Delete\n 3.Display \n 4.exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
          n=array_insertion(a,n);
          break;
          case 2:
          n=array_deletion(a,n);
          break;
          case 3:
           display( a, n);
          break;
          case 4:
          printf("exiting...\n");
          break;
          default:
          printf("invalid choice\n");
      }
  }while(ch!=4);
}
int array_insertion(int a[],int n)
{
    int item,position,i;
    printf("enter the element and the position you want to insert");
    scanf("%d",&item);
    scanf("%d",&position);
    if(position<=n&&position>=0)
    {
        for(i=n;i>position;i--)
        {
            a[i]=a[i-1];
        }
        a[i]=item;
        n++;
        printf("element inserted succesfully");
        
    }
    else
    {
        printf("invalid position\n");
    }
    return n;
}
int array_deletion(int a[],int n)
{ 
    int i,j,found=0,item;
    printf("enter the element you want to delete ");
    scanf("%d",&item);
    for (int i = 0; i < n; i++) {
        if (a[i] == item) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;  
            printf("Element deleted successfully.\n");
            break;
        }
    }
    
    if(found !=1)
    {
        printf("the element dosent exist in the array\n");
    }
    return n;
}
void display(int a[],int n)
{
    printf("the sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    
}
   
      
