#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "----this is from for loop---------------\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "hello "<<i<<""<<endl;
    }

    cout<< "------this is from while loop--------------\n";
    int i =0; 
    while(i<10)
    {
        cout<< "hello "<<i<<""<< endl;
        i++;
    }
    cout<< "----This is from do-while loop-----------------\n";
    i=0;
     do{
        cout<<"hello " << i << ""<< endl;
        i++;
     }
     while(i<10);

     cout<< "----------loop control-----------(continue)\n";
    for(int i=0;i<100;i++){
        if(i%3==0){
            continue;
        }
        cout<<i<<"  ";
    }
     cout<< "----------loop control-----------(break)\n";
     int n,m;
     cin>>n>>m; 
     for(int num=n;num<=m;num++){
     for( i=2;i<num;i++){
         if(num%i==0){
             cout<< "not prime number "<<num<<"  \n"; 
             break;
         }
     }
      if(i==num)
         cout<<"prime number "<<num<<"  \n";
     }    
    return 0;
}