/*

    Implementing heap using STL

    push in max_heap = O(logN)
    pop in max_heap = O(logN)
    top in max_heap = O(1)
    size in max_heap = O(1)

 */
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> maxh;               // max heap
    priority_queue<int, vector<int>, greater<int>> minh; // min heap

    maxh.push(5);
    maxh.push(2);
    maxh.push(3);
    maxh.push(4);

    minh.push(5);
    minh.push(2);
    minh.push(3);
    minh.push(4);

    cout << "top of max heap : " << maxh.top() << endl;
    cout << "top of min heap : " << minh.top() << endl;

    maxh.pop();
    minh.pop();

    cout << "top of max heap after poping root element : " << maxh.top() << endl;
    cout << "top of min heap after poping root element : " << minh.top() << endl;

    return 0;
}