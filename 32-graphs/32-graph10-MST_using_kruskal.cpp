/*

    * Minimum spanning tree (using krushkals' algorithm )

    # what is spanning tree?
    -> for undirected and connected graph G(V,E), a spanning tree of the graph G is a tree that spans G(that is, it includes
       every vertex of G ) and is a subgraph of G(every edge in the tree belongs to G).
    NOTE 1) : there can be a many spanning tree for one graph.
    NOTE 2) : If there are total N vertices in the graph then there are total N-1 edges in the spanning tree.

    # what is cost of spanning tree?
    -> the cost of the spanning tree is the sum of the weights of all the edges in the tree.

    Now,
    # what is minimum spanning tree?
    -> Minimum spanning tree is the spanning tree where the cost is minimum amont all the spanning trees.
    NOTE : There also can be many minimum spanning tree.



           (0)             (4)
         5/   \ 6       10/   \7
         /     \   5     /     \
        (1)   (2)------(5)    (6)
         9\   /2        1\    /1
           \ /            \  /
           (3)            (7)

                graph G


    Krushkal's algorithm :
    1. sort the edges in increasing order of their weights.
    2. Iterate in the sorted edges,
        if inclusion of i'th edge leads to a cycle, then skip, this edge.
        else add it into MST.

    sorted edges for above graph is :
     { 1(6,8), 1(7,8), 2(3,4), 5(3,6), 5(1,2), 6(1,3), 7(5,7), 9(2,4) ,10(5,6)}

    -> add edges one by one and check for whether that including that edge make cycle or not.
    -> we get { 1(6,8), 1(7,8), 2(3,4), 5(3,6), 5(1,2), 6(1,3), 7(5,7) }
    so, here we covered all the nodes and there is no cycle now if we insert 9(2,4) then it forms a cycle.

     Now MST of above graph G is :

           (0)             (4)
         5/   \ 6             \7
         /     \   5           \
        (1)   (2)------(5)    (6)
              /2        1\    /1
             /            \  /
           (3)            (7)

    cost of MST is = 5 + 6 + 5 + 2 + 1 + 1 + 7 = 27

    Time-complexity : O(Edges * log (nodes))
                    because of sorting takes O(edges*log(edges))
                    and we know in complete graph there is max edges = (nodes)*(nodes-1) = O((nodes)²)
                    so, O(edges*2*log(nodes)) = O(edges*log(edges))

    space-complexity : O(Edges + Nodes) = O(Edges)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void make_set(vector<int> &parent, vector<int> &size_set, int x)
{
    parent[x] = x;
    size_set[x] = 1;
}

int find_set(vector<int> &parent, int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find_set(parent, parent[x]);
}

void union_set(vector<int> &parent, vector<int> &size_set, int a, int b)
{
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b)
    {
        if (a < b)
        {
            swap(a, b);
        }
        parent[b] = a;
        size_set[a] += b;
    }
}

bool weight_cmp(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])
    {
        return true;
    }
    else
    {
        return false;
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
    vector<vector<int>> edges_of_graph;

    // for checking cycle we take parent and size_of_set vector.
    vector<int> parent(nodes);
    vector<int> size_of_set(nodes);

    for (int i = 0; i < nodes; i++)
    {
        make_set(parent, size_of_set, i);
    }

    cout << "enter edges & it's weight : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y, w;
        cout << "edges = ";
        cin >> x >> y;
        cout << "weight = ";
        cin >> w;
        edges_of_graph.push_back({x, y, w});

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);
    }

    /*

        i/p :
                             (0)             (4)
                           5/   \ 6       10/   \7
                           /     \   5     /     \
                          (1)   (2)------(5)    (6)
                           9\   /2        1\    /1
                             \ /            \  /
                             (3)            (7)

                                  graph G
            total cost : 27

            nodes : 8
            edges : 9
            template input : 8 9 0 1 5 0 2 6 1 3 9 2 3 2 2 5 5 4 5 10 4 6 7 5 7 1 6 7 1

    */

    // here we sort all the edges according their weights
    sort(edges_of_graph.begin(), edges_of_graph.end(), weight_cmp);

    int total_cost = 0;
    vector<vector<int>> mst;
    cout << "edges in the spanning trees are : " << endl;

    // adding edges one by one in the mst.
    for (auto i : edges_of_graph)
    {
        int x = i[0];
        int y = i[1];
        int w = i[2];
        // if cycle detects then continue
        if (find_set(parent, x) == find_set(parent, y))
        {
            continue;
        }
        // otherwise make the disjoint-set.
        else
        {
            cout << x << " -> " << y << endl;
            mst.push_back(i);
            union_set(parent, size_of_set, x, y);
            total_cost += w;
        }
    }

    cout << "total cost for making minimum spanning tree is : " << total_cost << endl;

    return 0;
}