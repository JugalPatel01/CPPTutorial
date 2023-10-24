/*
    # Queue
    -> It follows FIFO(first in first out) property.
    -> It can be implemented using deque or linked list but generally it uses deque for implementation.
    -> operations on queue :
        enqueue()
        dequeue()
        front()
        size()
        empty()

    -> To learn more about queue visit : https://cplusplus.com/reference/queue/queue/

 */

#include <iostream>
#include <queue>
using namespace std;
int main()
{

    queue<string> q;

    q.push("1");
    q.push("12");
    q.push("123");
    q.push("1234");
    q.push("1235");

    cout << "Size of queue : " << q.size() << endl;
    cout << "First element of queue is : " << q.front() << endl;
    q.pop();
    cout << "First element of queue after dequeue opeartion : " << q.front() << endl;

    cout << "Size of queue : " << q.size() << endl;

    cout << "whether queue is empty or not ? " << q.empty() << endl;
    return 0;
}