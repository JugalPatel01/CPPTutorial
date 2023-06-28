/*
    Pointer as Function returns

    Q. if we want to return an address of variable from function then how can we do that ?

    -> so first solution is we make c as global variable so we can use it in whole program

    -> But if we declared c as local variable then after function excution the function and memory allocated for c both will
       remove from the stack for purpose of other function excution. And then c will be overwritten by some garbage value in it.
       so we can't use it(local variable) as a pointer.

    -> We can use pointer in main method/function because all the function which are called by the main function are above the
       main function in stack. so that pointers are not overwritten and we can use them.

    Conclusion :- it is okay to pass address of local variable from bottom to top of the call stack
                  but it is not okay for viceversa.

    Application(used cases) :- we have some memory address of the heap section or in the global section then we
                               can safely written address of variables.
*/
#include <iostream>
using namespace std;

// problem  -------------------------

int *Add_Prob(int *a, int *b)
{
    int x = (*a) + (*b);

    // below statement will give a warning at compilation time
    return &x;
}

// solution 1 -----------------------

int c;
int *Add(int *a, int *b)
{
    c = (*a) + (*b);
    return &c;
}

// solution 2 -----------------------

int *Add2(int *a, int *b)
{
    int *l = (int *)malloc(sizeof(int));
    *l = (*a) + (*b);
    return l;
}

int main()
{
    int x = 2, y = 4;
    int *prob_ptr = Add_Prob(&x, &y);

    // cout << "ans is : " << *prob_ptr << endl; // it will return some garbage value or crash the program because of security issues

    int *ptr1 = Add(&x, &y);
    cout << "ans from solution 1 : " << *ptr1 << endl;

    int *ptr2 = Add(&x, &y);
    cout << "ans from solution 2 : " << *ptr2 << endl;
    return 0;
}