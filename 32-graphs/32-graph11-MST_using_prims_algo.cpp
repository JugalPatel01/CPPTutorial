/*

    * MST using prims algorithm

    -> this approach is based on greedy appraoch

    approach :
    -> select any vertex.
    -> then select edge with minimum weight between tree and nontree vertex.
    -> add that edge in tree and add remaining edges from that node in min-heap.
    -> continue above process till every vertex will cover.

    eg.

                                 (0)
                             10 / | \ 15
                               / 5|  \
                             (1)--|--(2)
                                2 | / 40
                                  |/
                                 (3)

                                 graph G
        steps :
        1) take random vertex 0. add it in spanning tree and add all it's edges in min-heap.
        2) now remove one edge from min-heap which is 03(2) and add it in the spanning tree.
        3) now we have 2 edges 01(10) and 02(15) in the heap.
        4) we are on the vertex 3 so now we add edge 32(40) and pop edge from min-heap 01(10).
        5) now we are on 1 and we added all the connected edges in min-heap.
        6) now we have to pop edge from min-heap which is 12(5) and add it in the MST.
        7) so we have covered all the vertices. so our minimum spanning tree is.

                                 (0)
                             10 / |
                               / 5|
                             (1)--|--(2)
                                2 |
                                  |
                                 (3)

        * time complexity : O(edges * log (edges))      // for poping out from the min_heap

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct vector_cmp
{

    bool operator()(vector<int> &a, vector<int> &b)
    {
        // for swapping (it's not like sort)
        return a[2] > b[2];
    }
};

void MST_using_prims(int source, vector<bool> &visited, vector<vector<pair<int, int>>> &adj_list, vector<vector<int>> &mst, int &cost)
{
    priority_queue<vector<int>, vector<vector<int>>, vector_cmp> min_heap;
    visited[source] = 1;
    // pushes all the edges connected with source vertex
    for (auto i : adj_list[source])
    {
        min_heap.push({source, i.first, i.second});
    }

    while (!min_heap.empty())
    {
        // popint out lowest weighted edge
        vector<int> x = min_heap.top();
        min_heap.pop();
        // if next node is not visited then visit that node and add that edge in spanning tree otherwise just continue to traversing.
        if (!visited[x[1]])
        {
            visited[x[1]] = 1;
            cout << x[0] << " -> " << x[1] << endl;
            mst.push_back(x);
            cost += x[2];
            // add all the edges connected to the second node of edge.
            for (auto i : adj_list[x[1]])
            {
                min_heap.push({x[1], i.first, i.second});
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

    // for checking whether node is visited or not
    vector<bool> visited(nodes, 0);
    // final ans.
    vector<vector<int>> mst;

    cout << "enter edges & it's weight : ";
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

    int cost = 0;
    MST_using_prims(0, visited, graph_adj_list, mst, cost);

    cout << "cost of MST is : " << cost << endl;

    return 0;
}
