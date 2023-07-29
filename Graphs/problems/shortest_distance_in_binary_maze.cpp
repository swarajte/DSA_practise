#include <bits/stdc++.h>
using namespace std;

// question:https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze


// solution is basic bfs traversal with adjacnet i nodes in 4 direction find dist[destination row][destination col] while pushing in queue check if newr and newcl are destintion if yes then return that else after while loop completion return -1 



// for adjacent traversals
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// to check that a cell is within the grid
bool isValid(int nrow, int ncol, int n, int m)
{
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    queue<pair<int, pair<int, int>>> q;

    // source coordiantes
    int sx = source.first;
    int sy = source.second;
    dis[sx][sy] = 0;
    q.push({0, {sx, sy}});

    // destination coordinates
    int dx = destination.first;
    int dy = destination.second;

    while (!q.empty())
    {
        auto it = q.front();
        int dist = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();

        // finding the adjacent cells
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (isValid(nrow, ncol, n, m))
            {
                // check if the adjacent is a valid cell
                if (grid[nrow][ncol] == 1 and dist + 1 < dis[nrow][ncol])
                {
                    dis[nrow][ncol] = 1 + dist;

                    // the terminating condition
                    if (nrow == dx && ncol == dy)
                    {
                        return dis[nrow][ncol];
                    }

                    q.push({1 + dist, {nrow, ncol}});
                }
            }
        }
    }

    if (sx == dx && sy == dy)
    {
        return 0;
    }
    return -1;
}

int main()
{

    return 0;
}