/*
    Queue :
    -> it stores an item in FIFO (first in first out )method.

    -> enqueue() / push()
    -> dequeue() / pop()
    -> peek() / front()
    -> empty()
    -> size()
 */

#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "queue is full(overflow)" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || back < front)
        {
            cout << "queue is empty(queue underflow)" << endl;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || back < front)
        {
            return -1;
        }
        return arr[front];
    }
    int size()
    {
        if (front == -1 || back < front)
        {
            return 0;
        }
        return back - front + 1;
    }
    bool empty()
    {
        if (front == -1 || back < front)
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

    cout << "front of queue is : " << q.peek() << endl;

    q.pop();
    cout << "front of queue is : " << q.peek() << endl;

    q.pop();
    cout << "front of queue is : " << q.peek() << endl;

    q.pop();
    cout << "front of queue is : " << q.peek() << endl;

    cout << "is queue empty? : " << q.empty() << endl;

    return 0;
}