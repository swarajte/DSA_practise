#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> shopinfo, int n, int s, int idx)
{
    if (idx >= shopinfo.size() && n == 0)
        return 0;
    if (idx >= shopinfo.size())
        return 1e9;
    int mini = 1e9;
    for (int j = 1; j <= n; j++)
    {
        int x = shopinfo[idx][1] * j + shopinfo[idx][2] + solve(shopinfo, n - j, s, idx + 1);
        mini = min(mini, x);
    }
    int nottake = solve(shopinfo, n, s, idx + 1);
    return min(mini, nottake);
}
int main()
{
    int n = 10;
    int s = 2;
    vector<vector<int>> shopinfo = {{5, 5, 50}, {1000, 10, 0}};
    int x = solve(shopinfo, n, s, 0);
    return 0;
}