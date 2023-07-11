/*

    * binar_search
    -> use binary_search to find element in the sorted data structures.

    * lower_bound
    -> if value is present in the data structure then it return that value's pointer and if it's not present then it next bigger value's  pointer.

    * upper_bound
    -> if bigger value present in that data strcutre then it returns that value's pointer otherwise it returns last pointer of
    the data structure. eg. in set it returns set.end() in case if there is no bigger element in the set.

    * max , min , swap , reverse , rotate , sort , find , count , transform , next_permutation , prev_permutation, all_of,
      any_of, none_of, min_element, max_element
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

bool cmp(int a, int b)
{
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

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "is 5 is present in vector?? " << binary_search(v.begin(), v.end(), 5) << endl; // binary search
    cout << "is 15 is present in vector?? " << binary_search(v.begin(), v.end(), 15) << endl;

    cout << "lower bound --> " << lower_bound(v.begin(), v.end(), 51) - v.begin() << endl; // lower bound
    cout << "upper bound --> " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;  // upper bound

    int a = 5;
    int b = 3;
    cout << "max " << max(a, b) << endl; // max
    cout << "min " << min(a, b) << endl; // min

    cout << "a --> " << a << endl;
    cout << "b --> " << b << endl;
    swap(a, b); // swap
    cout << "a --> " << a << endl;
    cout << "b --> " << b << endl;

    string ab = "abcd";
    reverse(ab.begin(), ab.end()); // reverse
    cout << "string is " << ab;

    rotate(v.begin(), v.begin() + 1, v.end()); // rotate
    cout << "after rotate" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

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
    sort(v.begin(), v.end()); // sort  --> based on intro sort (mixture of)( quick sort, heap sort, insertion sort)

    // here we can pass 3rd argument as custom comparator. that return boolean according how we wan't our sorted array.
    // sort(v.begin(), v.end(),cmp);

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // min_element function
    auto minptr = min_element(v.begin(), v.end());
    cout << "minimum value in the array is : " << *minptr << endl;

    // max_element function
    auto maxptr = max_element(v.begin(), v.end());
    cout << "minimum value in the array is : " << *maxptr << endl;

    // accumlate function
    // argument in accumulate function is starting pointer, next pointer of ending pointer, and initial value
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum of whole array is : " << sum << endl;

    // all_of function
    cout << "are all element on a vector greater then 0 ? : " << all_of(v.begin(), v.end(), [](int x)
                                                                        { return x > 0; })
         << endl;
    // rather then passing lambda function we can use inbuilt function is_positive

    // any_of function
    cout << "is there any element which is greater then 50 ? : " << any_of(v.begin(), v.end(), [](int x)
                                                                           { return x > 50; })
         << endl;

    return 0;
}