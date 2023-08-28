/*

    * Place elements to Maximise Minimum Distance
    Q : Given is an array with n elements that represents n positions along a straight line. Find K elements such
        that the minimum distance between any 2 elements is the maximum possible.

    i/p : [11, 2, 7, 5, 1, 12]          k = 3
    o/p :
            [1,7,12]        with distance = minimum 5


    explaination :

        [1, 2, 5, 7, 11, 12]  and k = 3
        so we have to find out 3 elements from this array which have highest possible distance
        eg. [1,5,11] has minimum 4 distance
            [1,7,12] has minimum 5 distance
            so it answer of above question is [1,7,12] with 5 distance .

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool has_value(vector<int> v, int val, int k)
{
    int n = v.size() - 1;
    int pos = v[0];
    k--;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] - pos >= val)
        {
            pos = v[i];
            k--;
        }
    }
    if (k > 0)
    {
        return false;
    }
    return true;
}

int find_distance(vector<int> v, int k)
{
    int n = v.size() - 1;
    int ans = -1;
    int left = v[0];
    int right = v[n];

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (has_value(v, mid, k))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return ans;
}

int main()
{

    int n, k, ans_size;
    cout << "enter size of an array : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());

    cout << "enter no. of elements to find out with maximum distance between them from an array : ";
    cin >> k;
    if (k < n)
    {
        ans_size = find_distance(v, k);
    }
    else
    {
        cout << "more no. of elements entered :< " << endl;
        return 0;
    }

    vector<int> ans;
    int position = v[0];
    ans.push_back(position);

    for (int i = 0; i < n; i++)
    {
        if (v[i] - position >= ans_size)
        {
            position = v[i];
            ans.push_back(v[i]);
        }
    }

    cout << "k elements with distance " << ans_size << " are : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}