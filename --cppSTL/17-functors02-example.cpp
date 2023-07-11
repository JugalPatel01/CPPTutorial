/*

    * transform for unary opeartion
    transform(inputBegin, inputEnd, OutputBegin, unary_opeartion)

    * transform for binary opeartion
    transform(inputBegin1, inputEnd1,inputBegin2, OutputBegin, unary_opeartion)

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

    cout << "values of array before : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // for applying increment to all elements of arr and store the modified elements back in arr[]

    /*
        // here we use increment function which takes value and increment by one but what if we want to kind of function like, increment by 5, increment by 10 , increment by 1.5 ,etc...
        // so we have to make lot more function for doing that task
        transform(arr, arr + n, arr, increment);

    */
    // so to avoiding above condition we use functors
    transform(arr, arr + n, arr, increment(5));
    transform(arr, arr + n, arr, increment(10));
    transform(arr, arr + n, arr, increment(1));

    cout << "values of array after incremented by 16 (5, 10, 1) are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}