/*

    * Floyd WArshall Algorithm for finding all pair shortest paths.
    i.e. For every x,y in graph g, find the shortest path from x to y.
    -> this algorithm works on every type of graph (directed,undirected,weighted,unweighted)

    appraoch :
    -> we find distace between two nodes from each vertex as intermediate vertex.
    -> so at the end we get all pair shorest path distace
    -> it's time complexity is O(n³).
    -> it's space complexity is O(n²).

    eg.       5
        (0) -----> (1)
         |          |
       3 |          | 10
         \/         \/
        (2) -----> (3)
              1
    i/p : [ [  0   5   3   INF ]
            [ INF  0  INF  10  ]
            [ INF INF  0   1   ]
            [ INF INF INF  0   ]]

    o/p : [[ 0  5   3   4 ]
           [INF  0  INF 10]
           [INF INF 0   1 ]
           [INF INF INF 0 ]]

 */

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;
const int INF = 1e9;

void floyd_warshall_algo(vector<vector<int>> &adj_mtx, vector<vector<int>> &ans)
{
    for (int i = 0; i < adj_mtx.size(); i++)
    {
        for (int j = 0; j < adj_mtx.size(); j++)
        {
            for (int k = 0; k < adj_mtx.size(); k++)
            {
                if (ans[j][i] != INT_MAX || ans[i][k] != INT_MAX)
                    ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
        for (auto i : ans)
        {
            for (auto j : i)
            {
                if (j == INF)
                {
                    cout << "INF ";
                }
                else
                    cout << j << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    // int nodes;
    // cout << "enter no. nodes : ";
    // cin >> nodes;
    vector<vector<int>> graph_adj_mtrx = {
        {0, 5, 3, INF},
        {INF, 0, INF, 10},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    vector<vector<int>> dist_ans = graph_adj_mtrx;

    floyd_warshall_algo(graph_adj_mtrx, dist_ans);

    for (auto i : dist_ans)
    {
        for (auto j : i)
        {
            if (j == INF)
            {
                cout << "INF ";
            }
            else
                cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}