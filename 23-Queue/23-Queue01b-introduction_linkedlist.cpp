/*
    implement basic operation of the queue using linked list

    -> In array we are not using all the blocks of memory as we move forward in the queue so to to overcome of the issue which cause because of the array we use linked list.

 */

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = back = NULL;
    }
    void push(int val)
    {
        node *x = new node(val);
        if (front == NULL)
        {
            front = back = x;
            return;
        }
        back->next = x;
        back = back->next;
        return;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "queue underflow / queue is empty unable to pop" << endl;
            return;
        }
        node *to_delete = front;
        front = front->next;
        delete to_delete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "no element in queue :<<";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
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

    cout << "front of the queue is : " << q.peek() << endl;
    q.pop();
    cout << "front of the queue is : " << q.peek() << endl;
    q.pop();
    cout << "front of the queue is : " << q.peek() << endl;
    q.pop();
    cout << "front of the queue is : " << q.peek() << endl;
    q.pop();
    cout << "is queue empty ? : " << q.empty() << endl;
    return 0;
}