#include <iostream>
#include <limits.h>
using namespace std;
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
    int sum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currsum = 0;
            for (int k = i; k <= j; k++)
            {
                currsum += arr[j];
            }

            sum = max(sum, currsum);
        }
    }
    cout << "maximum sum of subarray is " << sum << endl;

    return 0;
}