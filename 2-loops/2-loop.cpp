#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "----This is from for loop---------------\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "hello I am for loop "<<i<<""<<endl;
    }

    cout<< "------This is from while loop--------------\n";
    int i =0; 
    while(i<10)
    {
        cout<< "hello I am while loop "<<i<<""<< endl;
        i++;
    }
    cout<< "----This is from do-while loop-----------------\n";
    i=0;
     do{
        cout<<"hello I am do-while loop" << i << ""<< endl;
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

     cout<< "\n----------loop control-----------(break)(Is number is prime or not between two numbers)\n";
     int n,m;
     cout<<"Enter the range "<<endl;
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