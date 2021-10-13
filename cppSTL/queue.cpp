#include <iostream>
#include <queue>
using namespace std;
int main()
{

    queue<string> q;

    q.push("1");
    q.push("12");
    q.push("123");
    q.push("1234");
    q.push("1235");

    cout << "size of queue " << q.size() << endl;
    cout << "first element " << q.front() << endl;
    q.pop();
    cout << "first element " << q.front() << endl;

    cout << "size of queue " << q.size() << endl;

    cout << "empty or not " << q.empty() << endl;
    return 0;
}