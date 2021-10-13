#include<iostream>
using namespace std;

    
int sumOf (int n){
    if (n==0)
    {
        return 0;
    }
    
    int sum=sumOf(n-1);
    return n+sum;
}

int main() {
int a;
cin>>a;
cout<<sumOf(a);


return 0;
}