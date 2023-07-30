#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> output, int n)
{
    int r = row;
    int c = col;

    while (r >= 0 && c >= 0)
    {
        if (output[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c--;
    }

    r = row;
    c = col;
    while (c >= 0)
    {
        if (output[r][c] == 'Q')
        {
            return false;
        }
        c--;
    }

    r = row;
    c = col;
    while (r < n && c >= 0)
    {
        if (output[r][c] == 'Q')
        {
            return false;
        }
        c--;
        r++;
    }

    return true;
}
void solve(vector<vector<string>> &ans, vector<string> output, int n, int col)
{
    if (col == n)
    {
        ans.push_back(output);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, output, n))
        {
            output[row][col] = 'Q';
            solve(ans, output, n, col + 1);
            output[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> output(n, string(n, '.'));
    int col = 0;
    solve(ans, output, n, col);
    return ans;
}

int main()
{

    return 0;
}