/*
    class is a user defined datatype to make a template for storing the same type of the data(we can say it as a container)

    class human{

        // data memebers of the class
        string name;
        int hand;
        int age;
        bool gender;
        string workingOfHand(qaw){
            return "to pick something and more";
        }
    }

    so above class is a template and we can make an instance for each human(like ramu,alice,bob,etc...)
    like ramu has 2 hand and his age is 23 and his hands are used in writing.

    so ramu is a object for the class human

    by default all the data members of a class are private so we have to make them public
*/

#include <iostream>
#include <string.h>
using namespace std;

class human
{
public:
    string name;
    int hand = 2;
    int age;
    bool gender;
    void printInfo()
    {
        cout << " name is " << name << endl;
        cout << " age is " << age << endl;
        cout << " gender of human is " << gender << endl;
    }
};

int main()
{

    // we can define 1 object like this
    human a;
    a.name = "ramu";
    a.age = 23;
    a.gender = 0; // 0 for male and 1 for female

    // for multiple objects we can define a array of human class datatype
    human arr[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "enter the name of human ";
        cin >> arr[i].name;
        cout << "enter the age ";
        cin >> arr[i].age;
        cout << "enter the gender ";
        cin >> arr[i].gender;
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i].printInfo();
    }

    return 0;
}