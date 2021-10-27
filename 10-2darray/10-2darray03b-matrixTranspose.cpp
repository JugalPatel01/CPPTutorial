#include<iostream>
using namespace std;
int main() {

    int n;
    cout << "enter the size of the 2D array ";
    cin >> n ;
    int arr[n][n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
        cin >> arr[i][j];
       }
    }
    cout<<"your matrix is \n";
     for (int  i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
           cout<<arr[i][j] << "  ";
        }
        cout<<"\n";
     }

     for (int i = 0; i < n; i++)
     {
         for (int j = i; j < n; j++)
         {
             int temp=arr[i][j];
             arr[i][j]=arr[j][i];
             arr[j][i]=temp;
             
         }
         
     }
     cout << "your matrix is \n";
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << arr[i][j] << "  ";
         }
         cout << "\n";
     }

return 0;
}