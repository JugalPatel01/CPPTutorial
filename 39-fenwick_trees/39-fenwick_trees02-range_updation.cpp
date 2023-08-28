/*

       * Range sum with range updates

    Q. we have an array containing n elements initially all O.
       we need to do 'u' number of update operations on it. In each update we specify left index , right index and value to be 
       added. After each update, we add the 'value' to all elements from index left to right index. After 'u' updates are over, 
       there will be q queries each containing an index for which you have to print the sum element at that index.

    Q-1. update the element in the tree :
         add given value in range 'L' to 'R'
     appraoch :
          we update the segment binary_index_tree[l] to binary_index_tree[n] with 'val'
          and update the segment binary_index_tree[r+1] to binary_index_tree[n] with '-(val)'

    Q-2. Get the sum of value from starting idx to given idx :
            sum[idx] = v[0] + v[1] + ... v[idx]
            
*/

#include <iostream>
#include <vector>
using namespace std;

void update_BIT(vector<int> &binary_search_tree, int idx, int total_elements, int val)
{
    while (idx <= total_elements)
    {
        binary_search_tree[idx] += val;
        idx += ((idx) & (-idx));
    }
}

int query(vector<int> &binary_search_tree, int idx, int total_elements)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += binary_search_tree[idx];
        idx -= ((idx) & (-idx));
    }
    return ans;
}

int main()
{
    int n, update_query;
    cout << "enter total number of elements in the array : ";
    cin >> n;
    vector<int> binary_search_tree(n + 2, 0);

    // update queries
    cout << "enter total update queries : ";
    cin >> update_query;
    for (int i = 0; i < update_query; i++)
    {
        int left_idx, right_idx, val;
        cout << "enter left and right index in 1's based indexing of range for updation : ";
        cin >> left_idx >> right_idx;

        cout << "enter value for updation for given range : ";
        cin >> val;

        update_BIT(binary_search_tree, left_idx, n, val);
        update_BIT(binary_search_tree, right_idx + 1, n, -val);
    }

    /*

        sample input : 5
                       3
                       1 2 7
                       3 5 6
                       2 4 2
                       3
                       1
                       4
                       5
     */

    // it's 1-based indexing

    cout << "enter total no. of fetching quereies : ";
    int fetching_idx, idx;
    cin >> fetching_idx;
    for (int i = 0; i < fetching_idx; i++)
    {
        cout << "enter index number in 1-based indexing : ";
        cin >> idx;
        cout << "element at given index " << idx << " is : " << query(binary_search_tree, idx, n) << endl;
    }

    return 0;
}