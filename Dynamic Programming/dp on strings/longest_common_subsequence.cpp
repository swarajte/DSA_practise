#include <bits/stdc++.h>
using namespace std;

int solve_recur(int ind1, int ind2, string &text1, string &text2)
{
    // base case
    //  atleast one of the string is completed nothing to compare return 0
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    // if character on ind1 and ind2 is matching
    if (text1[ind1] == text2[ind2])
    {
        return 1 + solve_recur(ind1 - 1, ind2 - 1, text1, text2);
    }

    int not_match = 0 + max(solve_recur(ind1 - 1, ind2, text1, text2), solve_recur(ind1, ind2 - 1, text1, text2));

    return not_match;
}

int solve_memo(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    // base case
    //  atleast one of the string is completed nothing to compare return 0
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }

    // if character on ind1 and ind2 is matching
    if (text1[ind1] == text2[ind2])
    {
        return dp[ind1][ind2] = 1 + solve_memo(ind1 - 1, ind2 - 1, text1, text2, dp);
    }

    int not_match = 0 + max(solve_memo(ind1 - 1, ind2, text1, text2, dp), solve_memo(ind1, ind2 - 1, text1, text2, dp));

    return dp[ind1][ind2] = not_match;
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    // return solve_recur(text1.size() - 1, text2.size() - 1, text1, text2);

    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return solve_memo(n-1,m-1,text1,text2,dp);

    // tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base cases initiated for tabulation
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{

    return 0;
}