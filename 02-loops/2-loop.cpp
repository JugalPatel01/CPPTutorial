/*
    Types of Loops
    1) For Loop
    2) While Loop
    3) do-while loop

    - Nested Loop -> loops inside a loop

    - loop controllers : 1) break; 2) continue;

    To learn more about loops visit : https://cplusplus.com/doc/tutorial/control/

 */

#include <iostream>
using namespace std;
int main()
{
    int a;

    cout << "----This is from for loop---------------\n";
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "from normal for loop : " << i << endl;
    }
    cout << endl;
    for (int i = 0, j = 0; i < 8 && j < 9; i++, j += 3)
    {
        cout << "From hybrid for loop : i = " << i << " & j = " << j << endl;
    }
    cout << endl;

    cout << "------This is from while loop--------------\n";
    cout << endl;
    int i = 0;
    while (i < 4)
    {
        cout << "From while loop " << i << "" << endl;
        i++;
    }
    cout << endl;

    cout << "----This is from do-while loop-----------------\n";
    cout << endl;
    // here in do while loop do part will always runs for the first time
    // here 0 !< 0 then also do will run for first time.
    i = 0;
    do
    {
        cout << "From do-while loop " << i << "" << endl;
        i++;
    } while (i < 0);
    cout << endl;

    cout << "----------loop control-----------(continue)\n";
    cout << endl;
    for (int i = 0; i < 100; i++)
    {
        if (i % 3 == 0)
        {
            continue;
        }
        cout << i << "  ";
    }
    cout << endl;

    cout << "\n----------loop control & nested loops -----------(break)(Is number is prime or not between two numbers)" << endl;
    cout << endl;
    int n, m;
    cout << "Enter the range (starting & ending Number) :  ";
    cin >> n >> m;
    for (int num = n; num <= m; num++)
    {
        for (i = 2; i < num / 2 + 1; i++)
        {
            if (num % i == 0)
            {
                cout << num << "is not prime number" << endl;
                break;
            }
        }
        if (i == num)
            cout << num << "is prime number" << endl;
    }

    return 0;
}