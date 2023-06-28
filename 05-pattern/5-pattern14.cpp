/*

        * Print zig-zag pattern

        for value 9

        1     *       *
        2   *   *   *   *
        3 *       *       *
          1 2 3 4 5 6 7 8 9

    -> here similarity is 1+3 ,1+7,2+2,2+6,3+1,3+5,3+9  sum of row and column is divided by 4.
    -> In 2nd row, column which are divide by 2 like(2,4),(2,6),(2,8),...
*/
#include <iostream>
#include <windows.h> // for windows only
using namespace std;
int main()
{
    int n;
    cout << "enter the number of stars : ";
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 2 == 0))
            {
                cout << "* ";
                Sleep(400); // for reviewing how patterns are printed
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}