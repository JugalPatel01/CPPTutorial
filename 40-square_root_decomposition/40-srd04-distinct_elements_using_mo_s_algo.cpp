/*

    Q. Given an array and K queries with starting and ending indices. for each queires we have to return the number of distinct
       elements in the subsequences.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Q
{
    int start, end, index;
};

int len;

bool cmp(Q q1, Q q2)
{
    if (q1.start / len == q2.start / len)
    {
        return q1.end > q2.end;
    }
    return (q1.start / len < q2.start / len);
}

int main()
{
    int n;
    cout << "enter total no. of elements in the array : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    len = sqrtl(n);
    /*

        sample input : 5 2 2 3 2 4
                       3
                       0 4
                       1 3
                       2 4
    */

    int k;
    cout << "enter total no. of queries : ";
    cin >> k;
    vector<Q> queries(k);
    vector<int> ans(k);
    cout << "enter all the queries simultanously : ";
    for (int i = 0; i < k; i++)
    {
        queries[i].index = i;

        cin >> queries[i].start >> queries[i].end;
    }

    sort(queries.begin(), queries.end(), cmp);

    int start, end, curr_start = 0, curr_end = -1, curr_ans = 0;
    unordered_map<int, int> check;

    for (int i = 0; i < k; i++)
    {
        start = queries[i].start;
        end = queries[i].end;

        while (curr_start < start)
        {
            check[v[curr_start]]--;
            if (check[v[curr_start]] == 0)
            {
                curr_ans--;
            }
            curr_start++;
        }
        while (curr_start > start)
        {
            curr_start--;
            if (check[v[curr_start]] == 0)
            {
                curr_ans++;
            }
            check[v[curr_start]]++;
        }
        while (curr_end < end)
        {
            curr_end++;
            if (check[v[curr_end]] == 0)
            {
                curr_ans++;
            }
            check[v[curr_end]]++;
        }
        while (curr_end > end)
        {
            check[v[curr_end]]--;
            if (check[v[curr_end]] == 0)
            {
                curr_ans--;
            }
            curr_end--;
        }

        ans[queries[i].index] = curr_ans;
        cout << "here" << i;
    }
    cout << "answer of all queries : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}