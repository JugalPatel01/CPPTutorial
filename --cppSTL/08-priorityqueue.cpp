/*
    priority queue
    -> we use priority queue to implement max head and min heap
    -> if two elements have the same priority, then they are served according to their order in the queue.
    -> It is based on vector

 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> maxi;
    maxi.push(5);
    maxi.push(6);
    maxi.push(7);
    maxi.push(8);
    maxi.push(9);
    maxi.push(10);
    cout << "size  " << maxi.size() << endl;
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    // min heap

    /*
        for implementing min heap we use functors

        second parameter is for container

        The third parameter, ‘Comparison Type’ can either be a function or functor (function object) that must have bool as return-type and must have 2 arguments.

        for learning more about functors refer to the 17-functors.cpp in --cppSTL folder
    */
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(5);
    mini.push(6);
    mini.push(7);
    mini.push(8);
    mini.push(9);
    mini.push(10);
    cout << "size  " << mini.size() << endl;
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "is empty? " << mini.empty() << endl;
    return 0;
}