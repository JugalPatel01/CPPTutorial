/*

    * bipartite graph
    -> it is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either
       connects a vertex from U to V or a vertex from V to U.
    -> The graph doesn't contain any odd-length cycles
    -> the graph is 2 colorable


        |------------------------------|
      | 1 |-----------| 2 |------|     |
      | 4 |-----------| 3 |      |     |
      | 5 |-----------| 6 |------|-----|
        |________________________|

    Nodes : 6
    groups : [1 4 5] [2 3 6]
    edges : [12 16 43 56 52 ]


    Approach :
    -> first, we find bfs tree for this graph.
    -> then we check whether there is a cross edges present in that bfs tree.
    -> cross edges : It is an edge that connects two nodes such that they do not have any ancestor and a descendant
                     relationship between them.
                     In simple meaning both the nodes are on the same level in the bfs tree and there is no edge present in the bfs tree between them but there is an edge between them in original graph.

                                        0
                                       / \
                                      1   2
                                      |   |
                                      3---4
                                        ^
                                        |------- cross edge
    -> If there is no cross edge in bfs tree of graph then it is a bipartite graph.
    -> NOTE : graph doesn't contain a cycle of odd length iff a graph is bipartite.

    Approach 2:
    -> Traverse the graph
    -> if the current node is of red color, paint its neighbours as blue.

    if we are able to color the graph successfully, then the graph is bipartite.

*/

#include <iostream>
#include <vector>
using namespace std;

void do_coloring(vector<vector<int>> const &adj_list, vector<int> &color, int src, int current, bool &bipartite)
{
    if (color[src] == 0)
    {
        color[src] = current;
        if (current == 1)
        {
            current = 2;
        }
        else
        {
            current = 1;
        }
        for (auto i : adj_list[src])
        {
            do_coloring(adj_list, color, i, current, bipartite);
        }
    }
    else if (color[src] != current)
    {
        bipartite = false;
        return;
    }
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

      (red) 0 -- 1 (blue)
            |    |
     (blue) 2 -- 3 (red)

        nodes : 4
        edges : 4 [01 13 23 02]
        o/p : bipartite graph

        template input : 4 5 0 1 1 3 2 3 0 2 0 3

    */

    vector<int> color(nodes, 0); // 1 for red ; 2 for blue
    int current = 1;
    bool bipartite = true;

    for (int i = 0; i < nodes; i++)
    {
        if (color[i] == 0)
        {
            do_coloring(graph_adj_list, color, i, current, bipartite);
        }
    }

    if (bipartite)
    {
        cout << "given graph is bipartite graph ." << endl;
    }
    else
    {
        cout << "given graph is not bipartite graph ." << endl;
    }

    return 0;
}