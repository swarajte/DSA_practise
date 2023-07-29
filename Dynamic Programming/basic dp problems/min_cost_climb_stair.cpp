#include <bits/stdc++.h>
using namespace std;

// top down approach

int solve1(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return cost[n];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve1(cost, n - 1, dp), solve1(cost, n - 2, dp));
    return dp[n];
}

// bottom up approach

int solve2(vector<int> &cost, int n, vector<int> &dp)
{
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[n] = cost[n] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

// Space Optimisation approach

int solve3(vector<int> &cost, int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev2, prev1);
}
int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans1 = min(solve1(cost, n - 1, dp), solve1(cost, n - 2, dp));
    int ans2 = solve2(cost, n, dp);
    int ans3 = solve3(cost, n);
    cout << "top down ans           : " << ans1 << endl;
    cout << "bottom up ans          : " << ans2 << endl;
    cout << "space optimization ans : " << ans3 << endl;
    return 0;
}