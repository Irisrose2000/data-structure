#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int data) {
    int index = hashFunction(data);
    struct node* new_node = createNode(data);
    if (hashTable[index] == NULL) {
        hashTable[index] = new_node;
    } else {
        new_node->next = hashTable[index];
        hashTable[index] = new_node;
    }
    printf("The element %d is inserted at index %d\n", data, index);
}

struct node* search(int key) {
    int index = hashFunction(key);
    struct node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void delete(int key) {
    int index = hashFunction(key);
    struct node* temp = hashTable[index];
    struct node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("The deleted element is %d at index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element %d not found in the table\n", key);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node* temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter the value you want to search: ");
                scanf("%d", &value);
                if (search(value) != NULL) {
                    printf("The element %d is found\n", value);
                } else {
                    printf("The element %d is not found\n", value);
                }
                break;
            case 3:
                printf("Enter the value you want to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice < 5);

    return 0;
}
