/*
    * range minimum query using square root decomposition
    Q. We are given an array and k queries.for each queries we have to give a minimum number in that range.
    -> i/p : no of elements = 5 ; elements = [5 3 6 7 2]; k = 2; 0 2; 1 4
       o/p : 3 2

    approach :
    here we apply same logic as range sum query rather then finding the sum we will find minimum element in the specific range.

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "enter total no. of elements in the array : ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    /*

        sample input : 5 5 3 6 7 2 2 0 2 1 4
    */

    int len = sqrtl(n);

    vector<int> pre_cal(len + 1, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        pre_cal[i / len] = min(pre_cal[i / len], v[i]);
    }

    int k;
    cout << "enter total no. of queries : ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int start, end, ans = INT_MAX;
        cout << "enter range of the query : ";
        cin >> start >> end;

        for (int j = start; j <= end;)
        {
            if (j % len == 0 && j + len < end)
            {
                ans = min(ans, pre_cal[j / len]);
                j += len;
            }
            else
            {
                ans = min(ans, v[j]);
                j++;
            }
        }

        cout << "minimum element in the range : " << start << " to " << end << " is : " << ans << endl;
    }

    return 0;
}