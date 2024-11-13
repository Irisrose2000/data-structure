#include <stdio.h>

int main() {
    int i, j, b, a[100], n;
    
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    
    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        b = a[i];  // The element to be inserted
        j = i - 1;

        // Shift elements to the right until the correct position is found
        while (j >= 0 && a[j] > b) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = b;  // Insert the element at the correct position
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
