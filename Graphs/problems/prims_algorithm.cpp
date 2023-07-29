#include <bits/stdc++.h>
using namespace std;

// given is weighted undirected graph
//     question : find sum of edgeweight of minimum spanning tree formed from above graph int
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<bool> visi(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int egwt = pq.top().first;

        if (visi[node])
        {
            continue;
        }

        visi[node] = true;
        sum += egwt;

        // traversing adjacent nodes
        for (auto i : adj[node])
        {
            if (!visi[i[0]])
            {
                pq.push({i[1], i[0]});
            }
        }
    }

    return sum;
}
int main()
{

    return 0;
}