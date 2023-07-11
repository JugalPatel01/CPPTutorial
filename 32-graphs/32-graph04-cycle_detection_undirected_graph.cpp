/*

    * Cycle detection in undirected graph
    -> we can find whether there is a cycle in the graph by making dfs and bfs trees from that graph.
    -> if bfs trees of that graph has any cross or slanted edge then that graph contain cycle.
        cross edge :
        slanted edge :
    -> if dfs tree of that graph has back edge then that graph contain cycle.

                0
               / \
              1   2
               \ /
                3

        DFS tree of above graph is DFS(0)

            0------
            |     |
            1     |
            |     |  <--- back edge
            2     |
            |     |
            3------

        BFS tree of above graph is BFS(0)

            0                              0
           / \                            / \
          1   2                          1   2
          |  / <---- slanted edge        |   |
          3 /                            3---4
                                           ^
                                           |------- cross edge


    ** approach for detecting cycle in the graph
    1) keep traversing the graph
    2) if you found an edge pointing to an already visited node(except the parent node ), a cycle is found.
*/

#include <iostream>
#include <vector>
using namespace std;

bool iscycle(int src, vector<vector<int>> &adj_list, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto i : adj_list[src])
    {
        if (i != parent)
        {
            if (visited[i])
            {
                return true;
            }
            if (visited[i] == false && iscycle(i, adj_list, visited, src))
            {
                return true;
            }
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

    vector<vector<int>> graph_adj_list(nodes);
    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);
    }

    /*

                        0
                       / \
                      1---2

        nodes : 3
        edges : 3
        cycle present : yes
        template input : 3 3 0 1 1 2 2 0


    */

    // find cycle using dfs tree
    bool cycle = false;

    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == false && iscycle(i, graph_adj_list, visited, -1))
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "cycle is present. " << endl;
    }
    else
    {
        cout << "cycle is not present. " << endl;
    }
    return 0;
}