#include<iostream>
using namespace std;
int main() {

    /*
    palindromic pattern
    
      1
     212
    32123
    */

   int n;
   cout<<"enter the number of rows";
   cin>>n;

   for(int i=1;i<=n;i++){
       for(int j=1;j<=n-i;j++){
           cout<<"  ";
       }
       for(int j=1;j<=i;j++){
           cout<<i-j+1<<" ";
       }
       for(int j=2;j<=i;j++){
           cout<<j<<" ";
       }
       cout<<endl;


   }


return 0;
}
