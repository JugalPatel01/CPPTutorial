/*

    * matrix chain multiplication

    problem : We are given 'N' matrices, we have to multiply them in such a way that total no. of operations are minimum.
    i/p : 4 matrices with indices [10 20 30 20 30]
    o/p : 18000 multiplying operations


    for more about this topic refer https://www.youtube.com/watch?v=_WncuhSJZyA&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=52

*/

/*  # what is array [10 20 30 20 30] represented above ?
   -> as shown above 4 matrices are there suppose there are matrix A,B,C,D
   -> now dimention of that matrices are given in array [10 20 30 20 30]
   so ,
   A(10x20), B(20x30), C(30x20), D(20x30)
   so dimention of matrices are :
            A = Arr[0] X Arr[1]
            B = Arr[1] X Arr[2]
            C = Arr[2] X Arr[3]
            D = Arr[3] X Arr[4]

   and resultant matrix will become of size A*B*C*D = ABCD(10x30)
*/

/*  # What is matrix multiplication and Why we need to calculate chain multiplicaiton?

    -> for multiplying of two matrices, the number of columns in the 1st matrix must be equal to the rows in the 2nd matrix.
    -> so, the resulting matrix product will have a number of rows of the 1st matrix and a number of columns of the 2nd matrix.
    -> Time complexity for calculating matrix multiplication is O(N³).
    -> matrix multiplication is following associativity property. so,
          (A * B) * C = A * (B * C)

    -> eg.
         suppose we have given 3 matrices : A(1x2), B(2x3), C(3,4) and we have to find minimum multiplications.

    -> so here,  A(1x2) * B(2x3) gives us AB(1x3) and
    -> AB(1x3) * C(3x4) gives us ABC(1x4)

    -> but, here multiplication cost are different.

          for,(A * B) * C cost is :
          = (A*B) * (C*C)
            (1*2*3) + 0
          = (AB) * (C)
             6 + AB * C
          =  6 + (1 * 3 * 4) = 6 + 12 = 18
            (A*B) + (AB*C)     (ABC)

          for,A * (B * C) cost is :
          = (A*A) * (B*C)
             0 + (2*3*4)
          = (A) * (BC)
            24 + A *BCD
          =  24 + (1 * 2 * 4) = 24 + 8 = 32
            (B*C) + (A*BC)     (ABC)

    so we can see that there are difference in multiplication cost. so we have to find minimum multiplication cost.

    so, multiplication (A B C) = min{ multiplication(A*(B*C)), multiplication((A*B)*C) }
*/

/*  # recurrence relation for matrix multiplication.

    -> multiplication(A₁A₂A₃A₄....Aₙ) = min( multiplication(A₁...Aₖ) + multiplication(Aₖ+₁... Aₙ) + arr[0]*arr[k]*arr[N])
                                            where 1 <= K < N-1
*/

/*  # Observation :

    # different way to multiply A₁* A₂* A₃
    1) (A₁* A₂)* A₃
    2) A₁* (A₂* A₃)
    -> total 2 ways for 3 matricies

    # different way to multiply A₁* A₂* A₃ * A₄
    1) A₁* ((A₂* A₃) * A₄)
    2) A₁* (A₂* (A₃ * A₄))
    3) (A₁* A₂)* (A₃ * A₄)
    4) ((A₁* A₂)* A₃) * A₄
    5) (A₁* (A₂* A₃)) * A₄
    -> total 5 ways for 4 matricies

    # from above examples we can see a pattern of catalan numbers
    catalan Numbers are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786
*/

/*  # approches to solve matrix chain multiplication problem

    1) using recursion :
    ->
                                          mul(ABCD)
                                       /      |      \
                                      /       |       \
                        mul((A)(BCD))    mul((AB)(CD))  mul((ABC)(D))
                        /           \                    /           \
                       /             \                  /             \
             mul((A)((B)(CD)))   mul((A)((BC)(D)))  mul(((A)(BC))(D))  mul(((AB)(C))(D))

    -> so here, in above diagram we can can see that there are some repetation for (AB), (BC), (CD) , etc...
    so, we can use dynamic programming.

    2) using memorization technique (TOP DOWN approach):
    -> make working recursive solution for above problem.
    -> take one container data-structure and store return values.
    -> now, use that container and reduce redundant function calls.

    3) using tabulation method (BoTTOM UP approach):
    ->




*/

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

int mcm_recursion(vector<int> dim, int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = start; k < end; k++)
    {
        ans = min(ans, mcm_recursion(dim, start, k) + mcm_recursion(dim, k + 1, end) + (dim[start - 1] * dim[k] * dim[end]));
    }
    return ans;
}

int mcm_memorization(vector<int> dim, int start, int end, vector<vector<int>> &memo_table)
{
    if (start == end)
    {
        return 0;
    }
    if (memo_table[start][end])
    {
        return memo_table[start][end];
    }
    int ans = INT_MAX;
    for (int k = start; k < end; k++)
    {
        ans = min(ans, mcm_memorization(dim, start, k, memo_table) + mcm_memorization(dim, k + 1, end, memo_table) + (dim[start - 1] * dim[k] * dim[end]));
    }
    memo_table[start][end] = ans;
    return ans;
}

int mcm_tabulation(vector<int> dim)
{
    int matrices = dim.size() - 1;
    vector<vector<int>> cost_table(matrices + 1, vector<int>(matrices + 1, INT_MAX));
    vector<vector<int>> k_table(matrices + 1, vector<int>(matrices + 1, 0));

    /*

        for 4 matrices :

           0   1   2   3   4
       0 | - | - | - | - | - |
       1 | - | 0 |   |   |   |
       2 | - | - | 0 |   |   |
       3 | - | - | - | 0 |   |
       4 | - | - | - | - | 0 |

        -> now we have to find first table[1][1], table[2][2], table[3][3], table[4][4] which are 0.
        -> now we have to find  table[1][2], table[2][3], table[3][4]
        because
                    if we find table[1][3] after table[1][2] then :
                    table[1][3] = min (table[1][1] + table[2][3] + dim[0]*dim[1]*dim[3])
                    but now we don't have table[2][3] so we have to iterate in diagonal order .
        -> now we have to find table[1][3],table[2][4].
        -> and at last we have to find table[1][4].

     */

    for (int i = 1; i < matrices + 1; i++)
    {
        cost_table[i][i] = 0;
    }

    // x is storing starting column index for traversing 2D table in diagonal manner.
    for (int x = 2; x <= matrices; x++)
    {
        // i is the row value for traversing
        for (int i = 1; i <= matrices - x + 1; i++)
        {
            // j is the column value for traversing
            int j = i + x - 1;
            for (int k = i; k < j; k++)
            {
                if (cost_table[i][j] > cost_table[i][k] + cost_table[k + 1][j] + (dim[i - 1] * dim[k] * dim[j]))
                {
                    k_table[i][j] = k;
                }
                cost_table[i][j] = min(cost_table[i][j], cost_table[i][k] + cost_table[k + 1][j] + (dim[i - 1] * dim[k] * dim[j]));
            }
        }
    }

    return cost_table[1][matrices];
}

int main()
{
    int n;
    cout << "Enter total no. of matrices for multiplication : ";
    cin >> n;
    vector<int> dimensions(n + 1);
    cout << "Enter dimensions of matrices : ";
    for (auto &i : dimensions)
    {
        cin >> i;
    }

    /*
        sample input : 4 10 20 30 20 30
    */
    vector<vector<int>> memo_table(n + 1, vector<int>(n + 1, 0));
    cout << "minimum ways to multiply above matricies using memorization are : " << mcm_memorization(dimensions, 1, n, memo_table) << endl;

    cout << "minimum ways to multiply above matricies using tabulation are : " << mcm_tabulation(dimensions) << endl;

    cout << "minimum ways to multiply above matricies using recursion are : " << mcm_recursion(dimensions, 1, n) << endl;

    return 0;
}