#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // making adj list
    vector<int> adj[N];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // making distance vector and intialize by 1e9
    vector<int> dist(N, 1e9);
    dist[src] = 0;

    // make queue <int> for bfs traversal
    queue<int> q;
    q.push(src); // inserting src inside queue

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // traversing in adj of node
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
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