//subarray and subsequence.
/* subarry 
   --> continuous part of the array.

    no. of subarray of an arry with n elements= (nC2)+n = n*(n+1)/2

    subsequence
   --> A subsequence is a sequence that can be derived an array by selecting zero or more elements, without changing the order of the remaining elements.

    no. of subsequences of an array with n elements == 2^n.

    every subarray is a subsequence but every subsequence is not subarray.
 */
#include <iostream>
using namespace std;
int main()
{
    //sum of all subarray.
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "sum of individual subarray of this array are \n";
    int sum = 0;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            curr = 0;
            for (int k = i; k <= j; k++)
            {
                curr += arr[j];
                cout << curr << endl;
            }

            sum += curr;
        }
    }
    cout << "sum of all subarray's sum is " << sum << endl;

    return 0;
}