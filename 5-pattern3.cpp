#include <iostream>
using namespace std;
int main()
{
// reverse pyramid pattern
    int n; 
    cout<<"enter the number of stage in pyramid ";
    cin>>n;
     
     for(int i=n;i>=1;i--){
         for(int j=1;j<=i;j++){
             cout<<"*";
         }
         cout<<endl;
     }
    return 0;
}