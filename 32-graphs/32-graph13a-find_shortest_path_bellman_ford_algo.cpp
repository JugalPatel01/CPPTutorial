/*

    * bellman ford algoritm for find shortest path to all nodes from source node
    -> it is just like a dijkstra's algorithm but here we will do n-1 relaxation(total vertices+1 relaxations) for each edges to
       overcome dijkstra's algorithm's limitations.
    -> after doing relaxation if distance changed for another relaxation then we can say that there is a negative edge cycle.


    eg.
                    5        10
                (0)---->(1)---->(2)
                         ^       |
                         |  -8   |
                         |-------|
        approach :
        -> in unlike dijkstra's algorithm we relax every edges for (nodes-1) time.
        -> here nodes are 3 so (nodes-1) = (3-1) = 2 , so we will relax all the edges for 2 times
        -> in first pass all relaxes of edges will give ans [0 5 INF]
        -> in second pass all relaxes of edges will give ans [0 5 15]



*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <math.h>
using namespace std;

struct pair_cmp
{
    bool operator()(pair<int, int> &x, pair<int, int> &y)
    {
        return x.second > y.second;
    }
};

void bellman_ford_algo(int src, int nodes, vector<vector<int>> &edges, vector<int> &ans)
{
    ans[src] = 0;

    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto e : edges)
        {
            int x = e[0];
            int y = e[1];
            int w = e[2];

            ans[y] = min(ans[y], ans[x] + w);
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

        // for undirected graph add below line
        // graph_adj_list[y].push_back({x, w});

        graph_edges.push_back({x, y, w});
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
        template input 1 : 4 4 0 1 24 0 2 3 1 3 20 2 3 12

                   5        10
                (0)---->(1)---->(2)
                         ^       |
                         |  -8   |
                         |-------|

        nodes : 3
        edges : 3
        output : 0 5 15
        template input 2 : 3 3 0 1 5 1 2 10 2 1 -8



    */

    vector<int> ans(nodes, INT_MAX);

    bellman_ford_algo(0, nodes, graph_edges, ans);

    cout << " Vertex distance from source node is : " << endl;

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}