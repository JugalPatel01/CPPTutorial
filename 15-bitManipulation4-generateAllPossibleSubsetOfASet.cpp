#include <iostream>
using namespace std;

/*  here logic is number of all the subset of set is 2^n so we go for 2^n time loop and at every single loop we get on subset 
    so here suppose we have 2 elements in set {a,b}
    so in the first loop we get i=0 to i=2^n=2^2=4. so we have total 4 subset of this {a,b}
    now in second loop we check every single digit means 
    here we have four subset and they are like 
    00      {}        (i&1<<j)  here i=0==0 and j =0 so 1<<j = 2^0 = 01 so we get 0 | i=0 and j=1 so (1<<j)=2==10 so we get 0 ==  { }  |  { }
    01      {b}       (i&1<<j)  here i=1==01 and j =0 so 1<<j = 2^0 = 01 so we get 1 and print a | i=1==01 and j=1 so (1<<j)=2==10 so we get 0 == {a} | { }
    10      {a}       (i&1<<j)  here i=2==10 and j =0 so 1<<j = 2^0 = 01 so we get 0 | i=2==10 and j=1 so (1<<j)=2==10 so we get 10 and print b == { } | {b} 
    11      {a b}     (i&1<<j)  here i=3==11 and j =0 so 1<<j = 2^0 = 01 so we get 01 and print a | i=3==11 and j=1 so (1<<j)=2==10 so we get 10 and print b == {a} | {b}

        NOTE:  1<<n is left shift and 
 */
void subset(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    subset(arr, n);

    return 0;
}