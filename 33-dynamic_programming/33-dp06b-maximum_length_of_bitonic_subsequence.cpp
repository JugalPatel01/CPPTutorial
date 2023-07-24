/*

    * Maximum length bitonic subsequences
    # bitonic subsequences : A subsequence is bitonic if it is first strictly increasing and then strictly decreasing or
                             entirely increasing or decreasing.

    Q : Given an array of n numbers. Find the maximum length of bitonic subsequence.
    i/p : elements_of_an_array = 8  array : [1 9 3 10 4 5 2 1]
    o/p : 6
        maximum length = [1,3,4,5,2,1 ] = 6
                       = [1,9,10,5,2,1 ] = 6

    This problem is same as finding size of maximum increasing subsequence.
    -> here, we have to find and store increasing subsequence on ith element of an array.
    -> then we have to find and store decreasing subsequence on ith element of an array.
    -> now maximum length bitonic subsequence = increasing_subseq[i] + decreasing_subseq[i] - 1;
        because here we count ith element for 2 times.


*/
#include <iostream>
#include <vector>
using namespace std;

int find_bitonic(vector<int> &v)
{
    vector<int> increase(v.size() + 1, 1), decrease(v.size() + 1, 1);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
                increase[i] = max(increase[i], 1 + increase[j]);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        for (int j = v.size() - 1; j > i; j--)
        {
            if (v[i] > v[j])
                decrease[i] = max(decrease[i], 1 + decrease[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, increase[i] + decrease[i] - 1);
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter total no. of element in array : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }

    /*

        sample input : 8 1 9 3 10 4 5 2 1

    */
    cout << "maximum length of bitonic subsequence is : " << find_bitonic(v);
    return 0;
}