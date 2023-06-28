/*
    # implementation of stack's basic operation using array

    STACK
    -> It is container with LIFO (last in first out) property
    -> so last added memeber will be pop out first.
            ___                      ___
  TOP  ---> |5|                      | |
            |4|                      |4|
            |3|      on pop ->       |3|    ->  o/p after poping 5 elements out : 5 4 3 2 1
            |2|                      |2|
            |1|                      |1|

    so there are basically 4 opeartions in stack
    - push(k)       // pushing element at the top of the stack
    - pop()         // removing element from the top of the stack
    - top()         // it returns the top of the head
    - empty()       // it tells weather stack is empty of not

    all above operations are done in O(1) time.


 */

#include <iostream>
using namespace std;
#define n 100
// int n = 100;
/*
    there is difference between globally declared and define
    -> define is not getting memory allocation
    -> define can't be modify
    -> define will pre-process and doesn't get memory allocation whlie compile time so it's faster than global declaration
 */

class stack
{

    int top;
    int *arr;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            // overflow condition
            cout << "stack is full. unable to push any value" << endl;
            return;
        }
        top = top + 1;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            // stack underflow condition
            cout << "stack is empty, No element to pop" << endl;
            return;
        }
        top = top - 1;
    }

    int top_of_stack()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    stack *st = new stack();
    st->push(2);
    st->push(1);
    st->push(3);
    st->empty();
    cout << "top of stack is : ";
    cout << st->top_of_stack() << endl;
    st->pop();
    st->pop();
    st->pop();

    cout << "is stack is empty ? : " << st->empty() << endl;

    st->pop();

    delete st;
    return 0;
}