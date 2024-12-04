/*
    2) Run time polymorphism : we achieve this kind of polymorphism by function overriding using virtual functions in cpp


    # some interesting things about pointers :
    -> pointers can be used for base objects as well as objects of derived classes.
    -> The pointer of Base class pointing different objects of the derived class
    -> A derived class is a class that takes some properties from its base class and it it true that a pointer of one class can point to another class, but classes must be base and derived class, then only it is possible.
    -> To access the variable of the base class, a base class pointer will be used.So, a pointer is a type of base class, and it can access all, public function and variables of the base class since the pointer is of the base class,this is known as binding pointer.
    -> In this pointer base class is owned by the base class but points to the derived class object.

    NOTE 1: we can make virtual functions, virtual destructor but we can't make virtual constructor because if we make the constructor virtual then how can we create an object? (becuase to create an object we are using constructor).

    NOTE 2: Virtual functions cannot be static.


*/
/*
    # upcasting and object creation

    * Ways to make objects in inheritance to achieve polymorphism  :
        -> We can make object from parent(base) class and child(derived) class in three ways :
            1) parent(base) class's object using parent(base) class's reference
                -> We can call only those methods which are defined in the parent(base) class.
            2) child(derived) class's object using parent(base) class's reference ((Upcasting))
                ->  Upcasting is the process of treating a Child class object as if it were an object of its Parent class.
                -> Here we can call only those methods which are defined in the parent(base) class. If child(derived) class has overridden any methods from the parent(base) class, the child(derived) class's version of those method will be executed.
            3) child(derived) class's object using child(derived) class's referenece
                -> Here we can call all the methods which are defined in the parent(base) class and child(derived) class. If child(derived) class has overridden any method from the parent(base) class, then child(derived) class's version of those method will be executed.

*/

/*
    # Virtual Tables (vtables)
        -> It is a lookup table used by objects at runtime to determine which method to invoke when a method is called on an object through a base class pointer or reference.
        -> Means it is a table of function pointers used to resolve which virtual function to call at runtime.
        -> Vtables are a static array of function pointers. Each entry in this table corresponds to a virtual funtion in the class.
        -> If a class has virtual function then compiler creates a vtable for that class.

        * How vtables works ?
            -> when a class hasone or more virtual functions, the compiler automatically creates a vtable for that class.
            -> Each derived class that overrides a virtual function will have its own vtable, which will point to the overridden methods.
            -> when we call a virtual function on an object, the vtable is used to dynamically resolve which function implementation to call, depending on the actual type of the object.


    # Virtual pointers (Vpointers)
        -> It is a hidden pointer inside each object that points to the vtable of the object's class. It is usually automatically added by the compiler when a class has virtual function.

        * How vpointers works ?
            -> Each object of a class with virtual functions contains a vpointer. The vpointer points to the vtable corresponding to the actual class of the object.
            -> When a virtual function is called on an object, the vpointer is used to access the vtable, and the appropriate function is then called via the function pointer in the vtable.

    # Virtual destructor
        -> It ensures that the destructor of the correct child(derived) class is called when an object is deleted through a parent(base) class pointer.
        -> This is critical in scenarios where a parent(base) class pointer or reference is used to delete an object that is actually an instance of a child(derived) class. If the destructor is not virtual, only the parent(base) class's destructor will be called, which can lead to resource leaks, improper cleanup or undefined behavior if the child(derived) class has its own destructor that needs to be executed.
*/

#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "constructor of class A." << endl;
    }

    virtual void func()
    {
        cout << " this is func from class A ." << endl;
    }

    void funcb()
    {
        cout << "This is funcb from class A ." << endl;
    }

    virtual ~A()
    {
        cout << "Destructor of class A." << endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout << "constructor of class B." << endl;
    }

    void func()
    {
        cout << "This is func from class B." << endl;
    }

    void funcb()
    {
        cout << " This is funcb from class B." << endl;
    }

    ~B()
    {
        cout << "Destructor of class B." << endl;
    }
};
int main()
{

    cout << "For object created in the heap using new keyword : " << endl;
    A *a;
    B *b = new B();

    // upcasting which is equal to the
    // A *a = new B();   // here we can call all the method which are defined in the parent(base) class and if there are any method which is overridden by child(derived) class then child class's version will be execute there.
    a = b;

    // (*a).func();
    a->func();
    a->funcb();

    delete a;
    /*

        # what is the sequence for calling destructor?
        -> Here we have used upcasting for creating an object means we created an object of the Child(derived) class but reference it using a Parent(base) class reference.
        -> So when we delete this object through the Parent(base) class reference, it will only call the destructor of the Parent(base) class.
        -> Now suppose we have virtual destructor in parent(base) class then both destructor will be called first child(derived) class's destructor will be called and then parent(base) class's destructor will be called.


        NOTE : here the above scenario is for only when we declare a object in heap(using new keyword) and we are destructing object using delete keyword. if we declare it in local stack then things will be different because when main function will be removed from the local stack(memory stack) at that time all the variables will be destroyed automatically.

            -> in this scenario even though destructor is not declared as virtual in the parent(base) class both destructor will be called in c++14. and first it will call child(derived) class's destructor and then it will call parent(base) class's destructor.
            -> Now suppose there is destructor only in child(derived) class and not in the parent(base) class then in this case child(derived) class's destructor will be called. but in other scenario where object is created in heap there will no destructor will be called.
    */
    cout << "---------------------------------------------------------" << endl;
    cout << "For object created in the Memory stack : " << endl;

    // here if you remove virtual keyword from the destructor of class A then also sequence of destructor will be same for below scenario.
    A *c;
    B d;
    c = &d;
    c->func();
    c->funcb();

    return 0;
}