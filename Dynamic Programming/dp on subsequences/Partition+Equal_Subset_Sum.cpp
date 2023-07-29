#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    int n = nums.size();
    int k = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    // initialising target==0 wala col
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][nums[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int tr = 1; tr <= k; tr++)
        {
            bool exclude = dp[ind - 1][tr];
            bool include = false;
            if (tr >= nums[ind])
            {
                include = dp[ind - 1][tr - nums[ind]];
            }
            dp[ind][tr] = include | exclude;
        }
    }

    return dp[n - 1][k];
}

int main()
{

    return 0;
}