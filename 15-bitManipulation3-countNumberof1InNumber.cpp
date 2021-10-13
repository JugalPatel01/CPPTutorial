#include<iostream>
using namespace std;
int numberOfOnes(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
        
    }
    return count;
}
int main() {

int n;
cout<<"Enter number"<<endl;
cin>>n;
cout<<"total number of ones in binary representation of a number is "<<numberOfOnes(n)<<endl;

return 0;
}