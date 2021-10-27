#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}


int main() {
// find the given number in the array.
 
int n;
cout<<"enter the value of n for your array ";
cin>>n;

int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];

}
int key;
cout<< "enter the key value for searching ";
cin>>key;

cout<<"index of the key in the array is "<< linearSearch(arr,n,key);

return 0;
}