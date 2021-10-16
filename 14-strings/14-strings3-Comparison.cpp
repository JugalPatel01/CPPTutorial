#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1 = "abc";
    string s2 = "xyz";
    string s3 = "abc";
    cout << s2.compare(s1) << endl;
    cout << s3.compare(s1) << endl;
    //compare
    if (s2.compare(s1) == 0)
    {
        cout << "strings are equal " << endl;
    }
    else
    {
        cout << "stirngs are distinct " << endl;
    }
    //clear
    s3.clear();
    if (s3.empty())
    {
        cout << "string is empty" << endl;
    }
    //erase
    s2.erase(1, 1); //in bracket first one is index from where we want to remove character and second one is length how many characters we wan't to remove.
    cout << s2 << endl;
    //find
    string s4 = "yellow";
    cout << s4.find("low") << endl;
    cout << s4.find("ow") << endl;
    //insert
    s2.insert(1, "y");
    cout << s2 << endl;

    //size

    cout << s4.size() << endl;

    for (int i = 0; i < s4.length(); i++)
    {
        cout << s4[i] << endl;
    }

    //substring

    string s5 = s4.substr(3, 3);
    cout << s5 << endl;

    //string to integer

    string s6 = "7989";
    int x = stoi(s6);
    cout << x + 5 << endl;

    //integer to string

    int y = 3424;
    cout << to_string(x) + "2" << endl;

    //sorting

    string s7 = "ablkadjfi";
    sort(s7.begin(), s7.end());

    cout << s7 << endl;

    return 0;
}