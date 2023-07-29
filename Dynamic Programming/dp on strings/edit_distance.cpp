#include <bits/stdc++.h>
using namespace std;

// recursive using zero - based indexing
int solve_zero_based(int i, int j, string &word1, string &word2)
{
    // base case
    if (j < 0)
    {
        // if word2 is exhausted i.e we have to convert word1 in an empty string
        //  delete all elements i.e i+1 of word1
        return i + 1;
    }

    if (i < 0)
    {
        // we have to convert empty word1 in to non empty word2 so insert j+1 th items in word1
        return j + 1;
    }

    if (word1[i] == word2[j])
    {
        return 0 + solve_zero_based(i - 1, j - 1, word1, word2); // no need to perform any operation just make i-- and j-- we are going good
    }

    // if word1[i]!=word2[j]   we have three operations 1)insert 2)delete 3)replace and we have to take minimum of it therefore
    int insert_op = 1 + solve_zero_based(i, j - 1, word1, word2);      // we have inserted the element no matchinf with word2[j] in word1 so j--
    int delete_op = 1 + solve_zero_based(i - 1, j, word1, word2);      // just remove that word1[i] from word1 and i--
    int replace_op = 1 + solve_zero_based(i - 1, j - 1, word1, word2); // replace word1[i] with word2[j] and make i-- and j--

    return min(insert_op, min(delete_op, replace_op));
}

// recursive 1-based + memoization

int solve_recur(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    // base case
    if (j == 0)
    {
        // if word2 is exhausted i.e we have to convert word1 in an empty string
        //  delete all elements i.e i+1 of word1
        return i;
    }

    if (i == 0)
    {
        // we have to convert empty word1 in to non empty word2 so insert j+1 th items in word1
        return j;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (word1[i - 1] == word2[j - 1])
    {
        return 0 + solve_recur(i - 1, j - 1, word1, word2, dp); // no need to perform any operation just make i-- and j-- we are going good
    }

    // if word1[i]!=word2[j]   we have three operations 1)insert 2)delete 3)replace and we have to take minimum of it therefore
    int insert_op = 1 + solve_recur(i, j - 1, word1, word2, dp);      // we have inserted the element no matchinf with word2[j] in word1 so j--
    int delete_op = 1 + solve_recur(i - 1, j, word1, word2, dp);      // just remove that word1[i] from word1 and i--
    int replace_op = 1 + solve_recur(i - 1, j - 1, word1, word2, dp); // replace word1[i] with word2[j] and make i-- and j--

    return dp[i][j] = min(insert_op, min(delete_op, replace_op));
}



int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // return solve_zero_based(n-1,m-1,word1,word2);

    // memoization
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return solve_recur(n,m,word1,word2,dp);

    
    // tabulation method
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insert_op = 1 + dp[i][j - 1];
                int delete_op = 1 + dp[i - 1][j];
                int replace_op = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(insert_op, min(delete_op, replace_op));
            }
        }
    }

    return dp[n][m];
}
int main()
{

    return 0;
}