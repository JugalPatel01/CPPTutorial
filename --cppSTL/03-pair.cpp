#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){

    return p1.first<p2.first;
}
int main()
{
    // defining a pair 
    pair<int, int> p;
    p.first = 3;
    p.second = 3;

    cout << p.first << " " << p.second << endl;

    int arr[] = {1, 5, 3, 3, 6, 3, 4, 32, 6, 3, 443, 63, 23};

    // using pair into vector 
    vector <pair<int,int>> v;

    /* we can also defining pair into 2d vector like this  */
        // vector <vector<pair<int,int>>> v;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        /* we can push pair into vector like this manually */

        // pair<int,int> p;
        // p.first = arr[i];
        // p.second = i ;
        // v.push_back(p);

        /* or like this using make_pair function */

        v.push_back(make_pair(arr[i],i));
    }
    
        sort(v.begin(),v.end(),cmp);
        
        for (int i = 0; i < v.size(); i++)
        {
            arr[v[i].second] = i;
        }
        for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
        {
            cout<<arr[i]<<" ";
        }
        
        


        return 0;
}