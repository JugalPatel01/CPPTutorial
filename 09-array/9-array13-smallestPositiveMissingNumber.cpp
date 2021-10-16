/* you are given an array arr[] of N integers including 0. The task is to find the smallest positive nuber missing from the array. */
#include<iostream>
using namespace std;
int main() {

int n;
cout << "enter the size of the array ";
cin >> n;
int arr[n];
cout << "enter the elements of the array \n";
for (int i = 0; i < n; i++)
{
    cin >> arr[i];
}

bool check[100000];
for (int i = 0; i < 100000; i++)
{
    check[i]=false;
}
for (int i = 0; i < n; i++)
{
    if (arr[i]>0)
    {
        check[arr[i]]=1;
    }

    
}
int ans=-1;
for (int i = 1; i < 100000; i++)
{
    if (check[i]==false)
    {
        cout<<"The smallest positive number which is missing from array is "<<i<<endl;
        break;
    }
    
}




return 0;
}