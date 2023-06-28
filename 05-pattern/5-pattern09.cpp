/*

    * print left pyramid of alternate ones and zeros
    for value 5 :
        1
        0  1
        1  0  1
        0  1  0  1
        1  0  1  0  1

 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of rows : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}