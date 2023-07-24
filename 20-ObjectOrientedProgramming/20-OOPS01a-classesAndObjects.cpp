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

#include <iostream>
#include <string.h>
using namespace std;

class human
{
    // private variables
    int hand = 2;
    string name;

public:
    int age;
    bool gender;
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
    } // copy constructor in this we pass address of the class in the parameter.
    // here if we don't make copy constructor then compiler itself make on copy constructor.

    /*
    -> for making a instances of class we have to make constructors public.

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
        cout << "both are same " << endl;
    }
    else
    {
        cout << "both are not same " << endl;
    }

    return 0;
}