#include <bits/stdc++.h>
using namespace std;

void DFS_traversal(int node, vector<pair<int, int>> adj[], vector<bool> &visi, stack<int> &st)
{
    visi[node] = true;

    // traversing node's adjacent nodes
    for (auto i : adj[node])
    {
        if (!visi[i.first])
        {
            DFS_traversal(i.first, adj, visi, st);
        }
    }

    st.push(node);
    return;
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // making adjacency lsit from matrix with weight
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // finding the topt sort ka stack
    stack<int> st;
    vector<bool> visi(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!visi[i])
        {
            DFS_traversal(i, adj, visi, st);
        }
    }

    // creating minimum distance ka array
    vector<int> dist(N, 1e9);
    dist[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto i : adj[node])
        {
            int v = i.first;
            int wt = i.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }
    return dist;
}

int main()
{

    return 0;
}