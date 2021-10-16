#include<iostream>
using namespace std;
void A(){
    printf("Hello");
}
void B(void (*ptr)()){
    ptr (); // call-back function that "ptr" points to
}
int main() {

// void (*P)() = A;
// B(P); 

B(A);   // A is callback function
return 0;
}