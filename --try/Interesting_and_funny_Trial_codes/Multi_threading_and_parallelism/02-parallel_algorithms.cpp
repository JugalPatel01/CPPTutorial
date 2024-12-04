/*
    # Parallel algorithms
        -> It is type of the execution for the algorithms. It leverage multiple threads or processes to perform computations concurrently.
        -> There are basically 3 way to achieve parallelism in the C++ :
            -> 1) Multithreading using <thread>, <mutex>, <atmoic> and therad pools
                    -> std::thread : It is a simple abstraction for creating threads.
                    -> std::jthread : It manages threads more efficiently.
            -> 2) Parallel Algorithms in <algorithms> header via the std::execution policy.
                    -> we can perform operations like std::for_each, std::sort, std::transform,etc.. in parallel.
                    -> Execution policies
                            -> 1) std::execution::par --> This is for Parallel execution(can run operations concurrently).
                            -> 2) std::exectuion::seq --> This is for sequential execution(default behaviour).
                            -> 3) std::execution::par_unseq --> This is for parallel and unsequenced execution(unordered results).
            -> 3) use of std::async and futures to execute tasks asynchronously.
                    -> It allows launching a task that may return a result at some pointer in the future.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
using namespace std;

int main()
{
    vector<int> v = {2, 63, 74, 37, 34, 85, 8, 357, 578};
    std::sort(std::execution::par, v.begin(), v.end());

    std::for_each(std::execution::par, v.begin(), v.end(), [](int &x)
                  { x += x; });

    for (auto &i : v)
    {
        cout << i << endl;
    }
    return 0;
}