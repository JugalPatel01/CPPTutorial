#include <iostream>
using namespace std;
int main() {
    int a[2][3][4];
    printf("%d",a[1][0]-a[0][2]);
    cout<<endl;
    printf("%d",a[1][0]);
    cout<<endl;
    printf("%d",sizeof(a[1][0]));
    cout<<endl;
    printf("%d",a[0][2]);
    cout<<endl;
    printf("%d",sizeof(a[0][2]));
    

return 0;
}