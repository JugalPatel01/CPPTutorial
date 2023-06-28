/*
     passing 2d array as an argument to the function
*/
#include <iostream>
using namespace std;
void func(int **arr, int row, int cols)
{

    for (int i = 0; i < row; i++)
    {
        cout << "[ ";
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << " ]" << endl;
    }
}

int main()
{

    int row, cols;
    cout << "enter rows and columns respectivly : ";
    cin >> row >> cols;
    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[cols];
    }

    cout << "enter elements of an array (first inner array then second inner array and so on... ): ";
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