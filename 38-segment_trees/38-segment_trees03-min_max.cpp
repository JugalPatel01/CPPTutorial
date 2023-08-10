/*

    * Maximum and Minimum Queries/updates

    Q : given an array v of size n. we have to give result of following operations.
        1) query : output the maximum/minimum for the sub-array v[i...j]
        2) update : update the ith element of the array. v[i] = updated_value_x

    i/p : total nodes = 8 nodes = [4 7 -2 9 -1 2 1 3] query : 1 5 update : a[7] = 11
    o/p : maximum -> 9 minimum -> 2

    approach :

    query :
    -> In query we have to do work with subarray. so that subarray might be a fully overlaped or partially overlapped with the
       segment.
    -> so, we have to make two different segment trees for finding maximum and minimum from that subarray.

    update :
    -> first we have to update the given node and then we have to make changes in the segment tree according to that updation.

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

void max_build_st(vector<int> &v, vector<int> &segment_tree, int node, int start, int end)
{
    if (start == end)
    {
        segment_tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;

    max_build_st(v, segment_tree, 2 * node, start, mid);
    max_build_st(v, segment_tree, 2 * node + 1, mid + 1, end);

    segment_tree[node] = max(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

void min_build_st(vector<int> &v, vector<int> &segment_tree, int node, int start, int end)
{
    if (start == end)
    {
        segment_tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;

    min_build_st(v, segment_tree, 2 * node, start, mid);
    min_build_st(v, segment_tree, 2 * node + 1, mid + 1, end);

    segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

int find_max(vector<int> &segment_tree, int node, int start, int end, int query_start, int query_end)
{
    if (start > query_end || end < query_start)
    {
        return INT_MIN;
    }
    if (query_start >= start && query_end <= end)
    {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    return max(find_max(segment_tree, 2 * node, start, mid, query_start, query_end), find_max(segment_tree, 2 * node + 1, mid + 1, end, query_start, query_end));
}

int find_min(vector<int> &segment_tree, int node, int start, int end, int query_start, int query_end)
{
    if (start > query_end || end < query_start)
    {
        return INT_MAX;
    }
    if (query_start >= start && query_end <= end)
    {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    return min(find_min(segment_tree, 2 * node, start, mid, query_start, query_end), find_min(segment_tree, 2 * node + 1, mid + 1, end, query_start, query_end));
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
        sample input : 8 4 7 -2 9 -1 2 1 3 1 5
    */

    vector<int> max_segment_tree(4 * n - 1);
    vector<int> min_segment_tree(4 * n - 1);

    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    max_build_st(v, max_segment_tree, 1, 0, n - 1);
    min_build_st(v, min_segment_tree, 1, 0, n - 1);

    int query_start, query_end;
    cout << "enter subarray's starting and ending indices respectively : ";
    cin >> query_start >> query_end;

    cout << "maximum in subarray start from " << query_start << " to " << query_end << " Is : " << find_max(max_segment_tree, 1, 0, n - 1, query_start, query_end) << endl;
    cout << "minimum in subarray start from " << query_start << " to " << query_end << " Is : " << find_min(min_segment_tree, 1, 0, n - 1, query_start, query_end) << endl;

    return 0;
}