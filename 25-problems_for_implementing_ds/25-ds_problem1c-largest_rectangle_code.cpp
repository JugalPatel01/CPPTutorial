/*
    * Largest rectangle in a histogram
    Q: Given an array. Each element represents the height to the histogram's bar and the width of each bar is 1, find the area of largest rectangle in the histogram.
    -> i/p : [2,1,5,6,2,3]
    -> o/p :  10

    optimized solution using stack

*/

#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

int find_max_area(vector<int> a)
{
    int n = a.size(), i = 0;
    int max_area = 0;
    stack<int> st;
    /*
        -> here we added 0 at the end of the height vector because at last when we have some elements in our stack then we have to calculate max_area for them.
        -> so if last element is 0 then we can empty our stack through iterating our while loop becuase all the element in the stack are greater then 0.
     */
    a.push_back(0);
    while (i <= n)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();
            if (st.empty())
            {
                max_area = max(max_area, h * i);
            }
            else
            {
                // here we add 1 because top element of the stack is either smaller or equal to the current element so we have to consider the next element from the top element
                int len = i - (st.top() + 1);
                max_area = max(max_area, h * len);
            }
        }
        st.push(i);
        i++;
    }

    /*
    // if we don't push zero at the end of the height vector then we have to write below code for dealing with remaining element of stack.
        while (!st.empty())
        {
            int h = a[st.top()];
            st.pop();
            if (st.empty())
            {
                max_area = max(max_area, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                max_area = max(max_area, h * len);
            }
        }
     */

    return max_area;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of the array : ";
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << "largest area is : " << find_max_area(a) << endl;

    return 0;
}