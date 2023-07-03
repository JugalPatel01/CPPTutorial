/*

    * Number formed from subarray of size K, divisible by 3
    Q : For a given array and an integer K, check if any subarray of size K exists in the array such that elements in the
        subarray form a number divisible by 3.

    i/p : [8 23 45 12 56 4]         k = 3
    o/p : [12564] yes
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

bool check_exist(vector<int> v, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    if (sum % 3 == 0)
    {
        for (int i = 0; i < k; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        return true;
    }
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i] - v[i - k];
        if (sum % 3 == 0)
        {
            for (int j = i - k + 1; j <= i; j++)
            {
                cout << v[j] << " ";
            }

            cout << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "enter no. of elements in an array : ";
    cin >> n;
    cout << "enter elements of an array : ";
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int k;

    cout << "size of subarray is : ";
    cin >> k;

    if (k < n)
    {
        bool check = check_exist(v, k);
        cout << "is there any subarray of size " << k << " exist in array whose generated no. is divided by 3 ? : " << check;
    }

    return 0;
}