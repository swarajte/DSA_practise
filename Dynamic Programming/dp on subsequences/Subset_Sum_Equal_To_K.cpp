#include <bits/stdc++.h> 
using namespace std;

bool solve_recur(int index,int target,vector<int> &arr){
    // if target is found
    if(target==0){
        return true;
    }

    // if recursion after recursion size reduces to 1 and if that single element is equal to target true else false
    if(index==0){
        if(arr[index]==target){
            return true;
        }
        else{
            return false;
        }
    }

    // two options 1)exclude arr[index] from reduces (index-1) subset or 2) include arr[index] in subset if include check if target > arr[index]
    bool exclude=solve_recur(index-1,target,arr);
    bool include=false;
    if(target>=arr[index]){
        include=solve_recur(index-1, target-arr[index],arr);
    }

    return include||exclude;
}
bool solve_memo(int index,int target,vector<int> &arr,vector<vector<int>> &dp){
    // if target is found
    if(target==0){
        return true;
    }

    // if recursion after recursion size reduces to 1 and if that single element is equal to target true else false
    if(index==0){
        if(arr[index]==target){
            return true;
        }
        else{
            return false;
        }
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    // two options 1)exclude arr[index] from reduces (index-1) subset or 2) include arr[index] in subset if include check if target > arr[index]
    bool exclude=solve_memo(index-1,target,arr,dp);
    bool include=false;
    if(target>=arr[index]){
        include=solve_memo(index-1, target-arr[index],arr,dp);
    }

    return dp[index][target]=include||exclude;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here
    // recursion approach:
    // return solve_recur(n-1, k,arr);

    //memoisation
    // vector<vector<int>> dp(n,vector<int> (k+1,-1));
    // return solve_memo(n-1,k,arr,dp);

    // TABULATION APPROACH
    vector<vector<bool>> dp(n,vector<bool> (k+1,0)); 

    // initialising target==0 wala col
    for(int i=0; i<n; i++){
        dp[i][0]=true;
    }

    dp[0][arr[0]]=true;
    for(int ind=1; ind<n; ind++){
        for(int tr=1; tr<=k; tr++){
                bool exclude=dp[ind-1][tr];
                bool include=false;
                if(tr>=arr[ind]){
                    include=dp[ind-1][tr-arr[ind]];
                }
                dp[ind][tr]=include | exclude;
            
        }
    }

    return dp[n-1][k];
}
int main()
{

    return 0;
}