/*

    Q : we have a matrix of size NxM.we have to find out the hightest sum of the any diagonal from the matrix.
    i/p : 3 3 1 2 3 4 5 6 7 8 9
    o/p : 15
                                      0 1 2           0 1 2
            [[1 2 3]             0  [[/ / /]       0 [[\ \ \]
             [4 5 6]        ->   1   [/ / /]    +  1  [\ \ \]
             [7 8 9]]            2   [/ / /]]      2  [\ \ \]]
        here we have 10 diagonals 1 , 2+4, 7+5+3, 8+6, 9 , 3 , 2+6, 1+5+9, 4+8, 7
        and the highest sum is 15.

*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int row, col;
    cout << "enter the size of the 2D array : ";
    cin >> row >> col;
    int arr[row][col];
    cout << "enter the elements of the array : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "your matrix is : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    /*

        sample input : 3 3 1 2 3 4 5 6 7 8 9
    */

    int max_sum = 0, sum = 0;

    /*
        for below diagonals
                 0 1 2
            0  [[/ / /]
            1   [/ /  ]
            2   [/    ]]
    */
    for (int i = 0; i < row; i++)
    {
        int x = i, y = 0;
        sum = 0;
        while (x >= 0 && y < col)
        {
            sum += arr[x][y];
            x--;
            y++;
        }
        cout << "sum is : " << sum << "\t";
        max_sum = max(sum, max_sum);
    }
    cout << endl;

    /*
        for below diagonals
                 0 1 2
            0  [[\    ]
            1   [\ \  ]
            2   [\ \ \]]
    */
    for (int i = row - 1; i >= 0; i--)
    {
        int x = i, y = 0;
        sum = 0;
        while (x < row && y < col)
        {
            sum += arr[x][y];
            x++;
            y++;
        }
        cout << "sum is : " << sum << "\t";
        max_sum = max(sum, max_sum);
    }
    cout << endl;

    /*
        for below diagonals
                 0 1 2
            0  [[\ \ \]
            1   [  \ \]
            2   [    \]]
    */
    for (int i = 0; i < row; i++)
    {
        int x = i, y = col - 1;
        sum = 0;
        while (x >= 0 && y >= 0)
        {
            sum += arr[x][y];
            x--;
            y--;
        }
        max_sum = max(sum, max_sum);
        cout << "sum is : " << sum << "\t";
    }
    cout << endl;

    /*
        for below diagonals
                 0 1 2
            0  [[    /]
            1   [  / /]
            2   [/ / /]]
    */
    for (int i = row - 1; i >= 0; i--)
    {
        int x = i, y = col - 1;
        sum = 0;
        while (x < row && y >= 0)
        {
            sum += arr[x][y];
            x++;
            y--;
        }
        cout << "sum is : " << sum << "\t";
        max_sum = max(sum, max_sum);
    }
    cout << endl;

    cout << "maximum sum of any diagonal from the matrix is : " << max_sum << endl;
    return 0;
}