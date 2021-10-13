#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{

    string str = "ablksdflkajsdf";
    //lower case to upper case
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    cout << str << endl;

    //upper case to lower case
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    cout << str << endl;

    //lower case to upper case using function

    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<str<<endl;

    //upper case to lower case using function
    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<str<<endl;
    return 0;
}