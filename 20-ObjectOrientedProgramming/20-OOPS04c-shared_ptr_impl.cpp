/*
    # Implementation of Shared pointers using oops concepts
        -> It retains shared ownership of an object through a pointer, several shared_ptr objects may own the same object.
        -> The object is destroyed and its memory deallocated when either the last remaining shared_ptr owning the object is destroyed or the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().

*/

#include <iostream>
#include <memory>
#include <utility>
using namespace std;

template <typename T>
class sharedptr
{
private:
    int *counter;
    T *memo;
    inline void increment_counter()
    {
        if (counter)
            (*counter)++;
    }

    inline void decrement_counter()
    {
        if (counter)
        {
            --(*counter);

            if ((*counter) == 0)
            {
                if (memo)
                {
                    delete memo;
                    delete counter;
                    memo = nullptr;
                    counter = nullptr;
                }
            }
        }
    }

public:
    // parameterized constructor
    sharedptr(T *ptr = nullptr) : memo(ptr), counter(new int(1)) {}

    // copy constructor
    sharedptr(const sharedptr<T> &obj) : memo(obj.memo), counter(obj.counter)
    {
        increment_counter();
    }

    // move constructor
    sharedptr(sharedptr<T> &&obj) : memo(obj.memo), counter(obj.counter)
    {
        obj.memo = nullptr;
        obj.counter = nullptr;
    }

    // copy assignment operator
    sharedptr<T> &operator=(const sharedptr<T> &obj)
    {
        if (this != &obj)
        {
            decrement_counter();
            memo = obj.memo;
            counter = obj.counter;
            increment_counter();
        }
        return *this;
    }

    // move assignment operator
    sharedptr<T> &operator=(sharedptr<T> &&obj)
    {
        if (this != &obj)
        {
            decrement_counter();
            memo = obj.memo;
            counter = obj.counter;
            obj.memo = nullptr;
            obj.counter = nullptr;
        }
        return *this;
    }

    // resetting the shared pointer with some other value
    void reset(T *obj = nullptr)
    {
        decrement_counter();
        memo = obj;
        delete counter;
        counter = new int(1);
    }

    // returning raw pointer of the main resource
    T *get()
    {
        return memo;
    }

    // returning count of the total shared_pointer which are pointing to the resource
    int get_count()
    {
        if (counter)
        {
            return *counter;
        }
        return -1; // or we can throw an error
    }

    // overloading * operator
    T &operator*()
    {
        return (*memo);
    }

    // overloading -> operator
    T *operator->()
    {
        return memo;
    }

    // Destructor
    ~sharedptr()
    {
        decrement_counter();
    }
};

int main()
{
    sharedptr<int> p1;                 // default constructor
    sharedptr<int> p2(new int(10));    // parameterized construtor
    sharedptr<int> p3(p2);             // copy constructor
    p3 = p2;                           // copy assignment operator
    sharedptr<int> p4 = std::move(p1); // move constructor
    p2 = std::move(p3);

    p1.reset(); // resetting value of the shared pointer
    p1.reset(new int(5));
    p2.get(); // getting raw pointer of the shared pointer

    cout << *p1 << endl; // implementing * operator
    // p1->func();  // implementing -> operator

    cout << p1.get_count(); // it will return number of objects pointing to the same resources.

    return 0;
}