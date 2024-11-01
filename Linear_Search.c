#include<stdio.h>
int main()
{
    int a[5],i,n,b,loc=-1;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements in the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the elemnet you want to search\n");
    scanf("%d",&b);
    for(i=0;i<n;i++)
    {
        if(a[i]==b)
        {
            loc=i+1;
        }
    }
    if(loc==-1)
    {
        printf("element not found");
    }
    else
    {
        printf("element found at %d",loc);
    }
}
