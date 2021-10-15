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
        cout << "Hello" << endl;

        break;
    case 'b':
        cout << "Hello1" << endl;

        break;
    case 'c':
        cout << "Hello2" << endl;

        break;
    case 'd':
        cout << "Hello3" << endl;

        break;

    default:
        cout << "go back";
        goto Here;
        break;
    }
    return 0;
}