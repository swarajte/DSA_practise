#include <bits/stdc++.h>
using namespace std;
bool IsSafe(int x, int y, int n, vector<vector<int>> matrix, vector<vector<int>> visited)
{
    if (x < 0 && x > n - 1 && y < 0 && y > n - 1 && visited[x][y] == 0 && matrix[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> matrix, vector<vector<int>> visited, int x, int y, int n, string output, vector<string> &ans)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(output);
        return;
    }

    // we have reached x,y
    visited[x][y] = 1;

    // Down checking
    int newx = x + 1;
    int newy = y;
    if (IsSafe(newx, newy, n, matrix, visited))
    {
        output.push_back('D');
        solve(matrix, visited, newx, newy, n, output, ans);
        output.pop_back();
    }

    // Up checking
    newx = x - 1;
    newy = y;
    if (IsSafe(newx, newy, n, matrix, visited))
    {
        output.push_back('U');
        solve(matrix, visited, newx, newy, n, output, ans);
        output.pop_back();
    }

    // left checking
    newx = x;
    newy = y - 1;
    if (IsSafe(newx, newy, n, matrix, visited))
    {
        output.push_back('L');
        solve(matrix, visited, newx, newy, n, output, ans);
        output.pop_back();
    }

    // right checking
    newx = x;
    newy = y + 1;
    if (IsSafe(newx, newy, n, matrix, visited))
    {
        output.push_back('R');
        solve(matrix, visited, newx, newy, n, output, ans);
        output.pop_back();
    }

    visited[x][y] = 0;
}
int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 0, 1},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 1}};

    int srcx = 0;
    int srcy = 0;
    int n = 4;
    vector<vector<int>> visited;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string output = "";
    vector<string> ans; 

    solve(matrix, visited, srcx, srcy, n, output, ans);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"{"<<ans[i]<<"}"<<endl;
    } 

    return 0;
}