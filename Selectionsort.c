#include<stdio.h>
int main()
{
    int a[9],n,i,j,temp,min;
    printf("enter the size of the array");
    scanf("%d",&n);
    printf("enter the elements in the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("the sorted array is");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
