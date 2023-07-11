/*

    Q : There are N friends numbered from 0 to N-1. we have to choose 2 person such that they are not realted to each other.
        we are given information in the form of M pair(x,y) i.e. there is an link between friend x and y.
        find out the number of ways in which 2 person from different groups can be choosen.

    i/p : 11 friends (0...10)   relationship : 0->1->2->3  4->5->6 7->8->9->10
    o/p : 48

*/

#include <iostream>
#include <vector>
using namespace std;

int find_compo(vector<vector<int>> &adj_list, vector<bool> &visited, int src)
{
    int ans = 0;
    if (visited[src])
    {
        return ans;
    }
    if (!visited[src])
    {
        visited[src] = 1;
        ans = 1;
        for (auto i : adj_list[src])
        {
            if (!visited[i])
                ans += find_compo(adj_list, visited, i);
        }
    }
    return ans;
}

int main()
{
    int nodes, edges;
    cout << "enter no. friends(nodes) : ";
    cin >> nodes;
    cout << "enter no. relationships(edges) : ";
    cin >> edges;

    vector<vector<int>> graph_adj_list(nodes);
    cout << "enter relationships(edges) : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);
    }

    /*

        0->1->2->3   4->5->6    7->8->9->10
        o/p : total 3 groups so total permutations are 4*3*4 = 48

        template input : 11 8 0 1 1 2 2 3 4 5 5 6 7 8 8 9 9 10


    */
    vector<bool> visited(nodes, 0);
    vector<int> components;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            components.push_back(find_compo(graph_adj_list, visited, i));
        }
    }

    int ans = 1;
    for (auto i : components)
    {
        if (i)
        {
            ans *= i;
        }
    }
    cout << "total pairs from different group is : " << ans << endl;

    return 0;
}