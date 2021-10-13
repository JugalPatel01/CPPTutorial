/* find a unique number in an array where all numbers except one, are present twice */

#include <iostream>
using namespace std;
/* here  we use property of xor 
    x   y  x^y
    0   0   0
    0   1   1
    1   0   1
    1   1   0

    so if we do n^n then we get 0 ans so after all xor execution we get unique number and all same number became null.


 */

int unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
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

    cout << "unique number is " << unique(arr, n) << endl;

    return 0;
}