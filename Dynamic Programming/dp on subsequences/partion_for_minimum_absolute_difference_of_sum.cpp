#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	    //finding total sum for range in dp [n][sum]
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }

        int k=sum;
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

        // check for s1 existence from range s1=0 to sum/2 (as beyond sum/2 it will not give absolute difference minimum)  and then upadate the minimum absolute possible difference
        int min_diff=1e8;
        for(int s1=0; s1<=sum/2; s1++){
            if(dp[n-1][s1]){
                min_diff=min(min_diff,abs(s1-(sum-s1)));
            }
        }

        return min_diff;
}

int main()
{

    return 0;
}