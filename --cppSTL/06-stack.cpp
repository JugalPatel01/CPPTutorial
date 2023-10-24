/*
    # Stack
    -> Stack follows LIFO(last in first out) structure
    -> Stack can be implemented using vector, deque, linked list. but generally It is based on deque.

    * operations of stack
    -> push()
    -> pop()
    -> top()
    -> empty()
    -> swap()     ~> for swapping two stacks.
    -> emplace()

    emplace -> emplace is used to construct object in-place and avoid unnecessary copy of objects.
            -> insert and emplace are equal for premetive data types but when we deal with heavy objects we should use emplace.

    To learn more about initialisation list check out 20-OOPS02c-diamond_problem.cpp in 20-ObjectOrientedProgramming folder.

    To learn more about stack visit : https://cplusplus.com/reference/stack/stack/

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

    cout << "Size of stack s1 : " << s1.size() << endl;
    cout << "Top element of s1 : " << s1.top() << endl;

    s1.pop();
    cout << "Top element of s1 : " << s1.top() << endl;
    s1.pop();
    s1.pop();
    cout << "Top element of s1 : " << s1.top() << endl;

    cout << "Check whether stack s1 is empty or not ? " << s1.empty() << endl;

    cout << "Size of stack s1 : " << s1.size() << endl;

    cout << "Before swapping size of s1 : " << s1.size() << "\tsize of s2 : " << s2.size() << endl;
    s1.swap(s2);
    cout << "After swapping size of s1 : " << s1.size() << "\tsize of s2 : " << s2.size() << endl;

    // Emplace

    cout << "Before using emplace in stack insertion : " << endl;

    stack<A> a_stack;
    A b(10);
    /*
        Here we made b object so it's constructor called and then we copied that object into the stack.
        So, in stack also one object is created so copy constructor was called.
    */
    a_stack.push(b);

    cout << "After using emplace in stack insertion :" << endl;
    /*
        here we make a object inside the stack's emplace method only.
    */
    a_stack.emplace(20);
    cout << "Top of the a_stack is : " << a_stack.top().x << endl;

    return 0;
}