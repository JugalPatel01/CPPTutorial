/* 

Given an array arr[] of size N. The task is to find the first repeating element in the array of inetegers.
i.e., an element that occurs more than once and whose index of first occurrence is smallest.    

 */

#include <iostream>
#include<limits.h>
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

    static int idx[10000000];
    int minidx = INT_MAX;

    for (int i = 0; i < 10000000; i++)
    {
        idx[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minidx = min(idx[arr[i]], minidx);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }
    cout << "first occurrence with smallest index's number's index is " << minidx + 1 << endl;

    return 0;
}