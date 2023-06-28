/*
    List
    -> it is based on a doubly linkedlist.
 */
#include <iostream>
#include <list>
using namespace std;
int main()
{

    list<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(34);
    l.push_back(15);
    l.push_back(13);
    l.push_back(12);
    l.push_front(0);

    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "front " << l.front() << endl;
    cout << "back " << l.back() << endl;
    cout << "empty or not " << l.empty() << endl;

    l.erase(l.begin());

    cout << "after erase" << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "size of list " << l.size() << endl;

    cout << "copy of list" << endl;

    list<int> n(5, 100);
    list<int> m(l);

    for (int i : n)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    m.reverse();
    cout << "after use of reverse function " << endl;

    for (int i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}