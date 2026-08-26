#include <stdio.h>
#include <stdlib.h>

struct Node {
    int token;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at front
void insertFront(int token) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->token = token;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int token) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->token = token;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Insert at specific position
void insertAtPosition(int token, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertFront(token);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->token = token;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display
void display() {
    struct Node *temp = head;

    printf("\nPatient Queue: ");

    if (head == NULL) {
        printf("Empty");
    }

    while (temp != NULL) {
        printf("%d -> ", temp->token);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, token, position;

    while (1) {
        printf("\n===== HOSPITAL PATIENT QUEUE =====\n");
        printf("1. Insert Critical Patient at Front\n");
        printf("2. Insert Routine Patient at End\n");
        printf("3. Insert Patient at Specific Position\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter patient token: ");
                scanf("%d", &token);

                insertFront(token);
                display();
                break;

            case 2:
                printf("Enter patient token: ");
                scanf("%d", &token);

                insertEnd(token);
                display();
                break;

            case 3:
                printf("Enter patient token: ");
                scanf("%d", &token);

                printf("Enter position: ");
                scanf("%d", &position);

                insertAtPosition(token, position);
                display();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}