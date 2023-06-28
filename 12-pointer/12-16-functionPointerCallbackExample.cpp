/*
    * Example of function pointers and call backs
    -> In this program callback function should compare two integers, should return 1 if first element has higher rank,
    0 if elements are equal and -1 if second element has higher rank.
*/
#include <iostream>
#include <math.h>
using namespace std;
int compare(int a, int b)
{
    if (a > b)
        return 1; // here this function return 1 for a>b so we can sort array in ascending order.
    // if about if statement return -1 then we can sort array in descending order.
    else
        return -1;
}
int absolute_compare(int a, int b)
{
    if (abs(a) > abs(b))
        return 1;
    return -1;
}
void BubbleSort(int *a, int n, int (*compare)(int, int))
{
    int i, j, temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (compare(a[j], a[j + 1]) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{

    int a[] = {-3, 4, -2, -1, 2, -3};
    cout << "for absolute value sorting press 1 for normal value sorting press  press 2 " << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        BubbleSort(a, sizeof(a) / sizeof(a[0]), absolute_compare);
        break;
    case 2:
        BubbleSort(a, sizeof(a) / sizeof(a[0]), compare);
        break;

    default:
        cout << "run code again";
        break;
    }
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}