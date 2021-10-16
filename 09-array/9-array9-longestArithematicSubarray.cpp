/* An arithmetic array is an array that contians at least two integers and thedifferences between consecutive integers are equal. 
    eg.      [3,3,3,3], [9,7,5,3]

    question:

    he has an array of N non-negative integers. The i-th integer of the array is Ai. 
    he wants to choose a contiguous arithmetic subarry from his array that has the maximum length.
    Please help him to determine the length of the longest contiguous arithmetic subarray.

 */

#include <iostream>
using namespace std;
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

    cout << "longest contiguous arithmetic subarray's length is ";
    int curr = 2;
    int pd = arr[1] - arr[0];
    int ans = 2;

        for (int j = 2; j < n; j++)
        {
            if ((arr[j] - arr[j - 1]) == pd)
            {
                curr++;
            }
            if ((arr[j] - arr[j - 1]) != pd)
            {
                pd = arr[j] - arr[j-1];
                curr = 2;
            }
            ans=max(curr,ans);
        }
cout<<ans<<endl;
    return 0;
}