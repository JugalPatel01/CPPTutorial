#include <iostream>
#include <deque>
using namespace std;
int main()
{
    // double ended queue(deque)

    deque<int> d;

    d.push_back(5);
    d.push_back(3);
    d.push_front(1);
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    d.pop_back();
    d.push_front(2);
    d.pop_front();
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "print first element in deque " << d.at(1) << endl;

    cout << "front " << d.front() << endl;

    cout << "back " << d.back() << endl;

    cout << "Empty or not " << d.empty() << endl;

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "size before erase " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "size after erase " << d.size() << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "max size " << d.max_size() << endl;
    return 0;
}