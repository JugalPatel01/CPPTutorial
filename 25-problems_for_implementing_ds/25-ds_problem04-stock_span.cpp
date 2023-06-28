/*
    Stock Span Problem
    Q. The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward)
       for which the price of the stocks was less than or equal to today's price.
       find the span of the stocks for all the days.

    i/p : [100, 80, 60, 70, 60, 75, 85]
    o/p : [1, 1, 1, 2, 1, 4, 6]

    bruteforce appraoch is just go for nested loop and count days.

    create a stack of pairs which contains price & days
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
// bruteforce
vector<int> find_span(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int day = 0;
        for (int j = i; j >= 0; j--)
        {
            if (v[i] >= v[j])
            {
                day++;
            }
            else
            {
                break;
            }
        }
        ans[i] = day;
    }
    return ans;
}
 */

vector<int> find_span(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int day = 1;
        while (!st.empty() && st.top().first <= v[i])
        {
            day += st.top().second;
            st.pop();
        }
        st.push(make_pair(v[i], day));

        ans[i] = day;
    }

    return ans;
}

int main()
{
    int n;
    cout << "enter days : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter stock price : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "stack span is : ";
    vector<int> ans = find_span(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}