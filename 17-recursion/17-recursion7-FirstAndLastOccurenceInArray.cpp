#include <iostream>
using namespace std;
int firstoccu(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstoccu(arr, n, i + 1, key);
}
int lastoccu(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    int restArray = lastoccu(arr, n, i + 1, key);

    if (restArray != -1)
    {
        return restArray;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter the key" << endl;
    cin >> key;

    cout << "index of the first occurance of key in array is " << firstoccu(arr, n, 0, key) << endl;
    cout << "index of the last occurance of key in array is " << lastoccu(arr, n, 0, key) << endl;

    return 0;
}