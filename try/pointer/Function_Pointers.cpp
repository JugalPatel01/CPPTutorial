#include<iostream>
using namespace std;
// pointers can point to function

int add(int a, int b){
     return a+b;

}
void printHello(char *name){
    cout<<"Hello "<<name<<endl;
}

int main() {

    int (*p)(int,int); 
    p = add;        // equals to p = &add
    int c;
    c = p(2,3);     // equals to c = (*p)(2,3);
    cout<<c;

    void (*ptr)(char*);
    ptr = printHello;
    ptr("Jugal");

return 0;
}