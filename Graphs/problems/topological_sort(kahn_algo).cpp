#include <bits/stdc++.h>
using namespace std;

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> topo;

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    { // creating indegree vector having no of incoming edges for each node
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // find node having indegree ==0(it is a acyclic directed graph so there always will be someone with indegree==0)
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i); // pushing element with indegree zero as it will first element in topo vector
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node); // pushing element in our ans vector topo

        // deleting node from indegree vector
        for (auto i : adj[node])
        {
            indegree[i]--; // kind of deleting the incoming edge of node ke adjacent nodes
            if (indegree[i] == 0)
            {
                q.push(i); // pushing again element whose indegree will be zero
            }
        }
    }

    return topo;
}

int main()
{

    return 0;
}