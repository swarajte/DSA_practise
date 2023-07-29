#include <bits/stdc++.h>
using namespace std;

// dijkstra's algorithm using priority queue as min heap

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    dist[S] = 0; // making the dist of srcas 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // acting as min heap of pair<dist,node>

    pq.push({0, S}); // pushing source with dist as 0 and node as S

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // traversing adjacent nodes
        for (auto it : adj[node])
        {
            int edgeweight = it[1]; // in a adj it[1] is edgeweight
            int adjnode = it[0];    // in a adj it[0] is adjnode
            if (dis + edgeweight < dist[adjnode])
            {
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
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