/* character array                             strings

->need to know size beforehand.         -> no need to know size beforehand.
->larger size required for operations   -> perfomring operations liek concatenation & append is easier.
-> no terminating extra                 -> termianted with a special character '\0'
character.              
 */

#include<iostream>
#include<string>
using namespace std;
int main() {
string str;
cin>>str;
cout<<str<<endl;

//or

string str1(5, 'n');
cout<<str1<<endl;

//or

string str2="JugalPatel";
cout<<str2<<endl;

//or

string str3;
getline(cin,str3);
cout<<str3<<endl;


return 0;
}