#include <stdio.h>
#define MAX_TERMS 100

void polyadd(float poly1[][2], int n1, float poly2[][2], int n2);
void printpolynomial(float poly[][2], int n);

int main() {
    int n1, i, n2;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    float poly1[n1][2]; // Array for first polynomial

    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        scanf("%f %d", &poly1[i][0], &poly1[i][1]);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    float poly2[n2][2]; // Array for second polynomial

    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        scanf("%f %d", &poly2[i][0], &poly2[i][1]);
    }

    // Call the function to add polynomials
    polyadd(poly1, n1, poly2, n2);
}

// Function to add two polynomials
void polyadd(float poly1[][2], int n1, float poly2[][2], int n2) {
    float resultant[MAX_TERMS][2];  // Array to store result
    int i = 0, j = 0, n3 = 0;

    // Loop through both polynomials
    while (i < n1 && j < n2) {
        if (poly1[i][1] == poly2[j][1]) {
            // Add coefficients if exponents are the same
            resultant[n3][0] = poly1[i][0] + poly2[j][0];
            resultant[n3][1] = poly1[i][1];
            n3++;
            i++;
            j++;
        } else if (poly1[i][1] > poly2[j][1]) {
            // If poly1 exponent is higher, add it to the result
            resultant[n3][0] = poly1[i][0];
            resultant[n3][1] = poly1[i][1];
            n3++;
            i++;
        } else {
            // If poly2 exponent is higher, add it to the result
            resultant[n3][0] = poly2[j][0];
            resultant[n3][1] = poly2[j][1];
            n3++;
            j++;
        }
    }

    // Add remaining terms from poly1
    while (i < n1) {
        resultant[n3][0] = poly1[i][0];
        resultant[n3][1] = poly1[i][1];
        n3++;
        i++;
    }

    // Add remaining terms from poly2
    while (j < n2) {
        resultant[n3][0] = poly2[j][0];
        resultant[n3][1] = poly2[j][1];
        n3++;
        j++;
    }

    // Print the resultant polynomial
    printpolynomial(resultant, n3);
}

// Function to print the polynomial
void printpolynomial(float poly[][2], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            // Print the sign between terms
            if (poly[i][0] > 0) {
                printf(" + ");
            } else {
                printf(" - ");
                poly[i][0] = -poly[i][0];  // Make the coefficient positive for printing
            }
        }
        // Print the term (coefficient and exponent)
        printf("%.1fx^%d", poly[i][0], (int)poly[i][1]);
    }
    printf("\n");
}
