/*

    * Segment with the maximum sum
    Q : we have given an array. we have to make a segment tree to find the segment with the maximum sum.
    NOTE : if sum is negative then we have choice to not to choose any element in segment so sum is 0 for that case.
    i/p : element in array : 5 elements : [4 -3 4 3 -5]
    o/p : 8
        segment [4 -3 4 3 ]  gives us sum 8

    hint : it is just like finding a maximum contiguous elements sum.


    approach :
    -> each node of segment tree contains four kind of information :
        1) maximum prefix sum
        2) maximum suffix sum
        3) sum of prefix and suffix sum
        4) ans for maximum sum of the segment

*/
#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

struct segNode
{
    int pre_sum, suff_sum, sum, ans;
};

void build_st(vector<int> &v, vector<segNode> &segment_tree, int node, int start, int end)
{
    if (start == end)
    {
        segment_tree[node].pre_sum = max(v[start], 0);
        segment_tree[node].suff_sum = max(v[start], 0);
        segment_tree[node].sum = v[start];
        segment_tree[node].ans = max(v[start], 0);
        return;
    }
    int mid = (start + end) / 2;

    build_st(v, segment_tree, 2 * node, start, mid);
    build_st(v, segment_tree, 2 * node + 1, mid + 1, end);

    segment_tree[node].pre_sum = max(segment_tree[2 * node].sum + segment_tree[2 * node + 1].pre_sum, segment_tree[2 * node].pre_sum);
    segment_tree[node].suff_sum = max(segment_tree[2 * node + 1].sum + segment_tree[2 * node].suff_sum, segment_tree[2 * node + 1].suff_sum);
    segment_tree[node].sum = segment_tree[2 * node].sum + segment_tree[2 * node].sum;
    segment_tree[node].ans = max(segment_tree[2 * node].ans, max(segment_tree[2 * node + 1].ans, segment_tree[2 * node].suff_sum + segment_tree[2 * node + 1].pre_sum));
}

void update_seg(vector<int> &v, vector<segNode> &segment_tree, int node, int start, int end, int update_idx, int update_value)
{
    if (start == end)
    {
        v[update_idx] = update_value;
        segment_tree[node].pre_sum = max(v[start], 0);
        segment_tree[node].suff_sum = max(v[start], 0);
        segment_tree[node].sum = v[start];
        segment_tree[node].ans = max(v[start], 0);
        return;
    }

    int mid = (start + end) / 2;

    if (update_idx <= mid)
    {
        update_seg(v, segment_tree, 2 * node, start, mid, update_idx, update_value);
    }
    else
    {
        update_seg(v, segment_tree, 2 * node + 1, mid + 1, end, update_idx, update_value);
    }

    segment_tree[node].pre_sum = max(segment_tree[2 * node].sum + segment_tree[2 * node + 1].pre_sum, segment_tree[2 * node].pre_sum);
    segment_tree[node].suff_sum = max(segment_tree[2 * node + 1].sum + segment_tree[2 * node].suff_sum, segment_tree[2 * node + 1].suff_sum);
    segment_tree[node].sum = segment_tree[2 * node].sum + segment_tree[2 * node].sum;
    segment_tree[node].ans = max(segment_tree[2 * node].ans, max(segment_tree[2 * node + 1].ans, segment_tree[2 * node].suff_sum + segment_tree[2 * node + 1].pre_sum));
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
        sample input : 5 4 -3 4 3 -5 4 1
    */

    vector<segNode> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    cout << "maximum sum is for segment is : " << segment_tree[1].ans << endl;

    cout << "enter index and new value respectivaly for updation : ";
    int update_idx, udpate_value;
    cin >> update_idx >> udpate_value;

    update_seg(v, segment_tree, 1, 0, n - 1, update_idx, udpate_value);

    cout << "after updating the value the maximum sum of segment is : " << segment_tree[1].ans << endl;

    return 0;
}