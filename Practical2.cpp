#include <iostream>
using namespace std;

// Linear Search Iterative
int linearIterative(int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

// Linear Search Recursive
int linearRecursive(int arr[], int n, int target, int index)
{
    if(index == n)
        return -1;

    if(arr[index] == target)
        return index;

    return linearRecursive(arr, n, target, index + 1);
}

// Binary Search Iterative
int binaryIterative(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Binary Search Recursive
int binaryRecursive(int arr[], int low, int high, int target)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == target)
        return mid;

    if(arr[mid] < target)
        return binaryRecursive(arr, mid + 1, high, target);

    return binaryRecursive(arr, low, mid - 1, target);
}

int main()
{
    int n, target, choice;

    cout << "Enter Size of Array: ";
    cin >> n;

    int arr[n];

    cout << "Enter Array Elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter Target Element: ";
    cin >> target;

    cout << "\n===== MENU =====" << endl;
    cout << "1. Linear Search (Iterative)" << endl;
    cout << "2. Linear Search (Recursive)" << endl;
    cout << "3. Binary Search (Iterative)" << endl;
    cout << "4. Binary Search (Recursive)" << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    int index = -1;

    switch(choice)
    {
        case 1:
            index = linearIterative(arr, n, target);
            break;

        case 2:
            index = linearRecursive(arr, n, target, 0);
            break;

        case 3:
            index = binaryIterative(arr, n, target);
            break;

        case 4:
            index = binaryRecursive(arr, 0, n - 1, target);
            break;

        default:
            cout << "Invalid Choice";
            return 0;
    }

    if(index != -1)
        cout << "Element Found at Position: " << index << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}