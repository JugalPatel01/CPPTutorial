#include<iostream>
#include<queue>
using namespace std;
int main() {

    int arr[5];
    printf("%d\n",arr);
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    int *k ;
    k = arr;
    for (int i = 0; i < 5; i++)
    {
        cout<<k<<endl;
        cout<<*k<<endl;
        k++;
      
    }
    
    
    // int x = 5;
    // int *p ;
    // p = &x;
    // printf("%d\n",p);
    // cout<<*p<<endl;
    // p = p +1;
    // printf("%d\n",p);



    return 0;
}