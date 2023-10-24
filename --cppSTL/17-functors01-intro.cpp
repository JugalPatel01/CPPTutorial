/*

    # functors

    * what is functors?
    -> A functor is a C++ class that acts like a function or function pointer.
    -> Functors are called using the same old function call syntax.
    -> Functors can contain state
    -> we known that function are a piece of code so functors are pointer to that function.

    * why we use functors?
    -> suppose there is a function which accepts only one argument but we have to pass lot more information
    -> so we can make all the information global which is not a good option
    -> so we use functors

    -> greater<int>(), plus<int>(), multiplies<int>()

    for more about inbuilt functors visit
                                        : https://en.cppreference.com/w/cpp/utility/functional
                                        : https://cplusplus.com/reference/functional/function/function/

 */
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

void mul_val(int &a)
{
    a = a * 10;
    cout << a << " ";
}

void print_val(int &a)
{
    cout << a << " ";
}

void change_all(int arr[], int n, void (*func)(int &))
{
    for (int i = 0; i < n; i++)
    {
        func(arr[i]);
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto fn1 = &mul_val;
    int x = 12;
    cout << "Multiply " << x << " with 10 : ";
    fn1(x);
    cout << endl;

    cout << "Print all the values in array : ";
    change_all(arr, n, print_val);

    cout << "Multiply all the values of array with 10 : ";
    change_all(arr, n, mul_val);

    cout << "Finally modified array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}