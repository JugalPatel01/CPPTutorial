/*

    * Maximum Perfect Numbers in length k
    Q : For a given arrayand an integer K, find the maximum perfect numbers in a subarray of size K.
    ->  Perfect Number : Number is equal to the sum of it's proper devisors.
    eg. 6 = 1 + 2 + 3 = 6
    i/p : [ 1 2 6 28 496 86 99 8128]    k = 4;
    o/p : 3         // 6 28 496

 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> find_perfect(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            v[i] = 0;
            continue;
        }
        int sum = 1;
        for (int j = 2; j <= sqrt(v[i]); j++)
        {
            if (v[i] % j == 0)
            {
                if (j == v[i] / j)
                {
                    sum += j;
                }
                else
                {
                    sum += j + (v[i] / j);
                }
            }
        }
        if (sum == v[i])
        {
            v[i] = 1;
        }
        else
        {
            v[i] = 0;
        }
    }
    return v;
}

int max_perfect(vector<int> v, int k)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    ans = sum;
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i] - v[i - k];
        ans = max(sum, ans);
    }
    return ans;
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

    vector<int> perfect_Number = find_perfect(v);

    int find_max_perfect = max_perfect(perfect_Number, k);

    if (k < n)
    {
        cout << "maximum perfect numbers in subarray of size " << k << " are : " << find_max_perfect << endl;
    }
    else
    {
        cout << "given size of subarray is greater than array size :< " << endl;
    }

    return 0;
}