/*
    implementing queue using stack

    method :
    using recursion

    it is more costlier in terms of time then using 2 stacks;
    becuase in this for pop() and peek() both operation takes O(n) time while in 2 stack method only pop() takes O(n) time.
 */
#include <iostream>
#include <stack>
using namespace std;

void remove_last(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    if (s.empty())
    {
        return;
    }
    else
    {
        remove_last(s);
        s.push(x);
    }
}

int get_last(stack<int> s)
{
    int x = s.top();
    s.pop();
    if (s.empty())
    {
        s.push(x);
        return x;
    }

    int ans = get_last(s);
    s.push(x);
    return ans;
}

class queue
{
    stack<int> s;

public:
    void push(int val)
    {
        s.push(val); // O(1)
    }

    void pop()
    {
        // O(n)
        if (s.empty())
        {
            cout << "queue underflow/ queue is empty unable to pop " << endl;
            return;
        }
        remove_last(s);
    }

    int peek()
    {
        // O(n)
        if (s.empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = get_last(s);
        return ans;
    }

    bool empty()
    {
        if (s.empty())
        {
            return 1;
        }
        else
            return 0;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "front of the queue is " << q.peek() << endl;
    q.pop();

    cout << "front of the queue is " << q.peek() << endl;
    q.pop();

    cout << "front of the queue is " << q.peek() << endl;
    q.pop();

    q.push(5);

    cout << "front of the queue is " << q.peek() << endl;
    q.pop();

    cout << "front of the queue is " << q.peek() << endl;
    q.pop();

    cout << "is queue empty ? : " << q.empty() << endl;

    return 0;
}