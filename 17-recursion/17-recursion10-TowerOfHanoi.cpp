/* tower of honai */

#include<iostream>
using namespace std;
void tOH(int n,char src,char desti,char helper){

if(n==0){
    return;
}
    tOH(n-1,src,helper,desti);
    cout<<"Move From "<<src<<" to "<<desti<<endl; 
    tOH(n-1,helper,desti,src);

}
int main() {
    int n;
    cout<<"enter the number of block in the toi";
    cin>>n;
    tOH(n,'A','C','B');



return 0;
}