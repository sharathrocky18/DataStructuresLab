#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *list1 = NULL, *list2 = NULL;

struct node* insert(struct node *head, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct node* concatenate(struct node *a, struct node *b) {
    if (a == NULL)
        return b;

    struct node *temp = a;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = b;
    return a;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert into list 1\n");
        printf("2. Insert into list 2\n");
        printf("3. Display both lists\n");
        printf("4. Sort list 1\n");
        printf("5. Reverse list 1\n");
        printf("6. Concatenate list 2 to list 1\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list1 = insert(list1, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list2 = insert(list2, value);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
            case 4:
                sort(list1);
                printf("List 1 sorted\n");
                break;
            case 5:
                list1 = reverse(list1);
                printf("List 1 reversed\n");
                break;
            case 6:
                list1 = concatenate(list1, list2);
                list2 = NULL;
                printf("List 2 concatenated to list 1\n");
                break;
            case 7:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice, try again\n");
        }
    }
}