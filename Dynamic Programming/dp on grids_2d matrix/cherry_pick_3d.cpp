#include <bits/stdc++.h>
using namespace std;

// PROBLEM STATEMENT
// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots

int solve_recur(int i, int j1, int j2, vector<vector<int>> &grid)
{
    // boundry condition
    if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
    {
        return -1e8;
    }

    // base case (starting from first row so reaching last row will be the base case)
    if (i == grid.size() - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }

    // finding maximum from all 9 combos possible of
    //  (i)j1-1 j1 j1+1 j2-1 j2 j2+1
    int maxi = -1e8;
    for (int J1 = j1 - 1; J1 <= j1 + 1; J1++)
    {
        for (int J2 = j2 - 1; J2 <= j2 + 1; J2++)
        {
            int value = 0;
            if (j1 == j2)
            {
                value = grid[i][j1] + solve_recur(i + 1, J1, J2, grid);
            }
            else
            {
                value = grid[i][j1] + grid[i][j2] + solve_recur(i + 1, J1, J2, grid);
            }
            maxi = max(maxi, value);
        }
    }

    return maxi;
}

int solve_memo(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        //boundry condition
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
            return -1e8;
        }

        //base case (starting from first row so reaching last row will be the base case)
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }


        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        //finding maximum from all 9 combos possible of
        // (i)j1-1 j1 j1+1 j2-1 j2 j2+1
        int maxi=-1e8;
        for(int J1=j1-1; J1<=j1+1; J1++){
            for(int J2=j2-1; J2<=j2+1; J2++){
                int value=0;
                if(j1==j2){
                    value=grid[i][j1]+solve_memo(i+1,J1,J2,grid,dp);
                }
                else{
                    value=grid[i][j1]+grid[i][j2]+solve_memo(i+1,J1,J2,grid,dp);
                }
                maxi=max(maxi,value);
            }
        }

        return dp[i][j1][j2]=maxi;
    }
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    //recursion approach
    // return solve_recur(0, 0, m - 1, grid);

    // memoisation approach
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
    // return solve_memo(0,0,m-1,grid,dp);

    // tabulation approach:
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));

    // 1st step : initialising last row 

    for(int j1=0; j1<m; j1++){
        for(int j2=0; j2<m; j2++){
            if(j1==j2){
                dp[n-1][j1][j2]=grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    // step 2: processing for n rows from n-2 to 0
    for(int i=n-2; i>=0; i--){
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                int maxi=-1e8;
                for(int J1=j1-1; J1<=j1+1; J1++){
                    for(int J2=j2-1; J2<=j2+1; J2++){
                        int value=0;
                        if(j1==j2){
                        value=grid[i][j1] + dp[i+1][J1][J2];
                        }
                        else{
                        value=grid[i][j1]+grid[i][j2]+dp[i+1][J1][J2];
                    }
                    maxi=max(maxi,value);
                    }
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }

    return dp[0][0][m-1];
}
int main()
{

    return 0;
}