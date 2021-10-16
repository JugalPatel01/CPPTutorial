/* 
 given a n unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.

 */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s;
    cout<<"enter the sum you wan't from subarray ";
    cin>>s;
    int i=0,j=0;

    int st=-1,en=-1,sum=0;

    while(j<n && sum+arr[j] <=s){
        sum +=arr[j];
        j++;
    }
    if(sum == s){
    cout<<"index of starting subarray is "<<i+1<<" index of ending of subarray is "<<j<<endl;
    }
    
    while ((j<n))
    {
        sum+=arr[j];
        while(sum>s){
            sum -= arr[i];
            i++;
        }
        if(sum ==s ){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }

    cout<<"index of starting subarray is "<<st<<" index of ending of subarray is "<<en<<endl;
    

    return 0;
}