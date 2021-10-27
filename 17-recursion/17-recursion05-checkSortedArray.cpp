#include <iostream>
using namespace std;

bool assend(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }

    bool sorted = assend(arr + 1, n - 1);

    return (arr[0] < arr[1] && sorted);
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

    cout << "sorted or not ? (1 or 0) --> " << assend(arr, n) << endl;

    return 0;
}