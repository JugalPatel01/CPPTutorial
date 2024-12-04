/*
    * Class : it is a user defined datatype to make a template for storing the same type of the data(we can say it as a
              container for variables and methods)

    * Object : it is a runtime instance of the class.

    * Constructor : It is a special member function with the same name as of the class name. It used to initialize the object
                    of its class and it is invoked automatically when object of the class is initialized.

    class human{

        // data memebers of the class
        string name;
        int hand;
        int age;
        bool gender;
        string workingOfHand(){
            return "to pick something and more";
        }
    }

    so above class is a template and we can make an instance for each human(like ramu,alice,bob,etc...)
    like ramu has 2 hand and his age is 23 and his hands are used in writing.

    so ramu is an object for the class human.

    by default all the data members of a class are private so we have to make them public.

    * Data Abstraction : hidding process which is not necessary to known to the user.
    like
    -> In DBMS(database management system) it is not necessary to know how to data stores in the behind,how it fetch data from the database, how they manage data for easy accessing, etc..,
       so without knowing all these stuff user can easily use and access the database.

    * Encapsulation : it is a way to restrict the direct access to some components of an object, so users cannot access state values for all of the variables of a particular object.
    -> It can be used to hide both data members and data functions or methods associated with an instantiated class or object
    -> It is achieved by declaring the instance variables of a class as private. To allow outside access to the instance variables, public methods called getters and setters are defined.getters and setters may have their own data validation rules.

    * Dynamic binding : Binding at compile time is known as static binding. and Binding at Run time is called dynamic binding
    -> eg. of static binding : function overloading , operator overloading
    -> eg. of dynamic binding : virtual functions
*/

/*
    # size of class object is depended on various factors which are shown below :
    1) size of all non-static data members (because static variables are not part of class object)
    2) order of data members (it is based on compiler optimization)
      a> suppose we declare variable in char ,int ,int order then it takes 12 bytes because Even though char will consume only 1
         byte,4 bytes will be allocated for it, and the remaining 3 bytes will be wasted (holes).
      -> This is because the next member is an int, which takes 4 bytes.if we don't go to the next (4th) byte for storing this
          integer member, the memory access/modify cycle for this integer will be 2 read cycles
      b> if we declare variable in int,int,char order then it takes 9 bytes.
    3) byte alignment or byte padding
    4) size of it's immediate base class
    5) the existence of virtual functions
    6) compiler being used
    7) Mode of inheritance


    for more about class object memory visit : https://www.cprogramming.com/tutorial/size_of_class_object.html
 */

#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

class human
{
    // private variables
    int hand = 2;
    string name;

public:
    int age;
    bool gender;
    // -> for making a instances of class we have to make constructors public.
    human()
    {
        cout << "call from the default constructor" << endl;
    } // default constructor

    human(string s, string s2 = "not given") // we can pass default values in the constructor like shown
    {
        if (s == "")
        {
            name = s2;
        }
        name = s;
        cout << "call from the parameterised constructor" << endl;
    } // parameterised constructor

    human(human &a)
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
        cout << " call from the copy constructor" << endl;
    } // copy constructor : In this we pass address of the class in the parameter.
    // NOTE : If we don't make copy constructor then compiler itself create a copy constructor.

    /*

    # Deep copy and shallow copy

    * there are two types of copy constructors
     1) defalut copy constructor 2) defined copy constructor

     deafult copy constructor doing shallow copy and defined copy constructor doing deep copy.
     shallow copy : The object and its copy, point to the same memory address. If we make a change
                    in its copy it gets changed in the main copy as well and vice versa.
     deep copy : The object and its copy, point to different addresses in the memory. If we make a
                    change in its copy it will not get changed in the main copy and vice versa.

     so In shallow copy changes made in the copied object also reflect the original object.

     for more about shallow and deep copy check out on below link
     https://www.geeksforgeeks.org/difference-between-shallow-and-deep-copy-of-a-class/

    */

    /*
        # Move constructor and (lvalue and rvalue references)

        -> The move constructor is used to transfer ownership of resources from one object to another object, avoiding need of duplicate deep copies and make process more efficient.
        -> it is using rvalue reference(&&) for passing object as a parameter in consructor.
        -> for accessing move constructor we are using move function which is in the utility library.

        * what is lvalue and rvalue references ?
            -> lvalue referneces (&) : it is only used to bind lvalues(lvalues are appears on left side and they occupies some identifiable memory which we can use through &).
                                     : It provide a reference to an existing object with a name and memory address.
            -> rvalue references (&&) : it is only used to bind rvalues(rvalues are appears on the right side and they are temporary objects)
                                      : It is used for move semantic, to optimize performance by avoiding deep copies of resources.
                                      : eg. int x = 10 ; here x is a lvalue and 10 is rvalue.(rvalue are temporary objects)

         NOTE : To learn more about move constructor visit : https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
    */

    human(human &&a) : name(a.name), age(a.age), gender(a.gender)
    {
        cout << "call from the move constructor and it's now transfering ownership of name resources" << endl;
        a.name = "";
        a.age = 0;
        a.gender = false;
    } // move constructor

    ~human()
    {
        cout << "call from the Destructor" << endl;
    } // destructor for human object

    // setter and getter methods are used for incapsulation
    void set_name(string s)
    {
        name = s;
    } // setter method

    string get_name()
    {
        return name;
    } // getter method

    void printInfo()
    {
        cout << " name is " << name << endl;
        cout << " age is " << age << endl;
        cout << " gender of human is " << gender << endl;
        cout << "total " << hand << " hands " << name << " has." << endl;
    }

    // operator overloading for polymorphism
    bool operator==(human &a)
    {
        if ((name == a.name && age == a.age && gender == a.gender))
        {
            return true;
        }
        return false;
    }
};

int main()
{

    // we can define 1 object like this
    human a;
    a.set_name("ramu");
    a.age = 23;
    a.gender = 0; // 0 for male and 1 for female

    // for multiple objects we can define a array of human class datatype
    human arr[2];
    for (int i = 0; i < 2; i++)
    {
        string sname;
        int atemp;
        bool gtemp;
        cout << "enter the name of human ";
        cin >> sname;
        arr[i].set_name(sname);
        cout << "enter the age ";
        cin >> atemp;
        arr[i].age = atemp;
        cout << "enter the gender ";
        cin >> gtemp;
        arr[i].gender = gtemp;
    }

    for (int i = 0; i < 2; i++)
    {
        arr[i].printInfo();
    }

    // accessing parameterised constructor
    human x("x");
    // human x = human("x");        // these both are valid ways to initialize the constructor.
    x.age = 23;
    x.gender = 0;

    // copy constructor
    // human y(x);
    human y = x;
    y.printInfo();

    // opeartor overloading for polymorphism
    if (x == y)
    {
        cout << "After overloadiing we can see both x and y are same " << endl;
    }
    else
    {
        cout << "method overloading fails and both x and y are not same " << endl;
    }

    // move constructor
    human genz = std::move(y);

    // here after using move constructor all the resources which are belonging to y object is now transfered to the genz object. so here y object don't have any values in it as shown below.
    cout << "printing values of genz after using move constructor" << endl;
    genz.printInfo();
    cout << endl;
    cout << "printing values of y after using move constructor" << endl;
    y.printInfo();

    return 0;
}