/*
    print Hollow square / rectangle pattern

            * * * * *
            *       *
            *       *
            *       *
            * * * * *
*/

#include <iostream>
using namespace std;
int main()
{

    // hollow square pattern
    int rows, cols;
    cout << "enter size of rows and columns : ";
    cin >> rows >> cols;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (i == 1 || i == rows)
            {
                cout << "* ";
            }
            else if (j == 1 || j == cols)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}