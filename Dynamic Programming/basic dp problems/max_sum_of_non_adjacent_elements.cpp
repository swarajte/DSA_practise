#include <bits/stdc++.h> 
using namespace std;

int f_recursive(int index,vector<int> nums){
    if(index==0){
        return nums[0];
    }
    if(index<0){
        return 0;
    }

    int pick=nums[index]+f_recursive(index-2,nums);
    int notpick=0+f_recursive(index-1,nums);

    return max(pick,notpick);
}

int f_memoi(int index,vector<int> nums,vector<int> dp){ 
    
    if(index==0){
        return nums[0];
    }
    if(index<0){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    int pick=nums[index]+f_memoi(index-2,nums,dp);
    int notpick=0+f_memoi(index-1,nums,dp);

    return dp[index]=max(pick,notpick);
}

int f_tabular(int n,vector<int> nums,vector<int> dp){
    dp[0]=nums[0];
    int neg=0;

    for(int i=1; i<n; i++){
        int pick=nums[i];
        if(i>1){
            pick=pick+dp[i-2];
        }
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }

    return dp[n-1];
}

int f_spaceopti(int n,vector<int> nums){
    int prev2=nums[0];
    int prev1=0;
    int curri;
    for(int i=1; i<n; i++){
        int pick=nums[i];
        if(i>1){
            pick=pick+prev2;
        }
        int notpick=0+prev1;
        curri=max(pick,notpick);
        prev2=prev1;
        prev1=curri;

    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int index=nums.size();
    int n=nums.size();
    // return f_recursive(index,nums);
    vector<int> dp(nums.size(),-1); 
    return f_memoi(n-1,nums,dp);
}

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        nums.push_back(t);   
    }
    int ans=maximumNonAdjacentSum(nums);
}