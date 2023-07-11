/*

    * cycle detection in directed graph

    bruteforce appraoch:
    take one node's adjacency list and check all the node's adjacency list that whether there is a taken node in that list.
    if present then there is a cycle. otherwise there is no cycle.


*/

#include <iostream>
#include <vector>
using namespace std;

bool iscycle(vector<vector<int>> &adj_list, vector<bool> &visited, vector<bool> &stack, int src)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;

        for (auto i : adj_list[src])
        {
            if (stack[i])
            {
                return true;
            }
            if (visited[i] == false && iscycle(adj_list, visited, stack, i))
            {
                return true;
            }
        }
    }
    stack[src] = false;
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

        // x --> y

        graph_adj_list[x].push_back(y);
    }

    /*

                0 --> 1
                ^     ^
                |     |
                2 ----

                No cycle is present.

                nodes = 3
                edges = 3
                template input : 3 3 0 1 2 1 2 0

     */
    bool cycle = false;
    vector<bool> stack(nodes, 0);
    vector<bool> visited(nodes, 0);

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == false && iscycle(graph_adj_list, visited, stack, i))
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "there is cycle in the graph. " << endl;
    }
    else
    {
        cout << "there is no cycle in the graph. " << endl;
    }

    return 0;
}