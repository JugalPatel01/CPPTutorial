/*
    * vector
    -> It is a dynamic array
    -> It overcome the fixed array problem
    -> while old array became full it double it's size and copy all the elements from old array and dump old array while needed and shrink to half on deletion of elements

 */
#include <iostream>
#include <vector>

using namespace std;
int main()
{

    vector<int> v;
    vector<int> a(5, 1); // array of size 5 with all 1 element prefilled
    cout << "size " << v.capacity() << endl;
    v.push_back(1); // there is no concept of push_front we can only push element at the back size using push_back;
    v.push_back(2);
    v.push_back(3);
    cout << "size " << v.capacity() << endl;
    cout << "actual size " << v.size() << endl; // it has O(1) time complexity
    cout << "element at 2nd Index " << v.at(2) << endl;
    cout << "front " << v.front() << endl;
    cout << "back " << v.back() << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();

    cout << "after pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "size " << v.size() << " capacity " << v.capacity() << endl;
    v.clear();
    cout << "size " << v.size() << " capacity " << v.capacity() << endl;

    // vector<int> &last = a; // it doesn't make any copy. it is just same vector a.
    vector<int> last(a); // we can make copy of vectors in O(n) time complexity
    // vector<int> last = a;
    for (auto i = last.begin(); i != last.end(); i++)
    {
        // last.erase(i);   // for erasing specific element from the vector
        // cout<<*(i++)<<" ";
        cout << *i << " ";
    }
    cout << endl;

    // for(auto i:last){
    //     cout<<i<<" ";
    // }cout<<endl;
    return 0;
}