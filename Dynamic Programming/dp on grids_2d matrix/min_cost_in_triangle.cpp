#include <bits/stdc++.h>
using namespace std;

int solve_recur(int i, int j, vector<vector<int>> &triangle)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    int left = solve_recur(i + 1, j, triangle);
    int right = solve_recur(i + 1, j + 1, triangle);

    return triangle[i][j] + min(left, right);
}

int solve_memo(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = solve_memo(i + 1, j, triangle, dp);
    int right = solve_memo(i + 1, j + 1, triangle, dp);

    return dp[i][j] = triangle[i][j] + min(left, right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    //recursion
    // return solve_recur(0,0,triangle);

    vector<vector<int>> dp(n, vector<int>(n, -1));
    //memoisation
    // return solve(0,0,triangle,dp);

    // tabulation
    // for(int i=n-1; i>=0; i--){
    //     for(int j=triangle[i].size()-1; j>=0; j--){
    //         if(i==n-1){
    //             dp[i][j]=triangle[i][j];
    //         }
    //         else{
    //             int left=triangle[i][j]+dp[i+1][j];
    //             int right=triangle[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(left,right);
    //         }
    //     }
    // }

    // return dp[0][0];
}
int main()
{

    return 0;
}