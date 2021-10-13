#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){

    return p1.first<p2.first;
}
int main()
{

    pair<int, int> p;
    p.first = 3;
    p.second = 3;

    cout << p.first << " " << p.second << endl;

    int arr[] = {1, 5, 3, 3, 6, 3, 4, 32, 6, 3, 443, 63, 23};

    vector <pair<int,int>> v;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        pair<int,int> p;
        // p.first = arr[i];
        // p.second = i ;
        // v.push_back(p);

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