#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    string operation, page;

    for (int i = 0; i < n; i++) {
        cout << "Enter operation (visit/back): ";
        cin >> operation;

        if (operation == "visit") {
            cout << "Enter page: ";
            cin >> page;
            history.push(page);
        }
        else if (operation == "back") {
            if (history.size() > 1) {
                history.pop();
            }
        }

        if (!history.empty()) {
            cout << "Current page: " << history.top() << endl;
        }
        else {
            cout << "No page in history" << endl;
        }
    }

    return 0;
}