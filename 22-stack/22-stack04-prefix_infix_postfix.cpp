/*
    Applications of stack :

    coversion of expressions:
    * Infix expression
        -> (Traversal : LEFT ROOT RIGHT)
        -> (<operand> <operator> <operand>)
        ->     8 * 2 + 5
            ~  (8 * 2) + 5
            ~  ((8 * 2) + 5)

    // machine can't understand infix expression so we use prefix or postfix operation to give idea about precedence to machine.

    * Prefix expression (polish notation)
        -> (Traversal : ROOT LEFT RIGHT)
        -> (<operator> <operand> <operand>)
        ->     + * 8 2 5
            ~  + (8 * 2) 5
            ~  ((8 * 2) + 5)

    * Postfix expression (reverse polish notation)
        -> (Traversal : LEFT RIGHT ROOT)
        -> (<operand> <operand> <operator>)
        ->     8 2 * 5 +
            ~  (8 * 2) 5 +
            ~  ((8 * 2) + 5)

    Normal Operator Precedence :
    1. () , {} , []          Associativity : Left to right
    2. ^/pow()               Associativity : right to left  (2^3^2) -> (2^(3^2))
    3. *,/,%                 Associativity : Left to right  (2*3*2) -> ((2*3)*4)
    4. +,-                   Associativity : Left to right  (2+3+2) -> ((2+3)+2)

    for more about operator precedence check out 4-operators.cpp in 04-operators folder.

    # so our task is to convert these expression in to other
    -> infix to prefix
    -> infix to postfix

    # here we calculate prefix and postfix expressions
    -> time complexity is O(l) where l is length of string
 */

#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

int eval_prefix(string s)
{
    /*
            -+2*82-75
       ->   -+2*82(7-5) = -+2*822
       ->   -+2(8*2)2 = -+2162
       ->   -(2+16)2 = -182
       ->   (18-2) = 16
     */
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            int ans;
            switch (s[i])
            {
            case '*':
                ans = operand1 * operand2;
                break;
            case '+':
                ans = operand1 + operand2;
                break;
            case '-':
                ans = operand1 - operand2;
                break;
            case '/':
                ans = operand1 / operand2;
                break;
            case '^':
                ans = pow(operand1, operand2);
                break;
            default:
                break;
            }
            st.push(ans);
        }
    }
    return st.top();
}

int eval_postfix(string s)
{
    /*
            282*+75--
       ->   282*+(7-5)- = -+2*822
       ->   2(8*2)+2- = -+2162
       ->   (2+16)2- = -182
       ->   (18-2) = 16

    */
    stack<int> st;
    int ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int ans;
            switch (s[i])
            {
            case '*':
                ans = operand1 * operand2;
                break;
            case '+':
                ans = operand1 + operand2;
                break;
            case '-':
                ans = operand1 - operand2;
                break;
            case '/':
                ans = operand1 / operand2;
                break;
            case '^':
                ans = pow(operand1, operand2);
                break;
            default:
                break;
            }
            st.push(ans);
        }
    }
    return st.top();
}

int main()
{
    int check;
    int ans;
    string input = "";
enteragain:
    cout << " press 1 for prefix evaluation \n press 2 for postfix evaluation :  " << endl;
    cin >> check;
    switch (check)
    {
    case 1:
        // prefix
        cout << "enter prefix string " << endl;
        cin >> input;
        cout << "ans is : " << eval_prefix(input) << endl;
        break;

    case 2:
        // postfix
        cout << "enter postfix string " << endl;
        cin >> input;
        cout << "ans is : " << eval_postfix(input) << endl;
        break;

    default:
        cout << "enter again" << endl;
        goto enteragain;
        break;
    }
    return 0;
}