/*

   * find negative cycle in grpah using bellman-ford algorithm

    eg.
                    5        10
                (0)---->(1)---->(2)
                         ^       |
                         |  -8   |
                         |-------|

    approach :
    -> here rather then relaxing edges for (nodes-1) time we will relax all the edges (no. of nodes) times
    -> we will check that if given ans by pass (nodes-1) and given ans by pass (nodes) is same or not
    -> if it's same then there is no negative cycle present in the graph. otherwise there is a negative cycle in the graph.


*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool bellman_ford_algo(int src, int nodes, vector<vector<int>> const &edges, vector<int> &ans)
{
    ans[src] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto e : edges)
        {
            int x = e[0];
            int y = e[1];
            int w = e[2];
            if (ans[x] != INT_MAX && (ans[x] + w < ans[y]))
                ans[y] = ans[x] + w;
        }
    }

    for (auto e : edges)
    {
        int x = e[0];
        int y = e[1];
        int w = e[2];
        if (ans[x] != INT_MAX && ans[x] + w < ans[y])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;

    vector<vector<pair<int, int>>> graph_adj_list(nodes);
    vector<vector<int>> graph_edges;

    cout << "enter edges & it's weight : " << endl;
    for (int i = 0; i < edges; i++)
    {
        int x, y, w;
        cout << "edges = ";
        cin >> x >> y;
        cout << "weight = ";
        cin >> w;

        graph_adj_list[x].push_back({y, w});

        graph_edges.push_back({x, y, w});
    }

    /*

                   5        10
                (0)---->(1)---->(2)
                         ^       |
                         |  -18  |
                         |-------|

        nodes : 3
        edges : 3
        output : 0 5 15
        template input 2 : 3 3 0 1 5 1 2 10 2 1 -18



    */

    vector<int> ans(nodes, INT_MAX);

    cout << "is there any negative edges cycle in the graph ? : " << bellman_ford_algo(0, nodes, graph_edges, ans) << endl;

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}