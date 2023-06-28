#include<iostream>
using namespace std;
int main() {
/*  sum of each digit's cube is called armstrong number .
        1   5    3
        1  125  27 =153

*/


int n;
cin>>n;

int a= n;
int sum=0;

while(n>0){
    int ld = n%10;
    sum += ld*ld*ld;
    n=n/10;
}

if (sum==a){
    cout<<a<< " is a armstrong number.";
}
else{
    cout<<a<< " is not armstrong number. ";
}

return 0;
}
