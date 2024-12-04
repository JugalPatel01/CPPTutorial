/*
    # shared_pointer - Smart pointer
        -> using shared_ptr more than one pointer can point to the same object at a time.
        -> It maintains a refernece counter by using use_count() method

    # weak_ptr - Smart pointer
        -> It is a smart pointer that holds a non-owning refernece to an object.
        -> It is same like a shared_ptr except it will not maintain a reference count. 
        -> In weak_ptr pointer will not have a stronghold on the object. The reason is to avoid the circular dependency created by two or more object pointing to each other using shared_ptr.
*/

#include <iostream>
#include <utility>
#include <memory>
using namespace std;

class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {};

    int area() { return length * breadth; }
};

int main()
{
    shared_ptr<Rectangle> R1(new Rectangle(10, 20));
    cout << "Area of R1 is : " << R1->area() << endl;

    shared_ptr<Rectangle> R2;
    R2 = R1; // copying 'shared_ptr' to another pointer.
    cout << "Area of R2 is : " << R2->area() << endl;

    // check for the uniuqe ness of shared pointer
    if (R1.unique())
    {
        cout << "This is the only owner of R1 and use count is : " << R1.use_count() << endl;
    }
    else
    {
        cout << "use count of the R2 : " << R2.use_count() << endl;
    }

    // release ownership of R1 and set it to the nullptr
    R1.reset();
    cout << "use count of the R2 after resetting R1 : " << R2.use_count() << endl;

    // getting raw pointer.
    Rectangle *R3 = R2.get();
    cout << " Area of R3 is :" << R3->area() << endl;

    // swapping shared pointers.
    shared_ptr<Rectangle> R4 = make_shared<Rectangle>(30, 40);
    cout << "Area of R4 is : " << R4->area() << endl;

    // swap R2 and R4
    R2.swap(R4);
    cout << "Area of R2 is : " << R2->area() << endl;
    cout << "Area of R4 is : " << R4->area() << endl;

    // using weak_ptr to avoid circular references
    weak_ptr<Rectangle> WeakR1 = R4;
    if (auto R4_copy = WeakR1.lock()) // try to obtain shared_ptr from weak_ptr
    {
        cout << "R4 is still valid, area: " << R4_copy->area() << endl;
    }
    else
    {
        cout << "R4 has expiered" << endl;
    }

    R4.reset();

    if (auto R4_copy = WeakR1.lock())
    {
        cout << "R4 is still valid, area : " << R4_copy->area() << endl;
    }
    else
    {
        cout << "R4 has expired after reset." << endl;
    }

    return 0;
}