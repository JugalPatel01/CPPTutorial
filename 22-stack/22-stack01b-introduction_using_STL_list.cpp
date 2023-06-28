/*
    stack using linked list
*/
#include <iostream>
#include <list>
using namespace std;

class stack
{
public:
    list<int> l;
    int top = 0;
    void push(int val)
    {
        l.push_back(val);
        top++;
    }
    void pop()
    {
        // stack underflow condition
        if (top == 0)
        {
            cout << "stack is empty.unable to pop" << endl;
        }
        top--;
        l.pop_back();
    }

    bool empty() { return top == 0; }

    int top_of_stack()
    {
        list<int>::iterator p = l.end();
        return *p;
    }

    int size() { return top; }

    void print()
    {
        for (auto x : l)
        {
            cout << x << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.print();

    cout << "size of stack is : " << st.size() << endl;

    cout << "top element of the stack is : " << st.top_of_stack() << endl;

    st.pop();
    st.pop();
    st.print();
    st.pop();
    st.pop();

    cout << "is stack empty? : " << st.empty() << endl;

    return 0;
}