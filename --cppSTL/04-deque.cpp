/*
    # Double-ended queue ( Deque )
    -> it is mixture of stack and queue. we can implement stack as well as queue using deque.
    -> deques can be implement in different way, but generally it is implemented using dynamic array.

    To learn more about deque visit : https://cplusplus.com/reference/deque/deque/
 
*/

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d;

    d.push_back(5);
    d.push_back(3);
    d.push_front(1);
    cout << "Element in the deque : ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    // pop_front will act like a queue
    d.pop_front();
    d.push_front(2);

    // pop_back() will act like a stack
    d.pop_back();
    cout << "Element in the deque after poping from front and back : ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Print first element in deque : " << d.at(1) << endl;

    cout << "Element at front : " << d.front() << endl;

    cout << "Element at back : " << d.back() << endl;

    cout << "Is deque Empty or not ? " << d.empty() << endl;

    cout << "Size before erasing first element : " << d.size() << endl;

    d.erase(d.begin(), d.begin() + 1);

    cout << "Size after erasing first element : " << d.size() << endl;

    cout << "elements remaining in the deque : ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "maximum size of deque is : " << d.max_size() << endl;
    return 0;
}