/*

    * Types of containers:
     sequential  : array , vector, stack , queue
     ordered : maps, multimap, set, multiset
     unordered : unordered map, unordered set
     nested containers : vector<vector<int>>, map<int,vector<int>>, set<pair<int,string>>, vector<map<int,set<int>>>

     * Types of Iterators(pointers for traversing): 
     - point to memory address of containers
     - begin(), end(), rbegin(), rend(), etc...
     - vector<int>::iterator it; 

 */

#include <iostream>
#include <array>
using namespace std;
int main()
{
    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    cout << "Element at 2nd Index " << a.at(2) << endl;

    cout << "empty or not " << a.empty() << endl;

    cout << "first element " << a.front() << endl;
    cout << "last Element " << a.back() << endl;

    return 0;
}