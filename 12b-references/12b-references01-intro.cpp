/*

    * References

    -> A reference is a variable that is referred to as another name for an already existing variable. The reference
       of a variable is created by storing the address of another variable.
    -> In pointers we can re-assign values but we can't do that thing with references
    -> A pointer can be assigned NULL directly, whereas a references can't be.
    -> In pointer we have pointer to pointer (multi level indirection), but references only offer one level
       of indirection
    -> we can't use arithmatic operation on references

*/

#include <iostream>
using namespace std;

int increase(int n) // passing n as value
{
    n++;
    return n;
}

void increase_with_references(int &n) // passing n by reference
{
    n++;
}

void change_string(string &s)
{
    s = "";
}

int main()
{
    int a = 3;
    cout << "actual value of a : " << a << endl;
    a = increase(a);
    cout << "a's value after increase it by 1 in increase function : " << a << endl;
    increase_with_references(a);
    cout << "a's value after increase it by 1 in increase_with_references function : " << a << endl;
    cout << a << endl;
    string s = "abc";
    cout << "string before change is : " << s << endl;
    change_string(s);
    cout << "string after change is : " << s << endl;
    return 0;
}