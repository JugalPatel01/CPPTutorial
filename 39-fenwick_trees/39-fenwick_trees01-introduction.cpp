/*

    * Fenwick Trees (Binary Index Tree)

    Q : Given an array, find the sum of array[L,R]
    i/p : n = 5 , elements = [1,2,3,4,5] , query : sum(2,4) , update index 2's element in 5,  query : sum(2,4)
    o/p : 12 14

    brute force approach :
    -> go to first index and find the sum through iterating the array.
    -> it takes O(n) time compleixty for every query.
    -> for updation it takes O(1) time compelxity.

    prefix sum array approach :
    -> here we make one prefix array in O(n) time complexity.
    -> the for query we just go to those index take sum and do minus operation.
    -> sum(start,end) = prefix_sum(end) - prefix_sum(start-1).
    -> it takes O(1) time compelxity for every query.
    -> for updation it takes O(n) time complexity.

    so to perform both the operations efficiently we need fenwick trees.

    # Fenwick trees.
    suppose we have 8 elements. if we indicate every position with binary number then we get
    8 = 1000
    7 = 0111
    6 = 0110
    5 = 0101
    4 = 0100
    3 = 0011
    2 = 0010
    1 = 0001

    here every element's lsb has responsibility for that much elements.
    suppose, we take 8 then it's LSB indicates 8 so, it has responsibility of all 8 elements.
    suppose, we take 4 then it's LSB indicates 4 so, it has responsibility of 4 elements.
    suppose, we take 5 then it's LSB indicates 1 so, it has responsibility of only 1 element.

    now suppose we want sum of sum(1,6) then we have to do sum of A[6] + A[4].
    sum(1,6) = A[6] + A[4]
               6 is responsible for 2 elements 6 and 5 according to it's LSB.
               (6 - LSB(6) = 6 - 2 = 4)
               4 is responsible for 4 elements 4,3,2 and 1 according to it's LSB.

    now suppose we want to update element on 7th index then we have to change only those element which are affected by updation
    of this element.
    update(7) = A[7],A[8]
                7 is responsible for 1 element so we have to update 7.
                (7 + LSB(7) = 7 + 1 = 8)
                8 also include the sum with 7th element so we have to change 8 too.

    extraction of LSB:
    - we can represent any positive number with "a1b" where a is any binary number and b contains only 0s.
    - if we taking 2's complement of the number will result into "a'0b' + 1" now b' only contains 1s.
    - now if we add 1 in b' then we get 1b. so at last we get "a'1b"
    - taking bitwise AND of "a'1b" and "a1b" the we get "0...01b".
    - so we get "0...010...0" at last because here b contains only 0s.

    eg. number N =  6  = 110
    now if we take 2's complement then we get = N' + 1
                                              = 001 + 1
                                              = 010
    now taking bitwise AND of 110 and 010 will result into 010.

    # Time compelxity :
    for querying :
    -> In each iteration we are removing a LSB from the number. in the worst case there will be O(logN) opeartions.
    for updating :
    -> In each iteration we are adding a LSB in the number so in the worst case there will be O(logN) opeartions.

*/

/*

    * Range sum with point updates
    Q-1. find the sum for given range :
         sum[l...r] = sum[r] - sum[l-1]
    Q-2. update the element in the tree :
         -> remove current element from the responsible indices's value.
         -> add new value in all the responsible indices's value.

*/

#include <iostream>
#include <vector>

using namespace std;

int find_sum(vector<int> v, vector<int> &binary_index_tree, int index)
{
    int ans = 0;
    while (index > 0)
    {
        ans += binary_index_tree[index];
        index -= (index & (-index));
    }
    return ans;
}

void update_value(vector<int> &binary_index_tree, int total_elements, int idx, int val)
{
    while (idx <= total_elements)
    {
        binary_index_tree[idx] += val;
        idx += (idx & (-idx));
    }
}

int main()
{
    int n;
    cout << "enter total elements in the array : ";
    cin >> n;
    vector<int> binary_index_tree(n + 1, 0);
    vector<int> v(n + 1);

    cout << "enter elements of an array : ";
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        update_value(binary_index_tree, n, i, v[i]);
    }

    /*
        cout << "binary index tree after adding all the elements in that : ";
        for (auto i : binary_index_tree)
        {
            cout << i << " ";
        }
        cout << endl;
     */
    /*
        // here we are taking elements as 1 based indexing
        sample input : 5 1 2 3 4 5 1 5 1 0
    */

    // query for sum
    int query_start, query_end;
    cout << "enter starting and ending index of subarray for it's sum : ";
    cin >> query_start >> query_end;

    cout << "sum of the given subarray is : " << find_sum(v, binary_index_tree, query_end) - find_sum(v, binary_index_tree, query_start - 1) << endl;

    // query for update

    int upd_idx, upd_val;
    cout << "enter update index and updated value : ";
    cin >> upd_idx >> upd_val;

    update_value(binary_index_tree, n, upd_idx, -v[upd_idx]);
    v[upd_idx] = upd_val;
    update_value(binary_index_tree, n, upd_idx, upd_val);

    /*
        cout << "binary index tree after updation of element in that is : ";
        for (auto i : binary_index_tree)
        {
            cout << i << " ";
        }
        cout << endl;
     */

    cout << "sum of the given subarray after updation is : " << find_sum(v, binary_index_tree, query_end) - find_sum(v, binary_index_tree, query_start - 1) << endl;

    return 0;
}
