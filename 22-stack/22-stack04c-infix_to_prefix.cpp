/*
    infix to prefix


    i/p : (((8*2)+2)-(7-5))
    o/p : -+*822-75

 */
#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    
    else
    {
        return -1;
    }
}

bool check_precedence(char op1, char op2)
{
    if (op1 == op2)
    {
        if (op1 == '^')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    else if (op1 > op2)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

string infix_to_prefix(string s)
{
    stack<char> st;
    reverse(s.begin(), s.end());
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && check_precedence(st.top(), s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string input, ans;
    cout << "enter infix string to convert it into prefix : ";
    cin >> input;
    ans = infix_to_prefix(input);
    cout << "prefix is : " << ans << endl;
    return 0;
}