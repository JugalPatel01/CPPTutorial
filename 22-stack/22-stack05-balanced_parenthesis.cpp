/*
    balanced parenthesis
     input : {[()]}
     output : 1

     input : [{()]}
     output : 0
 */

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool balanced_parenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return 0;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return 0;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return 0;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    string input;
    cout << "enter string for checking balanced parenthesis : ";
    cin >> input;
    cout << "is string balanced ? : " << balanced_parenthesis(input) << endl;

    return 0;
}