#include <bits/stdc++.h>
using namespace std;

bool detect_cycle_in_directed(int node, vector<int> adj[], vector<bool> &visi, vector<bool> &path_visi)
{
    visi[node] = 1;      // marking node is visited
    path_visi[node] = 1; // marking path is visited

    // traversing for neighbouring nodes of our node
    for (auto i : adj[node])
    {
        //
        if (!visi[i])
        {
            if (detect_cycle_in_directed(i, adj, visi, path_visi))
            {
                return true;
            }
        }

        else if (path_visi[i] == true)
        { // how is pathvisi[i] where i is child already true  therefore in this path this node has been already touched (cycle detected)
            return true;
        }
    }

    path_visi[node] = 0; // if cycle is not detected in this path then make pathvisi[node] ==0
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visi(V, 0);
    vector<bool> path_visi(V, 0);

    // for disconnected components
    for (int i = 0; i < V; i++)
    {
        if (detect_cycle_in_directed(i, adj, visi, path_visi))
        {
            return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}