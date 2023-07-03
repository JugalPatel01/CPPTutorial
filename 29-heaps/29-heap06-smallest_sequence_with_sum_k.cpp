/*

    * Smallest subsequence with sum K
    Q : given an array and integer k get smallest subsequence with sum is greater than or equal to K.
    i/p : [1 1 3 2 8 ]         k = 13
    o/p : [3 2 8]  -> ANS : 3

    difference between subarray and subsequence :
    subarray : continuous block of elements
    subsequence : Not necessarily continous, but order should remain as in original array
    NOTE : every subarray is subsequence but not vice versa.

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find_subseq(vector<int> v, int k)
{
    priority_queue<int, vector<int>> max_heap;

    for (auto i : v)
    {
        max_heap.push(i);
    }
    int sum = 0, count = 0;
    while (sum < k && !max_heap.empty())
    {
        sum += max_heap.top();
        cout << max_heap.top() << " ";
        max_heap.pop();
        count++;
    }
    cout << endl;
    if (sum >= k)
    {
        return count;
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "enter elements in an array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "Enter targest sum for subsequence : ";
    cin >> k;

    int count = find_subseq(v, k);
    cout << "smallest subsequence with atleast sum " << k << " is : " << count;

    return 0;
}