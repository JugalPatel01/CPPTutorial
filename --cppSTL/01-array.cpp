/*

    * Types of data containers:
     sequential containers : array , vector, stack , queue
     ordered containers : maps, multimap, set, multiset
     unordered container : unordered map, unordered set
     nested containers : vector<vector<int>>, map<int,vector<int>>, set<pair<int,string>>, vector<map<int,set<int>>>

     * Types of Iterators(pointers for traversing):
     - point to memory address of containers
     - begin(), end(), rbegin(), rend(), etc...
     - vector<int>::iterator it;


    To learn more about container classes visit
                                            : https://en.cppreference.com/w/cpp/container
                                            : https://cplusplus.com/reference/stl/

*/

/*
    # array
    -> Arrays are fixed-size continously allocated memory blocks(containers).
    -> size of the array is given in the square brakets ([]). eg. int arr[5]
    -> zero-sized arrays are valid.

    To learn more about arrays visit : https://cplusplus.com/reference/array/array/

*/

#include <iostream>
#include <array>
using namespace std;
int main()
{
    // normal allocation for array
    int basic[3] = {1, 2, 3};

    // array memory allocation using STL array library
    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    cout << "Elements of array a : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Element at 2nd Index in Array a : " << a.at(2) << endl;

    cout << "Array a is empty or not ? " << a.empty() << endl;

    cout << "First element of Array a : " << a.front() << endl;
    cout << "Last element of Array a : " << a.back() << endl;

    return 0;
}