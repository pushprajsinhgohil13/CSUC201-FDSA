#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements (only 0, 1, or 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lo = 0;
    int mid = 0;
    int hi = n - 1;

    while (mid <= hi)
    {
        if (arr[mid] == 0)
        {
            swap(arr[lo], arr[mid]);
            lo++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[hi]);
            hi--;
        }
        else
        {
            cout << "Invalid element! Enter only 0, 1, or 2." << endl;
            return 0;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}