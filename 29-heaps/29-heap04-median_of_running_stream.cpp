/*

    * Median of Running Stream
    Q : Numbers are coming and we have to tell median after each input.

    eg. [10 15 21 30 18 19]

    after 1ˢᵗ input :
    sorted array : 10           Median : 10
    after 2ⁿᵈ input :
    sorted array : 10 15          Median : 12.5
    after 3ʳᵈ input :
    sorted array : 10 15 21          Median : 15
    after 4ᵗʰ input :
    sorted array : 10 15 21 30         Median : 18
    after 5ᵗʰ input :
    sorted array : 10 15 18 21 30        Median : 18
    after 6ᵗʰ input :
    sorted array : 10 15 18 19 21 30        Median : 18.5

    appraoch :
    in bruthforce it takes N*log(N) for sorting and for N element it became N² * log(N).

 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "enter total elements in an array : ";
    cin >> n;
    int arr[n];
    cout << "Enter element an array : ";
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (auto &i : arr)
    {
        cin >> i;

        if (max_heap.empty())
        {
            // if max_heap is empty
            max_heap.push(i);
        }
        else if (min_heap.empty())
        {
            // if min_heap is empty
            min_heap.push(i);
        }
        else
        {
            // if size of min_heap is less then max_heap so we have to push in min_heap
            if (min_heap.size() < max_heap.size())
            {
                // if inserted element is greater then top of min_heap then push in min_heap
                if (min_heap.top() <= i)
                {
                    min_heap.push(i);
                }

                // if inserted element is smaller then top of min_heap then two cases
                else
                {

                    int x = max_heap.top();
                    // if top of max_heap is less then inserted element then push in min_heap
                    if (i > x)
                    {
                        min_heap.push(i);
                    }
                    // and if top of max_heap is greater then inserted element then pop element from max_heap
                    // push that element into min_heap and
                    // insert new element in max_heap
                    else
                    {
                        min_heap.push(x);
                        max_heap.pop();
                        max_heap.push(i);
                    }
                }
            }
            // if size of min_heap and max_heap are equal then we have to push in max_heap
            else
            {

                // if inserted element is smaller then top of max_heap then push in max_heap
                if (max_heap.top() >= i)
                {
                    max_heap.push(i);
                }
                // if inserted element is greater then top of max_heap then two cases
                else
                {
                    int x = min_heap.top();
                    // if top of min_heap is greater then inserted element then push in max_heap
                    if (x >= i)
                    {
                        max_heap.push(i);
                    }
                    // and if top of min_heap is smaller then inserted element then pop element from min_heap
                    // push that element into max_heap and
                    // insert new element in min_heap
                    else
                    {
                        max_heap.push(x);
                        min_heap.pop();
                        min_heap.push(i);
                    }
                }
            }
        }

        if (max_heap.size() > min_heap.size())
        {
            cout << "median is : " << (double)max_heap.top() << " ";
        }
        else
        {
            cout << "median is : " << ((double)max_heap.top() + (double)min_heap.top()) / 2.0 << " ";
        }
        cout << endl;
    }
    return 0;
}