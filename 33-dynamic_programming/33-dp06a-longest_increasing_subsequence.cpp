/*

    * Longest increasing subsequence
    Q: Given an array. Find the length of longest increasing subsequence.
    sub_array : continuous block of elements
    sub_sequence : part of array in order.
    NOTE : every subarray is subsequence but every subsequene is not subarray.
    i/p: [1 4 2 5 3]
    o/p : 3
        { 1,4,5 }
        { 1,2,3 }

    1) bruteforce-appraoch :
    -> find all the sub-sequences and check whether it's increasing.
    -> and if it is increasing then store it's size
    -> and iterate through all the sub-sequences and find the maximum size.

    2) recursive approach :
    recurrance relation for above problem :
    suppose f(i) = length of longest increasing subsequence ending at iᵗʰ element.
    so f(i) is dependent on f(0),f(1),....,f(i-1).
    now, if array[i] > array[k]
    then f(i) = max(f(i),1+f(k))    where 0 <= k <= i-1

                        f(x)
                      /  |...\
                  f(0)  f(1)  f(x-1)
                             /  |...\
                        f(0)  f(1)  f(x-2)

    so, from above recursion tree we can conclude that we can use dynamic programming to reduce recursive calls.

    2) memorization technique
    -> first of all we make a working recursive program.
    -> now we take one container-data_structure and store returned value in that.
    -> we have to use that stored data to reduce unnecessary repeated calls.

    3) tabulation technique
    -> make table of size more than array with initial value 1.
    -> enter the base case in that table.
    -> iterate through every i of the table and make another iteration from 0 to i-1 and check condition :
            if(array[i] > array[j]){
                table[i] = max(table[i], 1 + table[j])
            }
    -> after return table[n].


*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int find_length_recursion(vector<int> v, int ele)
{
    if (ele < 0)
    {
        // this base condition is already implemented in for loop but because of to follow recursion step it is here.
        return 0;
    }
    int count = 1;
    for (int i = 0; i < ele; i++)
    {
        if (v[i] < v[ele])
        {
            count = max(count, 1 + find_length_recursion(v, i));
        }
    }
    return count;
}

int find_length_memorization(vector<int> v, int ele, unordered_map<int, int> &memo_table)
{

    if (ele < 0)
    {
        return 0;
    }
    if (memo_table[ele])
    {
        return memo_table[ele];
    }
    int count = 1;
    for (int i = 0; i < ele; i++)
    {
        if (v[i] < v[ele])
        {
            count = max(count, 1 + find_length_memorization(v, i, memo_table));
        }
    }
    memo_table[ele] = count;
    return count;
}

int find_length_tabulation(vector<int> v, int ele)
{
    vector<int> table(ele + 1, 1);

    int ans = 0;

    for (int i = 0; i <= ele; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                table[i] = max(table[i], 1 + table[j]);
            }
        }
        ans = max(ans, table[i]);
    }

    return ans;
}

int main()
{

    int n;
    cout << "enter size of an array : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }

    /*

        sample input :  9 7 19 6 30 18 47 49 60 88
    */

    unordered_map<int, int> memo_table;
    cout << "size of longest increasing subsequence using memorization is : " << find_length_memorization(v, n - 1, memo_table) << endl;

    cout << "size of longest increasing subsequence using tabulation is : " << find_length_tabulation(v, n - 1) << endl;

    cout << "size of longest increasing subsequence using recursion is : " << find_length_recursion(v, n - 1) << endl;

    return 0;
}