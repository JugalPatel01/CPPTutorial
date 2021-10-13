#include<iostream>
using namespace std;
int main() {

    int n,m;
    cout << "enter the size of the 2D array ";
    cin >> n >> m;
    int arr[n][m];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
        cin >> arr[i][j];
       }
    }

    cout<<"your matrix is \n";
     for (int  i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
         {
             cout<<arr[i][j] << "  ";
         }
         cout<<"\n";
     }

     int arrt[m][n];

     for (int i = 0; i < m; i++)
     {
         for (int  j = 0; j < n; j++)
         {
             arrt[i][j]=arr[j][i];
             cout<<arrt[i][j];
         }
         
     }
     cout << "your transposed matrix is \n";
     for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << arrt[i][j] << "  ";
         }
         cout << "\n";
     }

return 0;
}