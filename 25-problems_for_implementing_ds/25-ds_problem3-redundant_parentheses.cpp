/*
    * Redundant parentheses
    Q. Given a valid mathematical expression, find whether it have redundant parentheses or not. It contains '+','-','*','/'.
    i/p : ((x+y))
    o/p : 1

    i/p : (x+(x-y))
    o/p : 0
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check_redundancy(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                return 1;
            }
            while (st.top() != '(')
            {
                st.pop();
            }
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return 0;
}

int main()
{
    string s;
    cout << "enter string without space : ";
    cin >> s;
    cout << "is/are redundant parentheses present? " << check_redundancy(s) << endl;
    return 0;
}