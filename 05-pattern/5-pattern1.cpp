#include<iostream>
using namespace std;
int main()
{

    //square and rectangle
    int rows,cols;
    cin>>rows>>cols;

    for(int i=1;i<=rows;i++){

        for(int j=1;j<=cols;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}