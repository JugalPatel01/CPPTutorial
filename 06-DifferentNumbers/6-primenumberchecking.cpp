// checking wheather a number is prime or not

#include<iostream>
#include<cmath>
using namespace std;
int main() {

int n; 
int flag;
cin>>n;
 for(int i=2;i<=sqrt(n);i++){
     if(n%i==0){
         cout<<n<<" is not prime number";
         flag=1;
         break;
        
     }if(flag==0){
         cout<<"prime"<<endl;
     }
 }
return 0;
}