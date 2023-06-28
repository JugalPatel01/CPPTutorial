/*
    Reverse a Stack

    -> one possible solution is use a extra stack and reverse the whole stack.
    -> another way that we can use recursion for reverse the stack.so here we will see the recursion method for reversing the stack. here basic idea is using a call stack rather then new stack.

            ___           ___
            |5|           |1|
            |4|           |2|
            |3|    -->    |3|    ->  o/p after reverse the stack
            |2|           |4|
            |1|           |5|
 */

#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int top_val = s.top();
    s.pop();
    insert_at_bottom(s, val);
    s.push(top_val);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top_ele = s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s, top_ele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // 1 -> 2 -> 3 -> 4 -> 5
    reverse(st);
    // 5 -> 4 -> 3 -> 2 -> 1
    // so top function will return 1
    cout << st.top() << endl;

    return 0;
}