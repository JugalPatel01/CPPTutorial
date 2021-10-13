#include<iostream>
#include<stack>
using namespace std;
int main() {

stack<int> s;
s.push(3);
s.push(4);
s.push(5);
s.push(6);
s.push(7);
s.push(8);
cout<<"size of stack "<<s.size()<<endl;
cout<<" Top element "<< s.top()<<endl;

s.pop();
cout<<" Top element "<< s.top()<<endl;
s.pop();
cout<<" Top element "<< s.top()<<endl;
s.pop();
cout<<" Top element "<< s.top()<<endl;

cout<<"check for empty " << s.empty()<<endl; 

cout<<"size of stack "<<s.size()<<endl;

return 0;
}