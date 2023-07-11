/*

    * finding count and size of the connected component in the graph using dfs.

*/

#include <iostream>
#include <vector>
using namespace std;

int get_compo(vector<vector<int>> &adj_list, vector<bool> &visited, int src)
{
    int ans = 0;
    if (visited[src])
    {
        return 0;
    }
    else
    {
        visited[src] = true;
        ans++;
        for (auto i : adj_list[src])
        {
            if (!visited[i])
                ans += get_compo(adj_list, visited, i);
        }
    }
    return ans;
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
    vector<int> compo_size;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            compo_size.push_back(get_compo(graph_adj_list, visited, i));
        }
    }

    cout << "size of each component is : ";
    for (auto i : compo_size)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}