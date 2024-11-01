#include<stdio.h>
int main()
{
    int a[5],i,n,low,high,m,b;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements in the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element to search\n");
    scanf("%d",&b);
    low=0;
    high=n-1;
   
    while(low<=high)
    {
        m=(low+high)/2;
        if(b==a[m])
        {
            printf("element found at %d\n",m);
        }
        else if(b<a[m])
        {
            high=m-1;
        }
        else
        {
            low=m+1;
        }
    }
    if(b!=a[m])
    {
        printf("the element is not found");
    }
    
}
