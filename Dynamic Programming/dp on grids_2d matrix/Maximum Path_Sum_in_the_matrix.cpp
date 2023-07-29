#include <bits/stdc++.h>
using namespace std;

// strt from any col in 0th row and end in any col in last row find maximum sum
int solve_recur(int i, int j, vector<vector<int>> &matrix)
{
    // boundry condition
    if (j < 0 || j >= matrix[0].size())
    {
        return -1e9;
    }

    // base case
    if (i == 0)
    {
        return matrix[i][j];
    }

    int leftdiag = solve_recur(i - 1, j - 1, matrix);
    int rightdiag = solve_recur(i - 1, j + 1, matrix);
    int down = solve_recur(i - 1, j, matrix);

    return matrix[i][j] + max(down, max(leftdiag, rightdiag));
}

int solve_memo(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // boundry condition
    if (j < 0 || j >= matrix[0].size())
    {
        return -1e9;
    }

    // base case
    if (i == 0)
    {
        return matrix[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int leftdiag = solve_memo(i - 1, j - 1, matrix, dp);
    int rightdiag = solve_memo(i - 1, j + 1, matrix, dp);
    int down = solve_memo(i - 1, j, matrix, dp);

    return dp[i][j] = matrix[i][j] + max(down, max(leftdiag, rightdiag));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int maxi = -1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    // recursion wala solution
    // for(int j=m-1; j>=0; j--){
    //     maxi=max(maxi,solve_recur(n-1,j,matrix));
    // }

    // memoisation wala approach
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // for(int j=m-1; j>=0; j--){
    //     maxi=max(maxi,solve_memo(n-1,j,matrix,dp));
    // }

    // tabulation wala approach

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                dp[i][j] = matrix[i][j];
            } else {
                int ldiag = matrix[i][j] + dp[i - 1][j];
                int rdiag = matrix[i][j] + dp[i - 1][j];
                int down = dp[i - 1][j];
                if (j - 1 >= 0) {
                    ldiag = max(ldiag, matrix[i][j] + dp[i - 1][j - 1]);
                }
                if (j + 1 < m) {
                    rdiag = max(rdiag, matrix[i][j] + dp[i - 1][j + 1]);
                }
                dp[i][j] = max(down, max(ldiag, rdiag));
            }
            if (i == n - 1) {
                maxi = max(maxi, dp[i][j]);
            }
        }
    }

    return maxi;
}

int main()
{

    return 0;
}