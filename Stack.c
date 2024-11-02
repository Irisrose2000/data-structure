#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push();
void pop();
void display();

int main() {
    int act;
    
    do {
        printf("Select any operation from the below menu:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &act);

        switch (act) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice! Try again\n");
                break;
        }
    } while (act != 4);

    return 0; // Correct return type for main
}

void push() {
    int item;
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    
    if (top == SIZE - 1) {
        printf("Stack is overflow\n"); // Correct message for overflow
    } else {
        top++;
        stack[top] = item;
        printf("Element is inserted successfully into the stack\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is underflow\n"); // Correct message for underflow
    } else {
        int item = stack[top];
        printf("Element %d is deleted successfully\n", item);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
