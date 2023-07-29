#include <bits/stdc++.h>
using namespace std;

bool cycle_detected_by_dfs(int node, int parent, vector<int> adj[], vector<bool> &visi)
{

    // mark node as visited
    visi[node] = 1;

    // check for neighbouring nodes
    for (auto i : adj[node])
    {
        // if nodes is visited no need to visit it is parent......if not visited then go to that node and
        if (!visi[i])
        {
            // if this child of node hase cycle in future no need of checking other child
            if (cycle_detected_by_dfs(i, node, adj, visi))
            {
                return true;
            }
        }

        else if (visi[i] && i != parent)
        { // neighbour is visited but not parent (cycle detected)
            return true;
        }
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visi(V, 0);

    // for disconnected components
    for (int i = 0; i < V; i++)
    {
        if (!visi[i])
        {
            if (cycle_detected_by_dfs(i, -1, adj, visi))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}