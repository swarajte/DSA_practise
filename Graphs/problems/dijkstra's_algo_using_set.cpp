#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    dist[S] = 0; // making the dist of srcas 0

    set<pair<int, int>> st; // acting as set of pair<dist,node>

    st.insert({0, S}); // pushing source with dist as 0 and node as S

    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        st.erase(it);

        // traversing adjacent nodes
        for (auto it : adj[node])
        {
            int edgeweight = it[1]; // in a adj it[1] is edgeweight
            int adjnode = it[0];    // in a adj it[0] is adjnode
            if (dis + edgeweight < dist[adjnode])
            {
                if (dist[adjnode] != 1e9)
                {
                    st.erase({dist[adjnode], adjnode});
                }

                dist[adjnode] = dis + edgeweight;
                st.insert({dist[adjnode], adjnode});
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