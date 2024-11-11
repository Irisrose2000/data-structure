#include <stdio.h>

int main() {
    int a[100], i, j, min, temp, n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection Sort
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        // Swap the minimum element with the current element
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}
