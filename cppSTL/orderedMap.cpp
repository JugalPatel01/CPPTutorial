#include <iostream>
#include <map>
using namespace std;
int main()
{

    map<int, string> m;

    m[1] = "abc";
    m[2] = "5";
    m[3] = "khb";
    m.insert({4, "kahd"});

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "finding 3 --> " << m.count(3) << endl;

    m.erase(3);
    cout << "after erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "finding 3 --> " << m.count(3) << endl;

    auto it = m.find(4);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    // finding number of occurance ;

    map<char, int> cnt;
    string x = "abcslakdlg akdl1 3 5 13 5 23 5 3 2";
    for (char c : x)
    {
        cnt[c]++;
    }
    for(auto i:cnt){
        cout<< i.first<<" "<<i.second<<endl;
    }
    cout<<cnt['1'];

    return 0;
}