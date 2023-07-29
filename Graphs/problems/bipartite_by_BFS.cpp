#include <bits/stdc++.h>
using namespace std;

bool checkBipartite_bfs(int start, vector<int> adj[], vector<int> &color)
{
    color[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // processing for adjacent nodes
        for (auto i : adj[node])
        {
            if (color[i] == -1)
            { // adjacent node is not colored so color it as opposite of node ans also push it in queue
                color[i] = !color[node];
                q.push(i);
            } // pehle se coloured hai to kuch nahi krna but us adjacent ka color same hai to vo bipartite nhi hai
            else if (color[i] == color[node])
            {
                return false;
            }
        }

        return true;
    }
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V, -1); // creating color vector just like visi

    // for disconnected components
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (checkBipartite_bfs(i, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    return 0;
}