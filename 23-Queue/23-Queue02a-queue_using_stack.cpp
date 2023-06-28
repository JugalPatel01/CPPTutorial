/*
    implement queue using stack
    -> there are so many ways to implement it
    1) using 2 stacks
    2) using recursion or function call stack (just like a reversing a stack by recursion )


    here we use 2 stacks method:
    -> in this method pop operation required O(n) time complexity (if we peek first then it's O(1) other wise O(n))
    -> and it takes more space complexity too.

 */
#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x); // cost is O(1)
    }

    void pop()
    {
        // cost is O(n)
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            cout << "queue underflow / queue is empty unable to pop" << endl;
            return;
        }
        s2.pop();
    }

    int peek()
    {
        // cost is O(n)
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            return -1;
        }
        else
        {
            return s2.top();
        }
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
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
    q.push(5);
    cout << "front of the queue is " << q.peek() << endl;
    q.pop();
    cout << "front of the queue is " << q.peek() << endl;
    q.pop();
    cout << "front of the queue is " << q.peek() << endl;
    q.pop();
    cout << "is queue empty ? : " << q.empty() << endl;
    return 0;
}