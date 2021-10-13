#include<iostream>
using namespace std;
int SumOfElements(int* arr,int n){
    int i, sum = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {

int arr[]= {1,2,3,4,5};
int total = SumOfElements(&arr[0],sizeof(arr)/sizeof(arr[0]));

cout<<total;
return 0;
}