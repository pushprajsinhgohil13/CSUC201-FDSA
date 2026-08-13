#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of book IDs: ";
    cin >> n;

    unordered_map<int, int> library;

    cout << "Enter book IDs:"<<endl;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        library[id]++;
    }

    bool found = false;

    cout << "Duplicate Book IDs:"<<endl;

    for (const auto &book : library)
    {
        if (book.second > 1)
        {
            cout << "Book ID: " << book.first
                 << " (Count = " << book.second << ")\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No duplicate book IDs found.\n";
    }

    return 0;
}