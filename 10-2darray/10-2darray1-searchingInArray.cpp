#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "enter the size of the 2d array ";
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

    cout<<"matrix is :"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //for searching 

    int key;
    cout<<"enter the number for searching in matrix"<<endl;
    cin>>key;
    bool flag=false;

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            if (arr[i][j]==key)
            {
                cout<<"the number is at "<<i  <<" & "<< j <<" index number ";
                flag=true;
            }
            
        }
        
    }
    if (flag==true)
    {
        cout<<"element is present in array .";  
    }else{
        cout<<"element is not present in array.";
    }
    
    

    return 0;
}
