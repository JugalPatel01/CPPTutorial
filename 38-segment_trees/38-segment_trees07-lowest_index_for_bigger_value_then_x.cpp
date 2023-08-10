/*

    * Segment tree and binary serach
    Q : Given an array a of size n. we have to build a segment tree and we have given a value x we have to find minimum
        index i such that a[i] >= x.
    NOTE : If there is no bigger or equal element then return -1.
    i/p : elements in array : 5 elements [1 3 2 4 6]  value x = 5
    o/p : 4

    approach :
    -> build a maximum segment tree.
    -> so we get a kind of sorted array for maximum value.
    -> now on sorted array we can apply a binary search for finding the index.

    binary search return us one value y and on that value there are two cases :
    1) y < x -> means there is no element with value greater or equal to the x.
    2) y >= x -> go for further move of binary search
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

void build_st(vector<int> &v, vector<int> &segment_tree, int node, int start, int end)
{
    if (start == end)
    {
        segment_tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;

    build_st(v, segment_tree, 2 * node, start, mid);
    build_st(v, segment_tree, 2 * node + 1, mid + 1, end);

    segment_tree[node] = max(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

void update_ele(vector<int> &v, vector<int> &segment_tree, int node, int start, int end, int update_idx, int update_value)
{
    if (start == end)
    {
        v[update_idx] = update_value;
        segment_tree[node] = update_value;
        return;
    }

    int mid = (start + end) / 2;

    if (update_idx <= mid)
    {
        update_ele(v, segment_tree, 2 * node, start, mid, update_idx, update_value);
    }
    else
    {
        update_ele(v, segment_tree, 2 * node + 1, mid + 1, end, update_idx, update_value);
    }

    segment_tree[node] = max(segment_tree[2 * node], segment_tree[2 * node + 1]);
    return;
}

int query(vector<int> &segment_tree, int node, int start, int end, int query_start, int query_end)
{
    if (start > query_end || end < query_start)
    {
        return INT_MIN;
    }
    if (query_start <= start && query_end >= end)
    {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    int left = query(segment_tree, 2 * node, start, mid, query_start, query_end);
    int right = query(segment_tree, 2 * node + 1, mid + 1, end, query_start, query_end);
    return max(left, right);
}

int main()
{
    int n;
    cout << "enter total no. of element in array : ";
    cin >> n;
    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    /*
        sample input : 5 1 3 2 4 6 5
    */
    vector<int> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    int x;
    cout << "enter value x for finding lowest index which has higher value then x : ";
    cin >> x;

    int query_start = 0, query_end = n - 1, ans = n;
    while (query_start <= query_end)
    {
        int mid = (query_start + query_end) / 2;
        int y = query(segment_tree, 1, 0, n - 1, query_start, mid);
        if (y < x)
        {
            query_start = mid + 1;
        }
        else
        {
            /*
                -> here we are taking assumption that our mid is highter then x so we do query_end = mid-1.
                -> so if mid element is a higher then x then we got the index, now if in the binary search of left part we get
                   the lower index than mid then we update the ans value otherwise mid is the higher element then x.
            */
            query_end = mid - 1;
            ans = min(ans, mid);
        }
    }

    if (ans == n)
    {
        cout << "enter value x for finding minimum index i such that arr[i] >= k : " << -1;
    }
    else
    {
        cout << "enter value x for finding minimum index i such that arr[i] >= k : " << ans;
    }
    return 0;
}