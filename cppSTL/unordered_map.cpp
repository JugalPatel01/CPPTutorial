#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{

    unordered_map<int, string> u;

    u[1] = "abc";
    u[3] = "khb";
    u[2] = "5";

    for (auto i : u)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}