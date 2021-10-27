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
    cout<<"sum of each subarray is "<<endl;
    int currsum;
    int sum=0;
    for (int  i = 0; i < n; i++)
    {   
        currsum=0;
        for (int j = i; j < n; j++)
        {
            currsum+=arr[j];
            cout<<currsum<<endl;
        }
            sum=max(sum,currsum);
        
    }

    cout<<"\nSum of the all the subarray is "<<sum<<endl;


return 0;
}