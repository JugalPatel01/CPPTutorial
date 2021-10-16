#include <iostream>
using namespace std;
int knapsack(int value[], int wt[], int n, int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return knapsack(value, wt, n - 1, w);
    }
    return max(knapsack(value, wt, n - 1, w - wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, w));
}
int main()
{
    // enter weight
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int wt[n];
    cout << "enter the elements of the weight array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    // enter values
    int value[n];
    cout << "enter the elements of the value array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    // enter weight
    int w;
    cout << "enter weight of knapsack ";
    cin >> w;
    cout << knapsack(value, wt, n, w) << endl;
    return 0;
}