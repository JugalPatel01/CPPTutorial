/*

    * Number of Minimums on a segment
    Q : we have given an array . we have to build a segment tree for finding minimum value and also count the number of elements
        equal to the minimum.
    i/p : total elements : 5 elements of array [3 4 3 5 2] subarray 0 2 
    o/p : 3 2
            in subarray [3 4 3] we get minimum is 3 and it's frequency is 2. 

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void build_st(vector<int> &v, vector<pair<int, int>> &segment_tree, int node, int start, int end)
{
    if (start == end)
    {
        segment_tree[node].first = v[start];
        segment_tree[node].second = 1;
        return;
    }
    int mid = (start + end) / 2;

    build_st(v, segment_tree, 2 * node, start, mid);
    build_st(v, segment_tree, 2 * node + 1, mid + 1, end);

    if (segment_tree[2 * node].first < segment_tree[2 * node + 1].first)
    {
        segment_tree[node] = segment_tree[2 * node];
    }
    else if (segment_tree[2 * node].first > segment_tree[2 * node + 1].first)
    {
        segment_tree[node] = segment_tree[2 * node + 1];
    }
    else
    {
        segment_tree[node].first = segment_tree[2 * node].first;
        segment_tree[node].second = segment_tree[2 * node].second + segment_tree[2 * node + 1].second;
    }
}

pair<int, int> find_query(vector<pair<int, int>> &segment_tree, int node, int start, int end, int query_start, int query_end)
{
    if (start > query_end || end < query_start)
    {
        return {INT_MAX, -1};
    }
    if (query_start >= start && query_end <= end)
    {
        return segment_tree[node];
    }

    int mid = (start + end) / 2;

    pair<int, int> ans1 = find_query(segment_tree, 2 * node, start, mid, query_start, query_end);
    pair<int, int> ans2 = find_query(segment_tree, 2 * node + 1, mid + 1, end, query_start, query_end);

    pair<int, int> ans;
    if (ans1.first < ans2.first)
    {
        ans = ans1;
    }
    else if (ans1.first > ans2.first)
    {
        ans = ans2;
    }
    else
    {
        ans.first = ans1.first;
        ans.second = ans1.second + ans2.second;
    }
    return ans;
}

void update(vector<int> &v, vector<pair<int, int>> &segment_tree, int node, int start, int end, int update_idx, int update_value)
{
    if (start == end)
    {
        v[start] = update_value;
        segment_tree[node].first = update_value;
        segment_tree[node].second = 1;
        return;
    }

    int mid = (start + end) / 2;
    if (update_idx <= mid)
    {
        update(v, segment_tree, 2 * node, start, mid, update_idx, update_value);
    }
    else
    {
        update(v, segment_tree, 2 * node + 1, mid + 1, end, update_idx, update_value);
    }

    if (segment_tree[2 * node].first < segment_tree[2 * node + 1].first)
    {
        segment_tree[node] = segment_tree[2 * node];
    }
    else if (segment_tree[2 * node].first > segment_tree[2 * node + 1].first)
    {
        segment_tree[node] = segment_tree[2 * node + 1];
    }
    else
    {
        segment_tree[node].first = segment_tree[2 * node].first;
        segment_tree[node].second = segment_tree[2 * node].second + segment_tree[2 * node + 1].second;
    }
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
        sample input : 8 4 2 1 3 0 7 6 8 1 5 4 11
    */

    vector<pair<int, int>> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    int query_start, query_end;
    cout << "Enter starting and ending index for the query respectivaly : ";
    cin >> query_start >> query_end;
    pair<int, int> ans_query = find_query(segment_tree, 1, 0, n - 1, query_start, query_end);

    cout << "minimum element in the given range is : " << ans_query.first << " and it's frequency is : " << ans_query.second << endl;

    int update_idx, update_value;
    cout << "enter index and new value for updating value : ";
    cin >> update_idx >> update_value;
    update(v, segment_tree, 1, 0, n - 1, update_idx, update_value);

    for (auto i : segment_tree)
    {
        cout << i.first << " ";
    }

    return 0;
}