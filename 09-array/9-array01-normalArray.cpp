#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter total no. of elements in array : ";
    cin >> n;
    int array[n];

    cout << "Enter elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        array[i] = x;
    }

    cout << "elements in array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
        cout << i[array] << "\t";
    }

    return 0;
}