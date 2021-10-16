#include <iostream>
using namespace std;
int main()
{
    //selection sort for sorting
    int n;
    cout << "enter the size of the array ";
    cin >> n;

    int arr[n];
    cout << "enter elments of array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    cout << "sorted array is ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}