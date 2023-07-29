#include <bits/stdc++.h>
using namespace std;

bool checkBipartite_DFS(int start, int colo, vector<int> adj[], vector<int> &color)
{

    color[start] = colo;

    for (auto i : adj[start])
    {
        if (color[i] == -1)
        {
            // check for non colored adjacent node for false of bipartite
            if (checkBipartite_DFS(i, !colo, adj, color) == false)
            { // if one of the for iterartions gives us false no need to check for other iterartions so return false
                return false;
            }
        }
        else if (color[i] == color[start])
        {
            return false;
        }
    }

    return true;
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
            if (checkBipartite_DFS(i, 0, adj, color) == false)
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