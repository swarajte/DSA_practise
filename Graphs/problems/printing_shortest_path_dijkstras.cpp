#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

    // preparing adj list;
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> dist(n + 1, 1e9); // for storing minimum dist from src
    dist[1] = 0;

    vector<int> parent(n + 1); // for storing parent of that minimum dist kidhar se aaya
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i; // making themselves as parent first
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // acting as min heap of pair<dist,node>

    pq.push({0, 1}); // pushing source with dist as 0 and node as S

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // traversing adjacent nodes
        for (auto it : adj[node])
        {
            int edgeweight = it.second; // in a adj it[1] is edgeweight
            int adjnode = it.first;     // in a adj it[0] is adjnode
            if (dis + edgeweight < dist[adjnode])
            {
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
                parent[adjnode] = node;
            }
        }
    }

    if (dist[n] == 1e9)
    {
        return {-1};
    }

    int node = n;
    vector<int> ans;
    while (parent[node] != node)
    { // untill it reaches src node
        ans.push_back(node);
        node = parent[node];
    }

    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}