#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int h;
    cout << "Enter rotation value: ";
    cin >> h;

    h %= n;

    // Left rotation using reversal algorithm
    reverse(v.begin(), v.begin() + h);
    reverse(v.begin() + h, v.end());
    reverse(v.begin(), v.end());

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}