#include <iostream>
using namespace std;
void func(int **arr, int row, int cols)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << endl;
        }
    }
}

int main()
{

    int row, cols;
    cin >> row >> cols;
    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    func(arr, row, cols);

    return 0;
}