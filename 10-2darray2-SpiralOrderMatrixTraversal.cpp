/* 
        start - - - - >
           ^  - - - > |
           |  ^  >  | |
           |  < - - \/|
            < - - - - \/


    above figure is spiral order matrix 
 */

#include <iostream>
using namespace std;
int main()
{
   int n, m;
   cout << "enter the size of the 2D array ";
   cin >> n >> m;
   int arr[n][m];
   cout << "enter the elements of the array \n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> arr[i][j];
      }
   }

   int rowstart = 0;
   int rowend = n - 1;
   int colstart = 0;
   int colend = m - 1;

   while (rowstart <= rowend && colstart <= colend)
   {
      //for rowstart
      for (int col = colstart; col <= colend; col++)
      {
         cout << arr[rowstart][col] << " ";
      }
      rowstart++;
      //for colend
      for (int row = rowstart; row <= rowend; row++)
      {
         cout << arr[row][colend] << " ";
      }
      colend--;
      // for row end

      for (int col = colend; col >= colstart; col--)
      {
         cout << arr[rowend][col] << "  ";
      }
      rowend--;
      // for col start
      for (int row = rowend; row >= rowstart; row--)
      {
         cout << arr[row][colstart] << " ";
      }
      colstart++;
   }

   return 0;
}