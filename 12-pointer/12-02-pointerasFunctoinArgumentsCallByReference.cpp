#include<iostream>
using namespace std;
void Increment(int *a)// call by reference 
{
    *a = *a+ 1;
}
int main()
{

int a=10;
Increment(&a);// here we pass address of the variable a so that while we assign the value to the function it dereferenced it to a and then all the action are perfomed on the a not the assigned value like call by value.
cout<<a;
return 0;
}