#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Node* top = NULL;
    int count = 0;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    while (operations--) {

        int choice;

        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\nEnter choice: ";
        cin >> choice;

    
        if (choice == 1) {

            int value;
            cout << "Enter  value: ";
            cin >> value;

            
            if (count == n) {
                cout << "ERROR: Stack Overflow\n";
            }
            else {
                Node* newNode = new Node();

                newNode->data = value;
                newNode->next = top;

                top = newNode;
                count++;

                cout << "Current Top: " << top->data << endl;
            }
        }

    
        else if (choice == 2) {

            
            if (top == NULL) {
                cout << "ERROR: Stack Underflow\n";
            }
            else {
                Node* temp = top;

                top = top->next;

                delete temp;

                count--;

                if (top != NULL)
                    cout << "Current Top: " << top->data << endl;
                else
                    cout << "Stack is Empty\n";
            }
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}