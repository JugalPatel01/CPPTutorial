/*
    * deque (doubly ended queue )
    -> stacks follows LIFO structure and queue follows FIFO strcutre
    -> so deque has a functionality of both stack and queue
    -> In deque we can push and pop from start and end.
*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(0);
    dq.push_front(-1);
    dq.push_front(-2);

    cout << "so our deque is : " << endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.pop_back();
    dq.pop_front();
    
    cout << "after pop operation deque is : " << endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "size of the deque is : " << dq.size();
    cout << endl;
    return 0;
}