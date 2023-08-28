/*

    * Mo's algorithm
    Q. Given an array and K queries with starting and ending indices.we have to find sum for given queries.

    -> if we take all the queires simultaneously in square root decomposition, and do offline processing on that queries
       (not in a first come first serve manner like online processing ) is called mo's algorithm.


        here we have given below array.
            2 6 -1  |  5 7 -6  | 1 0 10

        and suppose there are total 3 queries and those queries are :
        k = 3,
        7 8
        1 6
        2 7
        now here we arrange above queries using below algorithm :

        int len = √n
        comparision(Q q1, Q q2){
            if(q1.start/len == q2.start/len){
                return q1.end > q2.end;
            }else{
                return q1.start/len < q2.start/len;
            }
        }

    so we get :

        start end                                           start   end
        7       8    change the order of given queries      2       7
        1       6   --------------------------------------> 1       6
        2       7                                           7       8

    now we find answer for our sorted queries so that it will take less time then it takes for individual query.


       time complexity for above sorting all queries is Klog(K).
       time complexity for call for all blocks -> n/√n * n
       time complexity for total time changes the start and end variables is -> √n*K
       Total time complexity is  : O((n+K)√n)

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct Query
{
    int start, end, index;
};
int len;
bool cmp(Query q1, Query q2)
{
    if (q1.start / len == q2.start / len)
    {
        return q1.end > q2.end;
    }
    else
    {
        return q1.start / len < q2.start / len;
    }
}

int main()
{
    int n;
    cout << "enter total number of elements in the array : ";
    cin >> n;

    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    /*

        sample input : 9 2 6 -1 5 7 -6 1 0 10
                       3
                       7 8
                       1 6
                       2 7

    */
    len = sqrtl(n);

    int k;
    cout << "Enter total no. of queries : ";
    cin >> k;
    vector<Query> queries(k);
    vector<int> ans(k);

    cout << "enter all the queries simultaneously : ";
    for (int i = 0; i < k; i++)
    {
        queries[i].index = i;
        cin >> queries[i].start >> queries[i].end;
    }

    // here we sort the queries it will take KlogK time for sorting.
    sort(queries.begin(), queries.end(), cmp);

    // we took 4 variables for traversing and getting the answer for given queries.
    int start, end, curr_start = 0, curr_end = -1, curr_ans = 0;

    for (int i = 0; i < k; i++)
    {
        start = queries[i].start;
        end = queries[i].end;

        while (curr_start < start)
        {
            curr_ans -= v[curr_start];
            curr_start++;
        }
        while (curr_start > start)
        {
            curr_start--;
            curr_ans += v[curr_start];
        }

        while (curr_end < end)
        {
            curr_end++;
            curr_ans += v[curr_end];
        }
        while (curr_end > end)
        {
            curr_ans -= v[curr_end];
            curr_end--;
        }

        ans[queries[i].index] = curr_ans;
    }

    cout << "answer of all the above queries are : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}