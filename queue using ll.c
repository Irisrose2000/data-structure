#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *front = NULL, *rear = NULL;

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(int value);
int dequeue();
void display();
int isEmpty() {
    return front == NULL;
}

int main() {
    int choice, value;
    while (1) {
        printf("Enter your choice\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("The element %d is deleted\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void enqueue(int value) {
    struct node* newnode = createNode(value);
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("The element %d is enqueued successfully\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    struct node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL; // If the queue is now empty, set rear to NULL as well
    }
    int value = temp->data;
    free(temp);
    return value;
}

void display() {
    if (isEmpty()) {
        printf("The queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
