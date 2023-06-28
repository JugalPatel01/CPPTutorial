/*
    Passing array as a argument in the function
*/

#include <iostream>
using namespace std;

int SumOfElements(int arr[], int n) // int arr[] is same as int* arr
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i]; // arr[i] == *(arr+i)
        arr[i] *= 2;
    }
    return sum;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    cout << "sum of elements of array is : " << SumOfElements(&arr[0], sizeof(arr) / sizeof(arr[0])) << endl; // &arr[0] is same as arr

    cout << "modified array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}