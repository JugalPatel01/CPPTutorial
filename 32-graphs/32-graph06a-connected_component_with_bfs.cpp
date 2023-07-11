/*

    * connected componenet in the graph

    -> A connected component is a subgraph in which any two vertices are connected to each other by paths, and which is
       connected to no additional vertices in the supergraph.


       0 --> 1 --> 2        3 --> 4 --> 5

       so in above case there in one supergraph which has two small subgraph and both are not connected to each other by any
       path. so we can say that subgroup 012 and 345 are connected components of supergraph.

    approach :
    -> we can use bfs and dfs traversal for finding connected componenet.if there is only one bfs/dfs tree for one graph
       there is only one connected component is present the graph and which is graph itself.
    -> if there are more than one bfs/dfs tree present for a single graph then there is multiple connected component present
       and their number is same as the number of bfs/dfs trees.

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &adj_list, vector<bool> &visited, int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    int count = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        count++;

        for (auto i : adj_list[x])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return count;
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


        0 --> 1 --> 2   3

        size of component 1 is : 3
        size of component 2 is : 1
        total components are : 2

        nodes = 4
        edges = 2
        template input : 4 2 0 1 1 2

     */
    vector<bool> visited(nodes, 0);
    int connected_count = 0;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            connected_count++;
            cout << "size of component " << connected_count << " is : " << bfs(graph_adj_list, visited, i) << endl;
        }
    }

    cout << "so, total connected components are : " << connected_count << endl;
    return 0;
}