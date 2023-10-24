/*

    # Algorithm library :

    * binar_search
    -> use binary_search to find element in the sorted data structures.
      ===> lower_bound
        -> if value is present in the data structure then it return that value's pointer and if it's not present then it next
           bigger value's  pointer.
      ===> upper_bound
        -> if bigger value present in that data strcutre then it returns that value's pointer otherwise it returns last pointer
           of the data structure. eg. in set it returns set.end() in case if there is no bigger element in the set.

    # popular functions of algorithm library.
    -> max , min , swap , reverse , rotate , sort , find , count , transform , next_permutation , prev_permutation, all_of,
      any_of, none_of, min_element, max_element

    -> To view all the functions which algorithm library contains visit : https://cplusplus.com/reference/algorithm/

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

bool cmp(int a, int b)
{
    // if this function return false then both elements will swap to each other.
    // for accending order
    return a < b;

    // for decreasing order
    // return a>b;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(51);
    v.push_back(56);

    cout << "Elements in vector v are : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // binary search    { only applied on sorted elements}
    cout << "Is 5 present in vector v ? " << binary_search(v.begin(), v.end(), 5) << endl;
    cout << "Is 15 present in vector v ? " << binary_search(v.begin(), v.end(), 15) << endl;

    cout << "Lower bound of 51 : " << v[lower_bound(v.begin(), v.end(), 51) - v.begin()] << endl; // lower bound
    cout << "Upper bound of 51 : " << v[upper_bound(v.begin(), v.end(), 51) - v.begin()] << endl; // upper bound

    // Min - Max function
    int a = 5;
    int b = 3;
    cout << "Maximum of " << a << " and " << b << " : " << max(a, b) << endl;
    cout << "Minimum of " << a << " and " << b << " : " << min(a, b) << endl;

    // swap function
    cout << "Initially value of a is : " << a << " & value of b is : " << b << endl;
    swap(a, b);
    cout << "After swapping value of a is : " << a << " & value of b is : " << b << endl;

    // reverse function for string,vector, etc... {arguments : (starting pointer, ending pointer), range : [start,end) }
    string ab = "abcd";
    cout << "string is : " << ab << endl;
    reverse(ab.begin(), ab.end()); // reverse
    cout << "After use of the reverse function string is : " << ab << endl;

    // rotate function {arguments : (starting pointer, middle pointer ,ending pointer), range : [start,end) }
    // after using rotate function middle pointer will become a first pointer in range.
    rotate(ab.begin(), ab.begin() + 2, ab.end()); // rotate
    cout << "After rotate by 2 position : " << ab << endl;

    // sort function
    /*
    // if we wan't vector sorted in accending order then return a<b; (means a always have to less);
        bool cmp(int a, int b){
            if(a<b){
                return true;
            }else{
                return false;
            }
        }

        // abvoe function is for sorting in accending order.

     */
    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "Before sorting elements of vector v are : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(v.begin(), v.end()); // sort  --> based on intro sort (mixture of)( quick sort, heap sort, insertion sort)

    // here we can pass 3rd argument as custom comparator. that return boolean according how we wan't our sorted array.
    // sort(v.begin(), v.end(),cmp);

    cout << "After sorting elements of vector v are : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // min_element function
    auto minptr = min_element(v.begin(), v.end());
    cout << "Minimum value in the vector v is : " << *minptr << endl;

    // max_element function
    auto maxptr = max_element(v.begin(), v.end());
    cout << "Maximum value in the vector v is : " << *maxptr << endl;

    // accumlate function {from numeric library}
    // {arguments: (starting pointer, ending pointer, initial value) , range : [start,end) }
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of whole array is : " << sum << endl;

    // all_of function
    cout << "Are all element of vector v greater then 0 ? " << all_of(v.begin(), v.end(), [](int x)
                                                                      { return x > 0; })
         << endl;
    // rather then passing lambda function we can use inbuilt function is_positive

    // any_of function
    cout << "Is there any element which is greater then 50 in vector v ? " << any_of(v.begin(), v.end(), [](int x)
                                                                                     { return x > 50; })
         << endl;

    return 0;
}