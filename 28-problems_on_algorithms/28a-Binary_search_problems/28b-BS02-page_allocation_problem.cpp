/*

    * Page Allocation problem
    Q : All the books have to be divided among m students, consecutively. Allocate the pages in such a way that maximum pages
        allocated to a student is minimum.

    i/p : n - numbers of pages = [12,34,67,90] , m - numbers of students = 2
    o/p :
        possible allocations are :
        [12][34,67,90] -> end 191
        [12,34][67,90] -> end 157
        [12,34,67][90] -> end 113

        so, ans is : [12,34,67][90]
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool has_en_pages(vector<int> v, int min_page, int students)
{
    int n = v.size() - 1, student_required = 1;
    int check_sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (v[i] > min_page)
        {
            return false;
        }
        if (check_sum + v[i] > min_page)
        {
            student_required++;
            check_sum = v[i];
            if (student_required > students)
            {
                return false;
            }
        }
        else
        {
            check_sum += v[i];
        }
    }
    return true;
}

int find_min_pages(vector<int> v, int student)
{

    int ans = INT_MAX, sum = 0;
    for (auto i : v)
        sum += i;
    int start = 0, end = sum;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (has_en_pages(v, mid, student))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, students;
    cout << "enter total no. of books : ";
    cin >> n;

    vector<int> v(n);
    cout << "enter pages of each books : ";
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());

    cout << "enter total no. of students for dividing pages : ";
    cin >> students;

    if (n >= students)
    {
        int min_pages = find_min_pages(v, students);

        vector<vector<int>> ans;
        vector<int> x;
        int pos = v[0];
        x.push_back(v[0]);
        for (auto i = 1; i < n; i++)
        {
            if (pos < min_pages)
            {
                pos += v[i];
                x.push_back(v[i]);
            }
            else
            {
                ans.push_back(x);
                x.clear();
                pos = v[i];
                x.push_back(v[i]);
            }
        }
        ans.push_back(x);

        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "students are more then books :< " << endl;
        return 0;
    }

    return 0;
}
