/*  Backtracking is an algorithmic-technique for solving reccursive problems by trying to build every possible solution incrementally and
    removing those solutions that fail to satisfy the constraints of the problem at any point of time.*/

// Rat in a Maze problem

// Rat can move only in right or down direction and we need to reach to ending from starting.

/*
        input :
                1 0 1 0 1
                1 1 1 1 1
                0 1 0 1 0
                1 0 0 1 1
                1 1 1 0 1

        expected output : 1 0 0 0 0
                          1 1 1 1 0
                          0 0 0 1 0
                          0 0 0 1 1
                          0 0 0 0 1

    Here we can move forward at 1 and block position is 0.

 */

#include <iostream>
using namespace std;

bool canItGo(int **arr, int x, int y, int n)
{

    if (x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{

    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }
    if (canItGo(arr, x, y, n))
    {
        solArr[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArr)) // can we go in right direction
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, solArr)) // can we go in down direction
        {
            return true;
        }
        solArr[x][y] = 0; // backtracking
        return false;
    }
    return false;
}
int main()
{
    cout << "Enter size of the maze : " << endl;
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}