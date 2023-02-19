#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // printing vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    } // 1 2 3 4 5
    cout << endl;

    // another method using inerator
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t";
    } // 1 2 3 4 5
    cout << endl;

    // another method
    for (auto i : v)
    {
        cout << i << "\t";
    } // 1 2 3 4 5
    cout << endl;

    v.pop_back(); // 1 2 3 4

    vector<int> v2(3, 50); // 3 times 50 in the vector

    for (auto i : v2)
    {
        cout << i << '\t';
    }
    cout << endl; // 50 50 50

    swap(v, v2);

    for (auto i : v)
    {
        cout << i << "\t";
    }
    cout << endl; // 50 50 50

    for (auto i : v2)
    {
        cout << i << '\t';
    }
    cout << endl;

    cout << "size of vector " << v2.size() << endl;
    cout << "actual size of vector " << v2.capacity() << endl;
    cout << "maximum size of vector " << v2.max_size() << endl;

    v2.push_back(2);
    sort(v2.begin(), v2.end()); // 1 2 2 3 4

    // insert element at anywhere
    std::vector<int>::iterator it2;
    it2 = v2.begin();

    v2.insert(it2 + 2, 10);

    for (auto i : v2)
    {
        cout << i << '\t';
    }
    cout << endl; // 1 2 10 2 3 4

    return 0;
}