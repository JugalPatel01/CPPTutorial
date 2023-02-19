/*
    Wave sort

    # here we have to sort array in the wave form means
    arr[0] >= arr[1]<= arr[2] >= arr[3] <= arr[4] ...

    time complexity of this algo is O(n/2) = O(n)
*/

#include <iostream>
using namespace std;

void WaveSort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if ((arr[i] > arr[i + 1]) && (i < n - 1))
        {
            swap(arr[i], arr[i + 1]);
        }
    }
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
    WaveSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}