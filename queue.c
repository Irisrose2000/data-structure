#include <stdio.h>
#define MAX 100

int q[MAX], front = -1, rear = -1; 
void enqueue(int value);
int dequeue();
void display();

int isFull() {
    return rear == MAX - 1; // The queue is full if rear reaches MAX - 1
}

int isEmpty() {
    return front == -1 || front > rear; 
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose the operation\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you want to insert\n");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("The element %d is dequeued\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void enqueue(int value) {
    if (isFull()) {
        printf("The queue is overflow\n");
    } else {
        if (front == -1) {  // If the queue is empty, initialize front
            front = 0;
        }
        rear++;  // Move rear to the next position
        q[rear] = value;
        printf("The element %d is enqueued successfully\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("The queue is underflow\n");
        return -1;
    } else {
        int value = q[front];  // Store the front element to return
        front++;  // Move front to the next position
        
        // Reset the queue if it becomes empty
        if (front > rear) {
            front = rear = -1;
        }

        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    }
}
