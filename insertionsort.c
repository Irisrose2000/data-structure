#include <stdio.h>

int main() {
    int a[50], i, j, b, n;

    printf("Enter the array size:\n");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++) {
        b = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > b) {
            a[j + 1] = a[j];  // Shift elements to the right
            j = j - 1;
        }
        a[j + 1] = b;  // Insert the element in the correct position
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
