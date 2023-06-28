/* 
    # Access modifiers
    1) public -> available to everyone. public memebers of a class can be accessed from anywhere in the program
    2) private -> accessed only by the member functions or friends functions inside the class. They are not allowed to be accessed directly by any object or function outside of the class.
    3) protected -> same as private class, but can be accessed by any subclass too.

 */

// Example of Multilevel inheritance 
#include <iostream>
using namespace std;

class Ground
{
    int Rooms;

protected:
    void put()
    {
        cout << " call from put" << endl;
    };

public:
    void get()
    {
        cout << " call from get" << endl;
        
    };
};

// here all the inheritable attributes of class Ground goes to the private of the class Middle so we can't inherite them in further inheritance.
class Middle : private Ground
{
    int Labs;

public:
    void Take()
    {
        cout << " call from Take" << endl;
    };
    void Give()
    {
        cout << " call from Give" << endl;
    };
    void Callput(){
        put();
    }
};

class Top : public Middle
{
    int Roof;

public:
    void In()
    {
        cout << " call from In" << endl;
    };
    void Out()
    {
        cout << " call from Out" << endl;
    };
};
int main()
{
    Middle m;
    // m.get();     // here we can't call get because it's a private function for class Middle
    m.Take();
    m.Callput();
    return 0;
}