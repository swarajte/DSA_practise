#include <bits/stdc++.h>
using namespace std;

bool DFS_traversal(int start, vector<int> adj[], vector<bool> &visi, vector<bool> &pathvisi, vector<bool> &check_safe_node)
{
    visi[start] = true;
    pathvisi[start] = true;
    check_safe_node[start] = false;

    // tarversing adjacent node for cycle detection
    for (auto i : adj[start])
    {
        if (!visi[i])
        { // if adjacent node not visited
            if (DFS_traversal(i, adj, visi, pathvisi, check_safe_node))
            {
                check_safe_node[start] = 0; // cycle detected therefore node is not a safe node and further no need to check
                return true;
            }
        }
        else if (pathvisi[i] == true)
        {
            check_safe_node[start] = 0; // cycle detected therefore node is not a safe node and further no need to check
            return true;
        }
    }

    // if reached here therefore no cycle detected
    check_safe_node[start] = 1;
    pathvisi[start] = 0;
    return false; // cycle not detected
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    vector<bool> visi(V, false);
    vector<bool> pathvisi(V, false);
    vector<bool> check_safe_node(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visi[i])
        {
            bool flag = DFS_traversal(i, adj, visi, pathvisi, check_safe_node);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check_safe_node[i])
        {
            ans.push_back(i);
        } // storing values of safe nodes in ans vector
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}