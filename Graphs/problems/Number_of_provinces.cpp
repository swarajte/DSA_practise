#include <bits/stdc++.h>
using namespace std;

void dfs(int ind, vector<int> adjls[], vector<bool> &visi)
{
    visi[ind] = true;

    for (auto it : adjls[ind])
    {
        if (!visi[it])
        {
            dfs(it, adjls, visi);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    // converting adj matrix into adj list
    int n = isConnected.size();
    vector<int> adjls[n];
    adjls[0] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }

    vector<bool> visi(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visi[i])
        {
            count++;
            dfs(i, adjls, visi);
        }
    }

    return count;
}

int main()
{
    
    return 0;
}