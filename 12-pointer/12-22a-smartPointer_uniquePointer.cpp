/*

    --> What is smart pointers in cpp?
        -> Java, C# kind of language uses garbage collection mechanism for deallocating unused memory to avoid memory leak, dangling pointers, wild pointer, etc. So, in C++ to achieve this kind of functionality there is a smart pointers.
        -> When object is destroyed it frees the memory as well. so, There is no need to delete memory as smart pointer will handle it.
        -> It is a wrapper class over a pointer with an operator like * and -> overloaded.
        -> It's implementation is achieved by RAII(Resource acquisition in Initialization)
        -> There are 4 types of smart pointers
                1) shared_ptr
                        -> It manages a shared ownership of a dynamically allocated object.
                        -> Multiple shared_ptr instances can point to the same object, and the memory is released when the last owner is destroyed.
                2) unique_ptr
                        -> It represents exclusive ownership of a dynamically allcoated object.
                        -> It cannot be copied, only moved, ensuring that there is only one owner at a time.
                3) weak_ptr
                        -> Special Case of Shared pointer.
                        -> It works with shared_ptr to prevent circular references. It does not affect the reference count of the object it points to.
                4) auto_ptr
                        -> It provides unique ownership but had some issues with copy semantics so this pointer is deprecated in C++ 11.

*/

/* 
        # unique_ptr
*/

#include <iostream>
#include <utility> // for move function
#include <memory>  // for smart pointers
#include <exception>
using namespace std;

class Rectange
{
        int length;
        int breadth;

public:
        Rectange(int l, int b) : length(l), breadth(b) {}

        int area() { return length * breadth; }
};

// Custom deleter function

void customDeleter(Rectange *ptr)
{
        cout << "from custom deleter of "<< ptr->area() << endl;
        delete ptr;
}

int main()
{
        unique_ptr<Rectange> R1(new Rectange(10, 5));

        cout << "Area of R1 is : " << R1->area() << endl;

        unique_ptr<Rectange> R2;
        R2 = std::move(R1);

        cout << "Area of R2 is : " << R2->area() << endl;
        if (R1)
        {
                cout << R1->area() << endl; // it will throw an exception because R1 no longer owns the object after the move
        }
        else
        {
                cout << "R1 is empty" << endl;
        }

        unique_ptr<Rectange> R3 = std::move(R2); // overloaded move constructor;

        // custom deleter
        unique_ptr<Rectange, void (*)(Rectange *)> R4(new Rectange(20, 10), customDeleter);
        cout << "Area of R4 is: " << R4->area();

        // resetting the value of R3
        R3.reset(new Rectange(30, 40));
        cout << "Rrea of R3 after reset is : " << R3->area() << endl;

        // use of the get for getting raw pointer
        Rectange* R5 = R4.get();
        cout<<" Area of R5 is : "<< R5->area()<<endl;

        return 0;
}