#include <iostream>
using namespace std;

/*
        pascal triangle
         1
         11
         121
         1331
         14641
*/
int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int ncr(int n, int r)
{
    int ncr;
    ncr = fact(n) / (fact(n - r) * fact(r));
    return ncr;
}
int main()
{

    int n;
    cout<<"enter the stage of the pascal triangle ";
    cin >> n;

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= i; j++)
        {

            cout<<ncr(i, j)<<" ";
        }
        cout<<endl;
    }

    return 0;
}