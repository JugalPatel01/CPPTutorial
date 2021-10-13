//Maximum subarray sum by kadane's algoritm
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

    int currsum = 0;
    int maxsum = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxsum = max(maxsum, currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }

    cout << "max sum of subarray is " << maxsum << endl;

    return 0;
}