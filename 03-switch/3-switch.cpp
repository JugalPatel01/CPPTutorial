/*

    * switch and goto statement
    -> switch is just like if else condition but faster then if condition because in switch character and it's actions are mapped in back-end.

    * using goto statement we can go back to the lable's position
 */

#include <iostream>
using namespace std;
int main()
{

    char button;
Here:
    cout << "Input a character:  ";
    cin >> button;
    switch (button)
    {
    case 'a':
        cout << "Hello from a" << endl;

        break;
    case 'b':
        cout << "Hello from b" << endl;

        break;
    case 'c':
        cout << "Hello from c" << endl;

        break;
    case 'd':
        cout << "Hello from d" << endl;

        break;

    default:
        cout << "wrong input go back";
        goto Here;
        break;
    }
    return 0;
}