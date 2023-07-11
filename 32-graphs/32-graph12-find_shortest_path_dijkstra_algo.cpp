/*

    * dijkstra's algorithm for finding shortest path to all the vertices from single node

    Q : Given a postive weighted graph. find the single source shortest path from a vertex u to all the vertices in the graph.
        If the node is unreachable, then print -1.
    -> Dijkstra works for both directed and undirected graph.
    NOTE : dijkstra's algorithm is not worked for negative weighted edge and that problem is solved by bellman ford algorithm

        approach :
        -> here we traverse all the edges and relex all edges.
           {because if we wan't a path then path has (nodes-1) edges otherwise that path will became cycle}
        -> relax means
             if distance[node] > distance[previous_node] + weight_of_connecting_edge
                then distance[node] = distance[previous_node] + weight_of_connecting_edge
             or
             distance[node] = min(distance[node] , distance[previous_node] + weight_of_connecting_edge )
        -> so after traversing all the edges we get minimum distance

    eg. :

                    (0)
                 24 / \ 3
                   /   \
                  (1)  (2)
                   \   /
                 20 \ / 12
                    (3)

        1) source = 0 => initial distance is [0 inf inf inf]
        2) now we traverse 01(24) and 02(3) so now distance is [0 24 3 inf]
                inf > 0 + 24  && inf > 0 + 3
        3) now for edge 13(20) we get [0 24 3 15]
                inf > 3 + 12;
        4) and for last edge 23(12) we get [0 24 3 15]
                15 < 24 + 20;   // so, this edge will not relax.


        so, dijkstra(0) will give : 0 24 3 15

*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct pair_cmp
{
    bool operator()(pair<int, int> &x, pair<int, int> &y)
    {
        return x.second > y.second;
    }
};

void dijkstra_algo(int src, vector<vector<pair<int, int>>> &adj_list, vector<int> &ans)
{
    ans[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> q;
    q.push({src, 0});

    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        for (auto i : adj_list[x.first])
        {
            if (ans[i.first] > ans[x.first] + i.second)
            {
                ans[i.first] = ans[x.first] + i.second;
                q.push({i.first, ans[i.first]});
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;

    vector<vector<pair<int, int>>> graph_adj_list(nodes);

    cout << "enter edges & it's weight : " << endl;
    for (int i = 0; i < edges; i++)
    {
        int x, y, w;
        cout << "edges = ";
        cin >> x >> y;
        cout << "weight = ";
        cin >> w;

        graph_adj_list[x].push_back({y, w});
        graph_adj_list[y].push_back({x, w});
    }

    /*
                    (0)
                 24 / \ 3
                   /   \
                  (1)  (2)
                   \   /
                 20 \ / 12
                    (3)

        nodes : 4
        edges : 4
        output : 0 24 3 15
        template input : 4 4 0 1 24 0 2 3 1 3 20 2 3 12

    */

    vector<int> ans(nodes, INT_MAX);

    dijkstra_algo(0, graph_adj_list, ans);

    cout << " Vertex distance from source node is : " << endl;

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}