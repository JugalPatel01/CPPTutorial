/*

    * optimal pattern merge
    Q : given n files with their computation time in an array.
    Operation : choose/take any two files, add their computation times and append it to the list of computation times.
    Do this until we are left with only one file in the array. we have to do this operation such that we get minimum cost finally.

    i/p : 5 2 4 7
    o/p : 18
          1st merge : [2 4]     -> 6
          2nd merge : [5 6]     -> 11
          3rd merge : [7 11]    -> 18
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find_time(vector<int> &v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (auto i : v)
    {
        pq.push(i);
    }
    while (pq.size() != 1)
    {
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();
        ans = ans + top1 + top2;
        pq.push(top1 + top2);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter total number of files : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter time taken by one file for operation : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "minimum operations to merge these files is : " << find_time(v) << endl;
    return 0;
}