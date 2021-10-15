// for 2D array
// a[i][j] = *(a[i]+j)
//         = *(*(a+i)+j)

#include <iostream>
using namespace std;
int main()
{
    int a[2][3]={{2,3,6},{4,5,8}};
    // int *p = &a[0][0];
    int (*p)[3]=a;
    cout<<a<<endl; // &a[0]
    cout<< *a <<endl; //&a[0][0]
    cout<< a+1 <<endl; // &a[1]
    cout<<*(a+1) <<endl ;
    cout<<*(a+1)+2<<endl; // a[1]+2 or &a[1][2]
    cout<<*(*a+1)<<endl;
    return 0;
}