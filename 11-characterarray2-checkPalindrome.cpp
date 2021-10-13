#include<iostream>
using namespace std;
int main() {
int n;
cout<<"enter length of name ";
cin>>n;
char arr[n+1];
cout<<"enter name ";
cin>>arr;

bool check=1;
for (int i = 0; i < n; i++)
{
    if(arr[i]!=arr[n-1-i]){
        check=0;
        break;
    }
}
if (check)
{
    cout<<"word is a palindrome"<<endl;
}
else{
    cout<<"word is not a palindrome"<<endl;
}
return 0;
}