/*
    * what is functors?
    -> A functor is a C++ class that acts like a function or function pointer.
    -> Functors are called using the same old function call syntax.
    -> Functors can contain state

    * why we use functors?
    -> suppose there is a function which accepts only one argument but we have to pass lot more information
    -> so we can make all the information global which is not a good option
    -> so we use functors

    -> greater<int>(), plus<int>(), multiplies<int>()

    for more about inbuilt functors visit https://en.cppreference.com/w/cpp/utility/functional

 */
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
/*
int increment(int x)
{
    return (x + 1);
}
 */
class increment
{
private:
    int num;

public:
    increment(int n) : num(n) {}

    // This operator overloading enables calling operator function () on objects of increment
    int operator()(int arr_num) const
    {
        return num + arr_num;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // for applying increment to all elements of arr and store the modified elements back in arr[]
    /*

    * transform for unary opeartion
    transform(inputBegin, inputEnd, OutputBegin, unary_opeartion)

    * transform for binary opeartion
    transform(inputBegin1, inputEnd1,inputBegin2, OutputBegin, unary_opeartion)

   */

    /*
        // here we use increment function which takes value and increment by one but what if we want to kind of function like, increment by 5, increment by 10 , increment by 1.5 ,etc...
        // so we have to make lot more function for doing that task
        transform(arr, arr + n, arr, increment);

    */
    // so to avoiding above condition we use functors
    transform(arr, arr + n, arr, increment(5));
    transform(arr, arr + n, arr, increment(10));
    transform(arr, arr + n, arr, increment(1));

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;

    return 0;
}