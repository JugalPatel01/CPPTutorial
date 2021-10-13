//here rows and cols are sorted .

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
 int key;
 cout<<"enter key value ";
 cin>>key;
 int r=0,c=n-1;
 bool found=false;
while (r<n&&c>=0)
{   
    if (arr[r][c]==key)
    {
        found = true;
        break;
    }
    if (arr[r][c]>key)
    {
        c--;
    }
    else{
        r++;
    }
    
    
}
if (found==true)
{
    cout<<"your given key is found in matrix ";
}else{
    cout<<"your given key is not found in matrix " ;
}


return 0;
}