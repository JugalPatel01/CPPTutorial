/*

    * Graph Theory

    ## components of a graph :
    1) nodes : these are the states or vertex.
    2) edges : Links between states in a graph.
        there are two types of edges :
        a) undirected graphs - (two way edges)
        b) directed graphs   - (one way edges)

    ## we can represent graph with 3 ways:
    1) adjacency matrix
    2) adjacency list
    3) incidence matrix

    1) adjacency matrix :
    -> 2D array, where a[i][j] = 1 if there is an edge from i to j else a[i][j] = 0.
    -> eg.  cols and rows are vertices

               a b c d
          a  | 0 0 0 1 |
          b  | 0 0 0 1 |
          c  | 0 0 0 1 |
          d  | 1 1 1 0 |

    2) adjacency list :
    -> array of lists, where each a[i] is a list of nodes xᵢ that are reachable from i.
    -> eg. here a,b,c,d,e are vertices

       | a |-> b -> d -> e ->
       | b |-> c ->
       | c |-> d ->
       | d |-> a ->
       | e |->

    3) incidence matrix
    -> 2D array, where a[i][j] = 1 if j edge contain i vertex else 0.
    -> eg. here rows are vertices & cols are edges

               w x y z
          a  | 0 1 0 0 |
          b  | 1 1 1 0 |
          c  | 0 0 1 1 |
          d  | 1 0 0 1 |

    ## graph terminologies
    -> Adjacent Vertices : Adjacnet vertices are two vertices with a direct edge connecting them.
    -> degree of vertex : There are total two types of degrees
            1) indegree : no. of edges incoming to the vertex
            2) outdegree : no. of edges outgoing to the vertex
    -> Path between two vertices : all vertices which come in the path of two given vertices is called their path.
    -> connected graph : Each node has path from every other node
    -> disconnected graph : each node doesn't have path from every other node.
    -> connected componenets : each connected graph in a disconnected graph is called a connected component.
    -> cycles in a graph : path from vertex to the same vertex in a graph is known as cycle.


    ## graph based on cycles :
    1) cyclic graph : a graph which contain cycles are called cyclic graph
    2) acyclic graph : a graph which doesn't contain any cycle in it called acyclic graph.
    NOTE : connected acyclic graph is called tree.
    properties of trees:
    -> no. of edges is n-1.(if there are total n vertices in graph).
    -> No cycle present.
    -> each node has path from every other vertex.

    ## directed Acyclic graph (DAG)
    -> it has directed edges
    -> it is acyclic i.e. no cycles are present.

    ## complete graph
    -> A graph in which each vertex is connected to every other vertex by a direct edge.
    -> number of edges in a complete graph = ⁿC₂ = (n*(n-1)/2)

    ##  weighted graph
    -> weighted edges - values are associated with edges.
    -> weighted nodes - Values are associated with nodes.
    -> A graph with weighted edges is called weighted graph.



 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes, edges;
    cout << "Enter no. of nodes : ";
    cin >> nodes;
    cout << "Enter no. of edges : ";
    cin >> edges;

    // here we took nodes+1 size of vector because we will start from index 1 and as we know that array's first index is 0.
    vector<vector<int>> graph_adjm(nodes + 1, vector<int>(nodes + 1, 0));

    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        graph_adjm[x][y] = 1;
        graph_adjm[y][x] = 1;
    }

    /*
                                1 -- 3
                               /   /
                              2 -- 7
                            / | \ /
                           4  5  6

                        vertices : 7
                        edges : 8 [12 13 24 25 26 27 37 67]

                           i/p for terminal for whole graph : 7 8 1 2 1 3 2 4 2 5 2 6 2 7 3 7 6 7

     */

    cout << "adjacency matrix of above graph is given by : " << endl;
    for (auto i : graph_adjm)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}