#include<stdio.h>
int main()
{
    int a[5], n, i, j, b;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements in the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Insertion sort logic
    for(i = 1; i < n; i++)
    {
        b = a[i];  // The element to be inserted in the sorted part
        j = i - 1;

        // Move elements of the sorted part that are greater than `b` one position ahead
        while(j >= 0 && a[j] > b)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        // Insert `b` in the correct position
        a[j + 1] = b;
    }

    printf("The sorted array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}
