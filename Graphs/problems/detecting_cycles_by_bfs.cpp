#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph.
bool detect_using_bfs(int src, vector<int> adj[], vector<bool> &visi)
{
    visi[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        // traversing for neighnouring child as well as parent nodes of node
        for (auto i : adj[node])
        {
            if (!visi[i])
            { // if i=parent of node then it will be already visited no need
                visi[i] = 1;
                q.push({i, node});
            }
            else if (visi[i] && i != parent)
            { // if neighbouring node is visited but it is not parent then it has been traversed earlier (cycle detected)
                return true;
            }
        }
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visi(V, 0);

    // for disconnected components
    for (int i = 0; i < V; i++)
    {
        if (!visi[i])
        {
            if (detect_using_bfs(i, adj, visi))
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