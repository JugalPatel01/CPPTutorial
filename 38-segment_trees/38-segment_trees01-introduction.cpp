/*

    * segment Tree

    # why we need segment tree
    * suppose we have given an array [1,2,3,4,5,6] and we have to find sum of given subarray i = 1 to i = 3
      or need to update an element at 4th position.
    -> bruteforce appraoch :
        - for subarray sum it takes O(N) time comeplxity for iterating from 1 to 3
        - for updating element at 4th position it takes time compelxityy O(1). just go to that index and update it.

    -> prefixsum array approach :
        - here we have calculated a prefix sum array for given array so we go to the index 3 and 1 then get the values and
          perform minus operation between those values it takes O(1) time complexity.
        - for updating value we have to update our prefix sum array also so it takes O(N) time complexity.

    so we get
                          bruteforce approach      |      prefix sum array approach
    sum of subarray   :       O(N)                 |               O(1)
    update an element :       O(1)                 |               O(N)

    so to perform both the operations in reasonable time(not more high, not more less) we have to build a new data structure which is called segment tree and it takes O(log(N)) time for both the operations.

    * segment trees

    Given an array : [4 2 1 3 0 7 6 8]

    we uses the approach of divide and conquer to divide above array

                [4 2 1 3 0 7 6 8]
                /               \
         [4 2 1 3]              [0 7 6 8]
            /   \                  /    \
        [4 2]   [1 3]           [0 7]   [6 8]
        /   \   /   \           /   \   /    \
       [4] [2] [1]  [3]        [0] [7] [6]  [8]

       and no. of levels are
            a * rˣ⁻¹ = n
            a = 1, r = 2
            (2)ˣ⁻¹ = n
            log₂(2)ˣ⁻¹ = log₂n
            x = 1 + log₂n
        so , number of levels are : 1 + log₂n
       total nodes in above trees are n + n/2 + n/4 + ... + 1 = 2⁽¹⁺ˡᵒᵍ⁽ⁿ⁾⁾ - 1
                                                              = 2 * 2ˡᵒᵍ⁽ⁿ⁾ - 1
                                                              = 2 * n - 1


        so our sum segment trees is :
                    [   31   ]
                /               \
             [10]               [21]
            /   \               /    \
         [6]     [4]         [7]    [14]
        /   \   /   \       /   \   /   \
       [4] [2] [1]  [3]    [0] [7] [6]  [8]


                          bruteforce approach      |      prefix sum array approach  |      segment tree
    sum of subarray   :       O(N)                 |               O(1)              |          O(log(N))
    update an element :       O(1)                 |               O(N)              |          O(log(N))
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
        sample input : 8 4 2 1 3 0 7 6 8 7 9
    */
    vector<int> segment_tree(4 * n - 1);
    // here we pass array, tree, starting index of tree, starting index of array , ending index of array
    build_st(v, segment_tree, 1, 0, n - 1);

    cout << "segment tree is : " << endl;
    for (auto i : segment_tree)
    {
        cout << i << " ";
    }

    cout << endl;

    int update_idx, update_val;

    cout << "enter index and updated value respectively for update an element : ";
    cin >> update_idx >> update_val;

    update_ele(v, segment_tree, 1, 0, n - 1, update_idx, update_val);

    cout << "array after updation is : " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "segment tree after updation : " << endl;

    for (auto i : segment_tree)
    {
        cout << i << " ";
    }
    return 0;
}