/*
    # Async and future
        -> Async provides a way to execute tasks asynchronously.
        -> It allows launching a task asynchronously(in parallel) that may return a result at some point in the future.
        -> When using std::async, we can specify a launch policy : 
                1) launch::async --> It forces the function to be executed in a new thread.
                2) launch::deferred --> It defers the execution of the function until get() is called on the std::future object.
                3) launch::any --> It allows the implementation to choose whether to execute the function in a new thread of defer it. 
        -> It retrieve results later using the std::future object.
        -> future is a template class that represents a value that will be computed in the future. It provides a mechanism for retrieving the result of an asynchronous task.

*/

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std;

int sum(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return a + b;
}

int main()
{

    future<int> ft_ans = std::async(std::launch::async, sum, 10, 20);

    cout << "Sum of A and B is " << ft_ans.get();

    return 0;
}