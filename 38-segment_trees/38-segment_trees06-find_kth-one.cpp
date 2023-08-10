/*

    Q : update the index's value with it's opposite value and find k-th one in the given segment tree.
    i/p : element in array : 5 , elements [1 1 1 0 1] , find_one = 3rd one , change_idx = 2 , find_one = 3rd one
    o/p : index of 3rd 1 is 2.
          after changing index at 2 our array will become [1 1 0 0 1]
          so now index of 3rd 1 is 4.
*/

#include <iostream>
#include <vector>
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

    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
}

int query(vector<int> &segment_tree, int node, int start, int end, int idx)
{
    if (start == end)
    {
        return start;
    }
    int mid = (start + end) / 2, ans;
    if (idx <= segment_tree[2 * node])
    {
        ans = query(segment_tree, 2 * node, start, mid, idx);
    }
    else
    {
        // here we subtracting left segment's sum so we get right segment's sum
        ans = query(segment_tree, 2 * node + 1, mid + 1, end, idx - segment_tree[2 * node]);
    }
    return ans;
}

void update_ele(vector<int> &v, vector<int> &segment_tree, int node, int start, int end, int update_idx)
{
    if (start == end)
    {
        v[update_idx] = (v[update_idx] == 1) ? 0 : 1;
        segment_tree[node] = v[update_idx];
        return;
    }

    int mid = (start + end) / 2;

    if (update_idx <= mid)
    {
        update_ele(v, segment_tree, 2 * node, start, mid, update_idx);
    }
    else
    {
        update_ele(v, segment_tree, 2 * node + 1, mid + 1, end, update_idx);
    }

    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
    return;
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
        sample input : 5 1 1 1 0 1 3 2 3
    */
    vector<int> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    int k;
    cout << "enter k-th one : ";
    cin >> k;

    cout << "index of k-th one is : " << query(segment_tree, 1, 0, n - 1, k) << endl;

    int update_idx;

    cout << "enter index for update an element : ";
    cin >> update_idx;

    update_ele(v, segment_tree, 1, 0, n - 1, update_idx);

    cout << "enter k-th one : ";
    cin >> k;

    cout << "index of k-th one is : " << query(segment_tree, 1, 0, n - 1, k) << endl;
    return 0;
}