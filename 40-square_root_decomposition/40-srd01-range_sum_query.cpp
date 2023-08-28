/*

    * Square root decomposition
    -> we use this technique to reduce amortize time complexity of the program.
    -> amortize time compleixty : It will give the average time taken per operation, which will be better than worst-case time
                                  complexity.

    -> here in this technique we divide our array into √n parts. and calculate given query for each part and store it in an array.
    -> and for next all queries we can use that result so it takes less time then the first time.

    Q : given an array v and k queries for sum find the sum for all queries.
    e.g.
        i/p : n = 9    elements are : [2 6 -1 5 7 -6 1 0 10]   k = 2    1) 0 5  2) 4 8
        o/p :   13 12

        here we divide above array in √n parts.
            2 6 -1  |  5 7 -6  | 1 0 10
              7           6         11

 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter total no. of elements in an array : ";
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    /*

        sample input : 9 2 6 -1 5 7 -6 1 0 10
                       2
                       0 5
                       4 8
    */

    int len = sqrtl(n);
    vector<int> pre_cal(len + 1, 0);

    for (int i = 0; i < n; i++)
    {
        pre_cal[i / len] += v[i];
    }

    cout << "enter total number of queries : ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int q_start, q_end, sum = 0;
        cout << "enter starting and ending point of the query : ";
        cin >> q_start >> q_end;

        for (int j = q_start; j <= q_end;)
        {
            if (j % len == 0 && j + len - 1 <= q_end)
            {
                sum += pre_cal[j / len];
                j += len;
            }
            else
            {
                sum += v[j];
                j++;
            }
        }
        cout << endl;

        cout << "sum for given range : " << q_start << " to " << q_end << " is : " << sum << endl;
    }

    return 0;
}