#include <bits/stdc++.h>
using namespace std;

int solve_recur(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }

    // boundry conditions
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    // if coming from up then min cost=uska ka(i,j) cost + solve(i-1,j)   and left =i,j + solve ()
    int up = grid[i][j] + solve_recur(i - 1, j, grid);
    int left = grid[i][j] + solve_recur(i, j - 1, grid);

    return min(up, left);
}

int solve_memo(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        // base case 
        if(i==0 && j==0){
            return grid[0][0];
        }

        // boundry conditions
        if(i<0 || j<0){
            return 250;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //if coming from up then min cost=uska ka(i,j) cost + solve(i-1,j)   and left =i,j + solve ()
        int up=grid[i][j]+solve_memo(i-1,j,grid,dp);
        int left=grid[i][j]+solve_memo(i,j-1,grid,dp);

        return dp[i][j]=min(up,left);
    }
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // return solve_recur(n - 1, m - 1, grid);

    // memoisation
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return solve_memo(n-1,m-1,grid,dp);

    // tabulation
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                return grid[i][j];
            }
            else if(i<0 || j<0){
                return INT_MAX;
            }
            else{
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

int main()
{

    return 0;
}