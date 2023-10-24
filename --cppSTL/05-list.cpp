/*
    # List
    -> it is based on a doubly linkedlist.

    To learn more about list visit : https://cplusplus.com/reference/list/list/

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

    cout << "Initially list is : ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Front of list l : " << l.front() << endl;
    cout << "Back of list l : " << l.back() << endl;
    cout << "List l is empty or not ? " << l.empty() << endl;

    l.erase(l.begin());

    cout << "After erase element from begining of the list : ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Size of list l : " << l.size() << endl;

    cout << "By default initialization of list with 5 times 100 value : ";
    list<int> n(5, 100);
    for (int i : n)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Copy of list l in list m : " ;
    list<int> m(l);
    for (int i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "After using reverse function list m will be : ";
    m.reverse();

    for (int i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}