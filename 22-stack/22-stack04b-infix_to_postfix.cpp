/*
    infix to postfix

    i/p : (((8*2)+2)-(7-5))
    o/p : 82*2+75--

    steps:
    1) if it's operand then store it or print it
    2) if it's ( then push to stack
    3) if it's ) then pop from stack and print or store until ( is found
    4) if it's an opeartor then pop from stack and print or store until an opeartor with less precedence is found

*/
#include <iostream>
#include <stack>
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
    if (precedence(op1) == precedence(op2))
    {
        // because pow operator is right to left associative left one has lower precedence so we return false for that.
        if (op1 == '^')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (precedence(op1) > precedence(op2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infix_to_postfix(string s)
{
    string ans = "";
    stack<char> st;

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

    return ans;
}
int main()
{
    string str;
    cout << "enter infix string to convert it into postfix : ";
    cin >> str;

    string ans = infix_to_postfix(str);
    cout << "postfix string is : " << ans << endl;

    return 0;
}