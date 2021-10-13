#include <iostream>
using namespace std;
int main()
{
reenter:
    int n1, m1, n2, m2;
    cout << "Enter the size of first matrix for matrix multiplication ";
    cin >> n1 >> m1;
    cout << "Enter the size of second matrix for matrix multiplication ";
    cin >> n2 >> m2;
    int a1[n1][m1];
    int a2[n2][m2];
    int mul[n1][m2];
    if (m1 == n2)
    {
        goto start;
    }
    else
    {
        cout << "Enter value again" << endl;
        goto reenter;
    }
start:
    cout << "enter first matrix's elements ";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> a1[i][j];
        }
    }
    cout << "enter second matrix's elements ";
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> a2[i][j];
        }
    }

    cout << "your matrix for multiplication are " << endl;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cout << a1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < m1; k++)
            {
                mul[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << mul[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}