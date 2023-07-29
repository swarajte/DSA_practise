#include <bits/stdc++.h>
using namespace std;

void DFS_traversal(int node, vector<int> adj[], vector<bool> &visi, stack<int> &st)
{
    visi[node] = true;

    // traversing node's adjacent nodes
    for (auto i : adj[node])
    {
        if (!visi[i])
        {
            DFS_traversal(i, adj, visi, st);
        }
    }

    st.push(node);
    return;
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{

    vector<int> ans;
    stack<int> st;

    vector<bool> visi(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visi[i])
        {
            DFS_traversal(i, adj, visi, st);
        }
    }

    while (st.size() != 0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{

    return 0;
}