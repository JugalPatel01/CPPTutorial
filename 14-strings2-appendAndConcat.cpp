#include<iostream>
#include<string>
using namespace std;
int main() {
    string s1 = "fam";
    string s2 = "ily";

    s1.append(s2);
    cout <<"from append " <<s1 <<endl;

    cout<<"from concate " <<s1+s2 <<endl;

    cout<<s1[1]<<endl;

    string abc=" helasklfjaf d flkjsf";
    cout<<abc;
    abc.clear();
    cout<<abc;

    return 0;
}