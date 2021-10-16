#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    //binary search for key in given array.

    int n;
    cout << "enter the number of elements in array ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter the key for searching ";
    cin >> key;

    cout << "index of the key in the array is " << binarySearch(arr, n, key) << endl;
    return 0;
}