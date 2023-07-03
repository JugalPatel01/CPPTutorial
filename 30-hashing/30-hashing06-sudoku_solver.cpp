/*

    * sudoku solver
    Q : solve a sudoku puzzle by filling the empty cells.
    -> A sudoku solution must satisfy all of the following rules:
        Each of the digit 1-9 must occur exactly once in each row.
        Each of the digit 1-9 must occur exactly once in each column.
        Each of the digit 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
        '*' means empty cell

    approach : we solve it with brute force method with backtracking,and storing elements into map

        _______________________________________
  i/p:  | 5 | 3 |   ||   | 7 |   ||   |   |   |
        | 6 |   |   || 1 | 9 | 5 ||   |   |   |
        |   | 9 | 8 ||   |   |   ||   | 6 |   |
        |------------|------------|-----------|
        | 8 |   |   ||   | 6 |   ||   |   | 3 |
        | 4 |   |   || 8 |   | 3 ||   |   | 1 |
        | 7 |   |   ||   | 2 |   ||   |   | 6 |
        |------------|------------|-----------|
        |   | 6 |   ||   |   |   || 2 | 8 |   |
        |   |   |   || 4 | 1 | 9 ||   |   | 5 |
        |   |   |   ||   | 8 |   ||   | 7 | 9 |
        |___________||___________||___________|


        _______________________________________
  o/p:  | 5 | 3 | 4 || 6 | 7 | 8 || 9 | 1 | 2 |
        | 6 | 7 | 2 || 1 | 9 | 5 || 3 | 4 | 8 |
        | 1 | 9 | 8 || 3 | 4 | 2 || 5 | 6 | 7 |
        |------------|------------|-----------|
        | 8 | 5 | 9 || 7 | 6 | 1 || 4 | 2 | 3 |
        | 4 | 2 | 3 || 8 | 5 | 3 || 7 | 9 | 1 |
        | 7 | 1 | 6 || 9 | 2 | 4 || 8 | 5 | 6 |
        |------------|------------|-----------|
        | 9 | 6 | 1 || 5 | 3 | 7 || 2 | 8 | 4 |
        | 2 | 8 | 7 || 4 | 1 | 9 || 6 | 3 | 5 |
        | 3 | 4 | 5 || 2 | 8 | 6 || 1 | 7 | 9 |
        |___________||___________||___________|

 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print(vector<vector<char>> s)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "|-----------|-----------|-----------|" << endl;
        }
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                cout << "| ";
            }
            cout << s[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "|-----------|-----------|-----------|" << endl;
    cout << endl;
}

void solve(int r, int c, vector<vector<char>> &s, map<pair<int, int>, map<int, int>> &grid, vector<map<int, int>> &row, vector<map<int, int>> &cols)
{
    // if row is greater then size then move on the next column
    if (r == 9)
    {
        solve(0, c + 1, s, grid, row, cols);
        return;
    }
    // if columns are exceeded then our sudoku was solved so just print that sudoku
    if (c == 9)
    {
        print(s);
        return;
    }
    // if there is already a number on that position then move to the next position
    if (s[r][c] != '.')
    {
        solve(r + 1, c, s, grid, row, cols);
        return;
    }
    // otherwise try all the numbers from 1 to 9
    for (int i = 1; i <= 9; i++)
    {
        int rg = r / 3, cg = c / 3;
        // if number is present in the row / column / grid then just change number
        if (row[r][i] == 1 || cols[c][i] == 1 || grid[{rg, cg}][i] == 1)
        {
            continue;
        }
        // otherwise put that number and solve sudoku for next indecies
        else
        {
            s[r][c] = i + '0';
            row[r][i] = 1;
            cols[c][i] = 1;
            grid[{rg, cg}][i] = 1;
            solve(r + 1, c, s, grid, row, cols);
            // if above solve function returned then we have to backtrack because that number is a part of solution
            s[r][c] = '.';
            row[r][i] = 0;
            cols[c][i] = 0;
            grid[{rg, cg}][i] = 0;
        }
    }
}

void solve_sudoku(vector<vector<char>> &s)
{
    map<pair<int, int>, map<int, int>> grid;
    vector<map<int, int>> row(9);
    vector<map<int, int>> cols(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s[i][j] != '.')
            {
                grid[{i / 3, j / 3}][s[i][j] - '0'] = 1;
                row[i][s[i][j] - '0'] = 1;
                cols[j][s[i][j] - '0'] = 1;
            }
        }
    }

    solve(0, 0, s, grid, row, cols);
}

int main()
{
    vector<vector<char>> sudoku;
    // for custom input
    /*
        for(int i = 0;i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cin >> sudoku[i][j];
            }
        }
     */
    sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "-------------------------- unsolved sudoku : ----------------------------------" << endl;
    cout << endl;
    print(sudoku);
    cout << "-------------------------- solved sudoku : ----------------------------------" << endl;
    cout << endl;
    solve_sudoku(sudoku);

    return 0;
}