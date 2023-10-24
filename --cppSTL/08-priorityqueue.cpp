/*
    # Priority queue
    -> we use priority queue to implement max heap and min heap
    -> By default priority queue implement max_heap.
    -> if two elements have the same priority, then they are served according to their order in the queue.
    -> It can be implemented using vector and deque but generally it uses vector for implemetation.
    -> Internally it calls algorithm functions like make_heap, push_heap and pop_heap when needed.

    -> To learn more about priority queue visit : https://cplusplus.com/reference/queue/priority_queue/

*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> maxi_heap;
    maxi_heap.push(5);
    maxi_heap.push(6);
    maxi_heap.push(7);
    maxi_heap.push(8);
    maxi_heap.push(9);
    maxi_heap.push(10);
    cout << "Size of max_heap : " << maxi_heap.size() << endl;

    cout << "Elements of max_heap : ";
    int n = maxi_heap.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi_heap.top() << " ";
        maxi_heap.pop();
    }
    cout << endl;

    // min heap

    /*

        -> To implement min heap we use functors.
        -> first parameter is for datatype.
        -> second parameter is for container
        -> The third parameter, ‘Comparison Type’ can either be a function or functor (function object) that must have bool as
           return-type and must have 2 arguments.

        for learning more about functors refer to the 17-functors.cpp in --cppSTL folder

        To learn more about min-heap using priority queue visit : https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    */
    priority_queue<int, vector<int>, greater<int>> mini_heap;
    mini_heap.push(5);
    mini_heap.push(6);
    mini_heap.push(7);
    mini_heap.push(8);
    mini_heap.push(9);
    mini_heap.push(10);
    cout << "Size of Mini heap is : " << mini_heap.size() << endl;
    int m = mini_heap.size();
    cout << "Elements in mini heap are : ";
    for (int i = 0; i < m; i++)
    {
        cout << mini_heap.top() << " ";
        mini_heap.pop();
    }
    cout << endl;

    cout << "Whether mini heap is empty or not ? " << mini_heap.empty() << endl;
    return 0;
}