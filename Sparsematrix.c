#include <stdio.h>

// Define structure for storing non-zero elements of the sparse matrix
struct SparseElement {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix from the user
void readSparseMatrix(struct SparseElement sparse[], int *numElements) {
    printf("Enter the number of non-zero elements: ");
    scanf("%d", numElements);

    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 0; i < *numElements; i++) {
        printf("Element %d - Row, Column, Value: ", i + 1);
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}

// Function to find the transpose of a sparse matrix
void transposeSparseMatrix(struct SparseElement sparse[], int numElements, struct SparseElement transpose[]) {
    for (int i = 0; i < numElements; i++) {
        transpose[i].row = sparse[i].col;
        transpose[i].col = sparse[i].row;
        transpose[i].value = sparse[i].value;
    }
}
void printSparseMatrix(struct SparseElement transpose[], int numTranspose,int numElements) {
    printf("Transpose matrix\nRow\tColumn\tValue\n");
    for (int i = 0; i < numTranspose; i++) {
        printf("%d\t%d\t%d\n", transpose[i].row, transpose[i].col, transpose[i].value);
    }
}


// Function to add two sparse matrices
void addSparseMatrices(struct SparseElement sparse1[], int num1, struct SparseElement sparse2[], int num2, struct SparseElement result[], int *numResult) {
    int i = 0, j = 0, k = 0;

    // Loop through both matrices to add their elements
    while (i < num1 && j < num2) {
        if (sparse1[i].row < sparse2[j].row || (sparse1[i].row == sparse2[j].row && sparse1[i].col < sparse2[j].col)) {
            result[k++] = sparse1[i++];
        } else if (sparse2[j].row < sparse1[i].row || (sparse2[j].row == sparse1[i].row && sparse2[j].col < sparse1[i].col)) {
            result[k++] = sparse2[j++];
        } else {
            result[k] = sparse1[i];
            result[k].value = sparse1[i].value + sparse2[j].value;
            i++;
            j++;
            if (result[k].value != 0) {
                k++;
            }
        }
    }

    // Add any remaining elements
    while (i < num1) result[k++] = sparse1[i++];
    while (j < num2) result[k++] = sparse2[j++];
    
    *numResult = k;
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseElement sparse[], int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    struct SparseElement sparse[10], transpose[10], sum[20];
    int numElements, numTranspose, numSum;

    // Read the original sparse matrix
    printf("Enter the sparse matrix:\n");
    readSparseMatrix(sparse, &numElements);

    // Calculate the transpose of the matrix
    transposeSparseMatrix(sparse, numElements, transpose);
    numTranspose = numElements; // Transpose has the same number of elements as the original matrix
     printSparseMatrix( transpose,  numTranspose,numElements) ;
          numTranspose = numElements;
     

    // Add the original matrix and its transpose
    addSparseMatrices(sparse, numElements, transpose, numTranspose, sum, &numSum);

    // Display the result
    printf("\nSum of the sparse matrix and its transpose:\n");
    displaySparseMatrix(sum, numSum);

    return 0;
}
