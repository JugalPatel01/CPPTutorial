/*
    Q : given int k and an array print maximum element in the window.

    i/p : [1,3,-1,-3,5,3,6,7]
        k = 3
    o/p : 3,3,5,5,6,7

    so here we can solve it in two different manners :
    1) using priority queue and sliding window algorithm
    2) using deque and sliding window protocol

    here we will go with first approach
 */
#include <iostream>
#include <set>
#include <vector>
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

    multiset<int, greater<int>> s;
    vector<int> ans;

    // insert k elements into the set
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }

    ans.push_back(*s.begin()); // insert ans from that elements

    for (int i = k; i < n; i++)
    {
        s.erase(s.lower_bound(a[i - k])); // remove first element

        /*
            lower bound is used to return an iterator pointing to the first element in an ordered range [first, last) that is greater than or equal to the specified value.
         */

        s.insert(a[i]);            // insert new element into set
        ans.push_back(*s.begin()); // and again pushback the ans
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
