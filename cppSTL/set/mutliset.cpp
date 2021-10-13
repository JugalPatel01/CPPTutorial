#include <iostream>
#include <set>
using namespace std;
int main()
{

    multiset<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // s.erase(5);      // it removes all the elements whose value is 5

    s.erase(s.find(5));       // it removes first occurance of 5
    
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}