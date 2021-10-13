#include <iostream>
#include <vector>

// vector is a dynamic array which double the size of the array and copy all the elements from old array and dump old array while needed and shrink to half on deletion of elements
using namespace std;
int main()
{

    vector<int> v;
    vector<int> a(5,1);
    cout << "size " << v.capacity() << endl;
    v.push_back(1);             // there is no concept of push_front we can only push element at the back size using push_back;
    v.push_back(2);
    v.push_back(3);
    cout << "size " << v.capacity() << endl;
    cout << "actual size " << v.size() << endl;
    cout << "element at 2nd Index" << v.at(2) << endl;
    cout << "front " << v.front() << endl;
    cout << "back " << v.back() << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    
    cout<<"after pop"<<endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"size "<<v.size()<<" capacity " <<v.capacity()<<endl;
    v.clear();
    cout<<"size "<<v.size()<<" capacity " <<v.capacity()<<endl;

    vector<int> last(a);
    for(int i:last){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}