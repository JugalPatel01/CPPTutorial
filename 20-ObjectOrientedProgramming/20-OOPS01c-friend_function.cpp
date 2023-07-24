/*

    * friend class and friend function :
    => friend class can access private and protected members of other classes(which declared it as a friend function.)
    => friend function is a function that is declared outside the class but is capable to accessing the private and protected
       members of class.
    NOTE : we can declare friend function or friend class anywhere in the base class.we can declare it in private block or protected block or public block.

    # why we have to use friend function ?
    -> friend function can acts as a bridge between two classes by accessing their private data.
    -> so, it is used to increase the versatility of overloaded operator(to known more about overaloded
       opeartor visit 20-OOPS3b-opeartor_overloading).

    # disadvantage of friend function :
    -> it can't do run-time polymorphism in their members.
    -> friendship is not inherited. If a base class has a friend function, then the function doesn’t become a friend of the derived class(es).

    NOTE : Friendship is not mutual & can't be. If class A is a friend of B, then B doesn’t become a friend of A automatically.

*/

#include <iostream>
using namespace std;

class ABC; // forword declaration of clss ABC because we are using it's object in class GHI

class GHI // for make GHI's method as a frined of ABC we have to delcare it before.
{
    int x;

public:
    GHI(int z)
    {
        x = z;
    }
    int sum_with_a(ABC &);
};

class ABC
{
    int a_from_abc, b_from_abc;

    // here we declare val_of_a_from_ABC function as a friend of ABC function
    // so now val_of_a_from_ABC function can use private and protected data of ABC class's object.
    friend int val_of_a_from_ABC(ABC &obj);

protected:
    friend int GHI::sum_with_a(ABC &);

public:
    ABC(int a, int b)
    {
        a_from_abc = a;
        b_from_abc = b;
    }

    // here we made DEF class as a friend of ABC class. so now DEF can access all the private and protected methods of ABC class.
    friend class DEF;
};

// friend class of class ABC
class DEF
{
public:
    void display(ABC &obj)
    {
        cout << "a of ABC's obj from DEF class : " << obj.a_from_abc << endl;
        cout << "b of ABC's obj from DEF class : " << obj.b_from_abc << endl;
    }
};

// friend function of class ABC (NOTE that it is note a member function of ABC class. so we can't call it through object of ABC)
int val_of_a_from_ABC(ABC &obj)
{
    return obj.a_from_abc;
}

// here sum_with_a is a member function of class DEF and friend function of class ABC.
int GHI::sum_with_a(ABC &a)
{
    return (x + a.a_from_abc);
}

int main()
{
    ABC obj1(5, 2);
    cout << " value of a from ABC is : " << val_of_a_from_ABC(obj1) << endl;
    DEF obj2;
    cout << "ABC class's obj's private variable accessed by DEF class's object : " << endl;
    obj2.display(obj1);

    GHI obj3(10);
    cout << "GHI class's sum_with_a method can access private variable of ABC class's object : " << obj3.sum_with_a(obj1);
    return 0;
}