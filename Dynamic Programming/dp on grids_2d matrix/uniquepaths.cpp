#include <bits/stdc++.h>
using namespace std;

int solve_recursive(int i, int j)
{
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
    int downaya = solve_recursive(i - 1, j);
    int rightaya = solve_recursive(i, j - 1);
    return downaya + rightaya;
}

int solve_dp_memo(int i,int j,vector<vector<int>> &dp){
        // base case when (0,0 ) is reached only 1 way possible
	    if(i==0 && j==0){
	    	return 1;
	    }

        // boundry conditions for row and col
        if(i<0 || j<0 ){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // fori,j no of ways= sum of ways from i-1,j and ways from i,j-1
        int downaya=solve_dp_memo(i-1,j,dp);
        int rightaya=solve_dp_memo(i,j-1,dp);
        return dp[i][j]=downaya+rightaya;
    }
int uniquePaths(int m, int n)
{
    // return solve_recursive(m - 1, n - 1);

    // vector<vector<int>> dp(m,vector<int> (n,-1));
    //     return solve_dp_memo(m-1,n-1,dp);

    //tabulation method 
    // vector<vector<int>> dp(m,vector<int> (n,-1)); 
	// for(int i=0; i<m; i++){
	// 	for(int j=0; j<n; j++){
	// 		if(i==0 && j==0){
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


    // space optimisation
    vector<int> prev(n,0); 
	for(int i=0; i<m; i++){
		vector<int> curr(n,0);
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
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

				curr[j]=downaya+rightaya;
				
			}
		}
		prev=curr;
	}
	return prev[n-1];
}

int main()
{

    return 0;
}