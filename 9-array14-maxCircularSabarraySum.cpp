// Maximum Circular Subarray Sum

#include <iostream>
#include <limits.h>
using namespace std;
int kadane(int arr[], int n)
{

    int currsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];

        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(currsum, maxsum);
    }

    return maxsum;
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
    int wrapsum;
    int nonwrapsum;

    nonwrapsum = kadane(arr, n);
    int totalsum = 0;

    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = totalsum + kadane(arr, n);

    cout << "Maximum cirular sabarray sum is " << max(wrapsum, nonwrapsum) << endl;

    return 0;
}