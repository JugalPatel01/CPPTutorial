/*
   * graph representation using adjacency list :
    -> array of lists, where each a[i] is a list of nodes xᵢ that are reachable from i.
    -> eg. here a,b,c,d,e are vertices

       | a |-> b -> d -> e ->
       | b |-> c ->
       | c |-> d ->
       | d |-> a ->
       | e |->

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;

    // here we took nodes+1 because we know that array's are starting from 0 not 1. so we have to take one more extra space.
    vector<int> graph_adj_list[nodes + 1];
    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);
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

    cout << "adjacency list of the above graph is given by : " << endl;
    for (int i = 1; i < nodes + 1; i++)
    {
        cout << i << " -> ";
        for (int j : graph_adj_list[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}