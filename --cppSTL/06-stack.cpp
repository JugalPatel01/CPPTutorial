/*
    stack follow LIFO structure
    -> It is based on deque

    * operations of stack
    -> push()
    -> pop()
    -> top()
    -> empty()
    -> swap()
    -> emplace()

    emplace -> emplace is used to construct object in-place and avoid unnecessary copy of objects.
            -> insert and emplace are equal for premetive data types but when we deal with heavy objects we should use emplace.

    for learn more about initialisation list check out 20-OOPS02c-diamond_problem.cpp in 20-ObjectOrientedProgramming folder.
 */

#include <iostream>
#include <stack>
using namespace std;

class A
{
public:
    int x;
    // initialisation list
    A(int x = 0) : x{x} { cout << "Construct" << endl; }
    A(const A &cp) // copy constructor
    {
        x = cp.x;
        cout << "COPY" << endl;
    }
};
int main()
{

    stack<int> s1, s2;
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s2.push(1);
    s2.push(2);
    s2.push(9);
    s2.push(10);

    cout << "size of stack s1 :" << s1.size() << endl;
    cout << " Top element of s1:" << s1.top() << endl;

    s1.pop();
    cout << " Top element of s1 : " << s1.top() << endl;
    s1.pop();
    s1.pop();
    cout << " Top element of s1 : " << s1.top() << endl;

    cout << "check for emptiness of stack s1 : " << s1.empty() << endl;

    cout << "size of stack s1 : " << s1.size() << endl;

    cout << "before swapping size of s1 : " << s1.size() << "\tsize of s2 : " << s2.size() << endl;
    s1.swap(s2);
    cout << "after swapping size of s1 : " << s1.size() << "\tsize of s2 : " << s2.size() << endl;

    // emplace

    stack<A> a_stack;
    A b(10);
    // here we made b object and constructor called and then we copied that object into the stack. so , in stack also one object is created so copy was called
    a_stack.push(b);
    // here we make a object inside the stack only.
    a_stack.emplace(20);
    cout << a_stack.top().x << endl;

    return 0;
}