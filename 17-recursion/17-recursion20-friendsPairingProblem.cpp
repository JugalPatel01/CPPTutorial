//find the number of ways in which n friends can remain single or can be paried up.

#include<iostream>
using namespace std;

int pairing(int n){
    if( n ==0 || n == 1 || n==2 ){
        return n;
    }
    return pairing(n-1) + pairing(n-2)*(n-1);
}
int main(){
    int n;
    cout<<"enter number of friedns. : "<<endl;
    cin>>n;

    cout<<pairing(n)<<endl;


    return 0;
}