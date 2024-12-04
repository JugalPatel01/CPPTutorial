/*
    # vector
    -> It is representing arrays that can change in size(dynamic array).
    -> It overcomes the fixed size of array problem.
    -> while old array became full it double it's size and copy all the elements from old array and dump old array.
    -> And on deletion of element from the array it will shrink if it's needed. 
    -> These expantion and shrinking should only happen at logarithmaically growing interval of size.

    -> time complexity for insertion O(n). {because we have to copy all the elements in new array if it's needed.}
       time complexity for accessing element O(1).
       time complexity for deletion O(n). {if array shrinks then it copy all the element in another array.}

       To learn more about vectors visit : https://cplusplus.com/reference/vector/vector/

*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{

    vector<int> v;

    // finding capacity of vector (capacity means how many elements it can store in it at that particular time)
    cout << "Capacity when no element in the vector : " << v.capacity() << endl;


    // pushing or adding element at end of the vector using push_back() function.
    v.push_back(1);     
    // NOTE : There is no concept of push_front we can only push element at the back size using push_back;
    v.push_back(2);
    v.push_back(3);

    cout << "Capacity of vector v after adding elements : " << v.capacity() << endl;
    cout << "Actual size of vector v : " << v.size() << endl; // it has O(1) time complexity

    // Accessing element at particular index using at function
    cout << "Element at 2nd Index in vector v : " << v.at(2) << endl;

    // getting first element of vector using front function
    cout << "Front of vector v : " << v.front() << endl;
    
    // getting last element of vector using back function
    cout << "Back of vector v : " << v.back() << endl;

    // print all the elements vector using range based for loop.
    cout << "All elements of vector  v : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // NOTE : from C++20 we can also initialize variable at the begining of the ranged based loop
    //          -> eg.  for(int x = 0; auto  i : v)

    // removing last element from the vector using pop_back() function
    v.pop_back();

    cout << "After pop back from vector v will be : ";

    // The auto keyword figured out variable's type from it's initial value.
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Size of vector v is : " << v.size() << " and capacity is : " << v.capacity() << endl;

    // removing all the elements of the vector using clear() function.
    v.clear();

    cout << "After clearing vector v ";
    cout << "Size is : " << v.size() << "and capacity is : " << v.capacity() << endl;

    // Assigning initial value to all vector indices.

    // vector of size 5 with all 1 element prefilled in it.
    vector<int> a(5, 1);

    // it doesn't make any copy. it is just reference for same vector a.
    // vector<int> &last = a; 
    
    // it make copy of vector and takes O(n) time complexity to create a new vector.
    vector<int> last(a); 
    // vector<int> last = a;

    // iterating vector using inbuilt iterators.
    cout << "Default initialization and copying elements of vector a in vector last : ";
    for (auto i = last.begin(); i != last.end(); i++)
    {
        // last.erase(i);   // for erasing specific element from the vector
        // cout<<*(i++)<<" ";
        cout << *i << " ";
    }
    cout << endl;

    /* Multi dimensional vector */ 

    // assinging initial value to the 2d vector
    int row = 3, col = 4;

    vector<vector<int>> two_d_matrix(row, vector<int>(col, -1));
    
    // print two dimentional vector using range loop.
    cout << "2d Vector of 3 x 4 size : "<<endl;
    for (auto i : two_d_matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}