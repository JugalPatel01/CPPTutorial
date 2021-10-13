#include<iostream>
using namespace std;

    /*  
    here in solution we make c as global variable so we can use it in whole program but
    if we declared c as local variable so after function excution the function will remove 
    from the stack and and memory which is allcoated for c is also will change. for purpose of 
    other function excution and c will be overwritten so we can't use it(local variable) as a pointer.

    But we can use pointer in main method because all the called function which are calling by the main are 
    above in stack so that pointers are not overwritten and we can use them.

    Conclusion :- it is okay to pass address of local variable from bottom to top of the call stack 
                  but it is not okay for viceversa.

    Application(used cases) :- we have some memory address of the heap section or in the global section then we
                               can safely written address of variables.
    */
// solution 1----------------------------

int c;   
int *Add(int* a, int* b){
    c = (*a)+(*b);
    return &c;
}
// // solution 2-----------------------

// int *Add(int* a,int* b){
//     int* c = (int*)malloc(sizeof(int));
//     *c = (*a) + (*b);
//     return c;
// }
int main() {
    int x = 2 , y = 4;
    int* ptr = Add(&x,&y);
    cout<<*ptr<<endl;
return 0;
}