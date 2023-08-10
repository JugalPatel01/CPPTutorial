/*
    * finding subarray sum query in segment tree.

    Q : find sum of subarray from [1,5] in given segment tree.
                [4 2 1 3 0 7 6 8]
    o/p : 13
            [2 1 3 0 7]

    approach :
    -> so here we have to cases :
    1) complete segment  --> if it's complete segment then return that sum
    2) partial segment  --> if it's partial segment then go inside that subtree.

            so our sum segment trees is :
                    [   31   ]  {0-7}
                /               \
             [10] {0-3}          [21]   {4-7}
            /   \               /    \
    {0-1}[6]     [4]{2-3}{4-5}[7]    [14] {6-7}
        /   \   /   \       /   \   /   \
       [4] [2] [1]  [3]    [0] [7] [6]  [8]


    approach :
    here 3 possibilities are possible :
    1) no overlap between segment trees starting and ending position and given subarray's starting and ending position.
       so here we return 0.
    2) if it's fully overlapped then we return that whole segment.
    3) if it's partial overlap then we just use divide and conqure technique.

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

int sub_sum(vector<int> &segment_tree, int node, int node_start, int node_end, int sub_start, int sub_end)
{
    if (sub_end < node_start || sub_start > node_end)
    {
        /*  no overlap
            sub_start ... sub_end ... node_start ... node_end
            node_start ... node_end ... sub_start ... sub_end
        */
        return 0;
    }
    if (sub_start <= node_start && sub_end >= node_end)
    {
        // complete overlap
        return segment_tree[node];
    }

    // partial overlap
    int mid = (node_start + node_end) / 2;
    return sub_sum(segment_tree, 2 * node, node_start, mid, sub_start, sub_end) +
           sub_sum(segment_tree, 2 * node + 1, mid + 1, node_end, sub_start, sub_end);
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

    int sub_start, sub_end;
    cout << "enter starting and ending index of subarray : ";
    cin >> sub_start >> sub_end;

    /*
        sample input : 8 4 2 1 3 0 7 6 8 1 5
    */
    vector<int> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    cout << "sum of sub array " << sub_start << " to " << sub_end << " = " << sub_sum(segment_tree, 1, 0, n - 1, sub_start, sub_end) << endl;


    return 0;
}