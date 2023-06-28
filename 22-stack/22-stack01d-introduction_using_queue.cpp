/*
    implement stack using queue
 */

#include <iostream>
#include <queue>
using namespace std;

class stack
{
    queue<int> q1, q2;
    int n;

public:
    stack()
    {
        n = 0;
    }
    void push(int val)
    {
        q2.push(val);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q2.swap(q1);
        while (!q2.empty())
        {
            q2.pop();
        }
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "stack is empty unable to pop / stack underflow" << endl;
            return;
        }
        q1.pop();
        n--;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        if (q1.empty())
        {
            return 1;
        }
        else
            return 0;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "top of the stack is : " << s.top() << endl;
    cout << "size of the stack is : " << s.size() << endl;

    s.pop();
    cout << "top of the stack is : " << s.top() << endl;
    s.pop();
    cout << "top of the stack is : " << s.top() << endl;
    s.pop();
    cout << "top of the stack is : " << s.top() << endl;
    s.pop();

    cout << "is stack empty? : " << s.empty() << endl;

    return 0;
}
