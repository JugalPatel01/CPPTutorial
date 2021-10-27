//0,1,1,2,3,5,8,13,21,....

#include<iostream>
using namespace std;

int fibo(int n){
    if(n==0||n==1){
        return n;
    }
    int ans=fibo(n-1)+fibo(n-2);
    return ans;

}

int main() {
int a;
cout<<"enter number"<<endl;
cin>>a;
cout<<a<<" element in fibonaaci series is "<<fibo(a-1)<<endl;

return 0;
}