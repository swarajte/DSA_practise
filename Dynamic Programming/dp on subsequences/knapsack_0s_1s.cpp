#include <bits/stdc++.h>
using namespace std;

int solve_recurr(int index, int w, vector<int> weight, vector<int> value)
{
    // base case
    if (index == 0)
    {
        if (weight[index] <= w)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }

    // not pick ka call
    int notpick = 0 + solve_recurr(index - 1, w, weight, value);

    // pick ka call
    int pick = -1e5;
    if (weight[index] <= w)
    {
        pick = value[index] + solve_recurr(index - 1, w - weight[index], weight, value);
    }

    return max(pick, notpick);
}

int solve_memo(int index,int w,vector<int> weight, vector<int> value,vector<vector<int>> &dp){
	//base case 
	if(index==0){
        if (weight[index] <= w) {
        return value[index];
		}
		else{
			return 0;
		}
    }

	if(dp[index][w]!=-1){
		return dp[index][w];
	}
	// not pick ka call
	int notpick=0+solve_memo(index-1, w, weight, value,dp);

	//pick ka call
	int pick=-1e5;
	if(weight[index]<=w){
		pick=value[index]+solve_memo(index-1, w-weight[index],weight,value,dp);
	}

	return dp[index][w]=max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    //recursion approach
    // return solve_recurr(n - 1, maxWeight, weight, value);
    
    // memoisation approach
    // vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	// return solve_memo(n-1,maxWeight,weight,value,dp);

    // tabulation approach
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));

	//initialisation for base case
	for(int w=weight[0]; w<=maxWeight; w++){
		dp[0][w]=value[0];
	}
    for(int i=1; i<n; i++){
        for(int w=0; w<=maxWeight; w++){
            int notpick=0+dp[i-1][w];
            int pick=INT_MIN;
            if(weight[i]<=w){
                pick=value[i]+dp[i-1][w-weight[i]];
            }
            dp[i][w]=max(pick,notpick);        
        }
    }

    return dp[n-1][maxWeight];
}

int main()
{

    return 0;
}