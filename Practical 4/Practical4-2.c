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
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
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

// Delete patient by token
void deleteByValue(int token) {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    // If first node contains the token
    if (head->token == token) {
        temp = head;
        head = head->next;
        free(temp);

        printf("Patient %d deleted.\n", token);
        return;
    }

    temp = head;

    while (temp != NULL && temp->token != token) {
        prev = temp;
        temp = temp->next;
    }

    // Token not found
    if (temp == NULL) {
        printf("Patient %d not found!\n", token);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Patient %d deleted.\n", token);
}

// Forward traversal
void displayForward() {
    struct Node *temp = head;

    printf("Queue (Front to Back): ");

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->token);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Reverse printing using recursion
void displayReverse(struct Node *temp) {

    if (temp == NULL) {
        return;
    }

    displayReverse(temp->next);

    printf("%d -> ", temp->token);
}

// Main reverse display function
void reverseDisplay() {

    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (Back to Front): ");

    displayReverse(head);

    printf("NULL\n");
}

int main() {

    int choice;
    int token;
    int position;

    while (1) {

        printf("\n========== HOSPITAL QUEUE ==========\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Patient by Token\n");
        printf("5. Forward Traversal\n");
        printf("6. Reverse Printing\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter patient token: ");
                scanf("%d", &token);

                insertFront(token);
                displayForward();
                break;

            case 2:
                printf("Enter patient token: ");
                scanf("%d", &token);

                insertEnd(token);
                displayForward();
                break;

            case 3:
                printf("Enter patient token: ");
                scanf("%d", &token);

                printf("Enter position: ");
                scanf("%d", &position);

                insertAtPosition(token, position);
                displayForward();
                break;

            case 4:
                printf("Enter token to delete: ");
                scanf("%d", &token);

                deleteByValue(token);
                displayForward();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                reverseDisplay();
                break;

            case 7:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}