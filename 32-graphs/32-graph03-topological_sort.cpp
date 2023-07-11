/*

    * topological order/sort
    -> Topological sorting for "Directed Acyclic Graph (DAG)" is a linear ordering of vertices such that for every directed
       edge ab(a->b), vertex a comes before b in the ordering.
    -> so if a graph has cycle then we can't find topological order for that graph.
    NOTE : Topological ordering are not unique.

    -> Indegree : The number of inward directed edges on vertex in a directed graph.
    -> so here concept is take vertices which has 0 indegrees and add it in the output list. after that remove that zero
       indegree vertices and connected edges with that vertices . now you get another 0 indegree vertices and repeat same
       procedure until zero vertices and edges are remain.so in the final list we get the topological order of the graph.

                              A
                            ^ ^ ^
                           /  |  \
                           B  C   D
                          ^ ^  ^
                          / \   \
                          E  F   G

        topological order : E F G D B C A
                          : D F G E B C A
                          : D F E G B C A
                          etc...

        NOTE : there is one other approach to find topological order using postorder dfs graph traversal.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;
    vector<int> indeg(nodes, 0);

    // here we took nodes+1 because we know that array's are starting from 0 not 1. so we have to take one more extra space.
    vector<vector<int>> graph_adj_list(nodes + 1);
    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        // x --> y

        graph_adj_list[x].push_back(y);
        indeg[y]++;
    }

    /*
                    0 --> 1 --> 2 --> 3

                  nodes = 4;
                  edges = 3;

                  topological order : 0 1 2 3

                  template i/p : 4 3 0 1 1 2 2 3
    */

    // topological ordering
    queue<int>
        q;
    for (auto i : indeg)
    {
        if (i == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto i : graph_adj_list[x])
        {
            indeg[i]--;
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return 0;
}