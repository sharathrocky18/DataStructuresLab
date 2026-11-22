#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    queue[++rear] = value;
    printf("%d inserted into the queue\n", value);
}

void delete() {
    if (front > rear) {
        printf("Queue is Empty! Nothing to delete\n");
        return;
    }
    printf("%d deleted from the queue\n", queue[front++]);
}

void display() {
    if (front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n----- QUEUE MENU -----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice, try again\n");
        }
    }
}