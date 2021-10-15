#include <iostream>
using namespace std;
int main()
{
    /*
    zig-zag pattern
    for n=9
    
   1     *       *
   2   *   *   *   *
   3 *       *       *
     1 2 3 4 5 6 7 8 9

     here similarity is 1+3 ,1+7,2+2,2+6,3+1,3+5,3+9  sum of row and column is divided by 4. 
     and in row 2  column which are divide by 4  (2,4),(2,8),...
    */
    int n;
    cout << "enter the number of stars ";
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 2 == 0))
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

    return 0;
}