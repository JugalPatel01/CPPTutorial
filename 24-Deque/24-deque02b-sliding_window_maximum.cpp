/*
    it's an optimized approach for sliding window protocol

    Q : given int k and an array print maximum element in the window.

    i/p : [1,3,-1,-3,5,3,6,7]
        k = 3
    o/p : 3,3,5,5,6,7
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // input start
    int n, k;
    cout << "enter size of the array :";
    cin >> n;
    vector<int> a(n);
    cout << "enter elements of the array : ";
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << "enter value of k : ";
    cin >> k;
    // input end

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && a[q.back()] < a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for (int i = k; i < n; i++)
    {
        if (q.front() == i - k)
        {
            q.pop_front();
        }

        while (!q.empty() && a[q.back()] < a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    cout << " ans is : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}