#include<iostream>
using namespace std;

void func(int *a,int (*b)[2],int (*c)[2][2])   //(int a[],int b[][2],int c[][2][2])
{
    cout<<a[1]<<endl;
    cout<<b[1][1]<<endl;
    cout<<c[1][1][1]<<endl;

}
int main() {

int c[3][2][2] = {{{2,5},{7,9}},{{3,4},{6,1}},{{0,8},{11,13}}};

int a[2]= {1,2};

int b[2][2]={{1,2},{3,4}};


cout<<c<<endl;
cout<<*c<<endl;
cout<<c[0]<<endl;
cout<<&c[0][0]<<endl;
cout<<*(c[0][0]+1)<<endl;

cout<<"----------------------------------------------"<<endl;

func(a,b,c);
return 0;
}