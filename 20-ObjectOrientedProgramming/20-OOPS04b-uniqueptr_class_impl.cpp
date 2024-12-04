/*
    # Implementation of Unique pointers using oops concepts
        -> unique_ptr stores one pointer only. We can assign a different object by removing the current object form the pointer.
        -> explanation about smart pointers is in (12-pointer\12-22a-smartPointer_uniquePointer.cpp), Here is a implementation of that unqiue_ptr class using OOPS concepts.

*/

#include <iostream>
#include <utility> // for move function
#include <memory>  // for smart pointers
using namespace std;

template <typename T>
class uniqueptr
{
private:
    T *memo;

public:
    // parameterized constructor
    uniqueptr(T *a = nullptr) : memo(a)
    {
        // cout << "inside constructor : ";
    }

    // copy constructor
    uniqueptr(const uniqueptr<T> &a) = delete;

    // move constructor
    uniqueptr(uniqueptr<T> &&a)
    {
        memo = a.memo;
        a.memo = nullptr;
    }

    // overload copy assignment operator
    uniqueptr &operator=(const uniqueptr<T> &a) = delete;

    // overload move assignment operator
    uniqueptr &operator=(uniqueptr<T> &&a)
    {
        if (this != &a)
        {
            if (memo)
            {
                delete memo;
            }
            memo = a.memo;
            a.memo = nullptr;
        }

        return *this;
    }

    T *operator->()
    {
        return memo;
    }

    T operator*()
    {
        return *memo;
    }

    T *get()
    {
        return memo;
    }

    void reset(T *a = nullptr)
    {
        if (memo)
        {
            delete memo;
        }
        memo = a;
    }

    // destructor
    ~uniqueptr()
    {
        try
        {
            if (memo)
            {
                delete memo;
                memo = nullptr;
            }
        }
        catch (const exception &e)
        {

            cerr << "Exception caught : " << e.what() << endl;
        }

        // cout<<"call from distructor";
    }
};

int main()
{
    uniqueptr<int> ptr1(new int(10));
    // uniqueptr<int> ptr2(ptr1); // copy constructor -> It will give compilation error
    // uniqueptr<int> ptr3 = ptr1; // copy constructor -> It will give compilation error
    uniqueptr<int> ptr4(new int(500));
    // ptr4 = ptr3; // copy operator -> It will give compilation error
    uniqueptr<int> ptr3 = std::move(ptr1); // move constructor
    ptr4 = std::move(ptr3);

    // ptr1->func();            // overload -> operator
    cout << *ptr4 << endl;   // overload * operator for getting value of at the pointer.
    ptr4.get();              // it will return raw pointers of the resource
    ptr4.reset(new int(30)); // resetting pointer

    return 0;
}