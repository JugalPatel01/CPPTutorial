/*

    * Surrounded regions
    Q : Given a 2D board containing 'X' and 'O'(letter O), capture all regions surrounded by 'X'.
    -> A region is captured by flipping all 'O's into 'X's in that surrounded region.

    i/p :
            [X X X X]
            [X O O X]
            [X X O X]
            [X O X X]

    o/p :
            [X X X X]
            [X X X X]
            [X X X X]
            [X O X X]

*/
#include <iostream>
#include <vector>
using namespace std;

void captured_by_O(vector<vector<char>> &grid, int x, int y)
{
    grid[x][y] = '*';
    vector<int> dir_x = {0, 0, 1, -1};
    vector<int> dir_y = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int dx = x + dir_x[i];
        int dy = y + dir_y[i];
        if (dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] == 'O')
        {
            captured_by_O(grid, dx, dy);
        }
    }
}

int main()
{
    int x_grid, y_grid;
    cout << "enter size of rows : ";
    cin >> x_grid;
    cout << "enter size of cols : ";
    cin >> y_grid;

    vector<vector<char>> grid(x_grid, vector<char>(y_grid));
    cout << "fill grid : " << endl;
    for (int i = 0; i < x_grid; i++)
    {
        for (int j = 0; j < y_grid; j++)
        {
            cin >> grid[i][j];
        }
    }

    /* 
    
        template input : 4 4 X X X X X X O X X O O X O X X O
     */

    for (int i = 0; i < x_grid; i++)
    {
        for (int j = 0; j < y_grid; j++)
        {
            if (i == 0 || i == x_grid - 1 || j == 0 || j == y_grid - 1)
            {
                if (grid[i][j] == 'O')
                {
                    captured_by_O(grid, i, j);
                }
            }
        }
    }

    for (int i = 0; i < x_grid; i++)
    {
        for (int j = 0; j < y_grid; j++)
        {
            if (grid[i][j] == 'O')
            {
                grid[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < x_grid; i++)
    {
        for (int j = 0; j < y_grid; j++)
        {
            if (grid[i][j] == '*')
            {
                grid[i][j] = 'O';
            }
        }
    }

    for (auto i : grid)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}