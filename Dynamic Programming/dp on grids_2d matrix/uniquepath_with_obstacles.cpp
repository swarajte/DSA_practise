#include <bits/stdc++.h>
using namespace std;

int mod=(int)(1e+7);
int solve_recursive(int i, int j, vector<vector<int>> &mat)
{

    // ensuring that blocked wala box gives no of paths as 0
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }

    // base case when (0,0 ) is reached only 1 way possible
    if (i == 0 && j == 0)
    {
        return 1;
    }

    // boundry conditions for row and col
    if (i < 0 || j < 0)
    {
        return 0;
    }

    // fori,j no of ways= sum of ways from i-1,j and ways from i,j-1
    int downaya = solve_recursive(i - 1, j, mat);

    int rightaya = solve_recursive(i, j - 1, mat);

    return downaya + rightaya;
}

int solve_memo(int i, int j, vector<vector<int>> &mat,vector<vector<int>> &dp)
{

    // ensuring that blocked wala box gives no of paths as 0
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }

    // base case when (0,0 ) is reached only 1 way possible
    if (i == 0 && j == 0)
    {
        return 1;
    }

    // boundry conditions for row and col
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if(dp[i][j]!=-1){
            return dp[i][j];
        }

    // fori,j no of ways= sum of ways from i-1,j and ways from i,j-1
    int downaya = solve_memo(i - 1, j, mat,dp);

    int rightaya = solve_memo(i, j - 1, mat,dp);

    return dp[i][j]=downaya+rightaya;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    // return solve_recursive(n - 1, m - 1, mat);

    // memoisation
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return solve_memo(n-1,m-1,mat,dp); 

    
    //tabulation method 
    // vector<vector<int>> dp(n,vector<int> (m,0)); 
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
    //         if(mat[i][j]==-1){
    //             dp[i][j]=0;
    //         }
	// 		else if(i==0 && j==0){
	// 			dp[0][0]=1;
	// 		}
	// 		else{
	// 			int downaya=0;
	// 			int rightaya=0;
	// 			if(i>0){
	// 				downaya=dp[i-1][j];
	// 			}
	// 			if(j>0){
	// 				rightaya=dp[i][j-1];
	// 			}

	// 			dp[i][j]=downaya+rightaya;
				
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];

    //space optimisation
    //tabulation method 
    vector<int> prev(m,0); 
	for(int i=0; i<n; i++){
        vector<int> curr(m,0);
		for(int j=0; j<m; j++){
            if(mat[i][j]==-1){
                curr[j]=0;
            }
			else if(i==0 && j==0){
				curr[j]=1;
			}
			else{
				int downaya=0;
				int rightaya=0;
				if(i>0){
					downaya=prev[j];
				}
				if(j>0){
					rightaya=curr[j-1];
				}

				curr[j]=(downaya+rightaya)%mod;
				
			}
            prev=curr;
		}
	}
	return prev[n-1];
}
int main()
{

    return 0;
}