//check if a given number is power of 2
#include <iostream>
using namespace std;

/* here we use a logic that in binary 
    here if we have n and if we revert right most digit or significant digit and all other digit after significant digit of n then we get n-1 
   eg. n=1010
           |
         our right most digit if we revert it then we get
      n-1 = 1001 or


    n=10000
      |
      significant digit if we revert this and all the digit after this then we get 
    
    n-1 = 01111
    
 */
int main()
{

    int n;
    cout << "Enter number for check if a number is power of 2 or not " << endl;
    cin >> n;

    if ((n && (n & n - 1)) == 0)
    {
        cout << "inserted number is power of 2 " << endl;
    }
    else
    {
        cout << "inserted number is not power of 2";
    }

    return 0;
}