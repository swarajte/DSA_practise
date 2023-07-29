#include <bits/stdc++.h> 

long long f(vector<int> nums,int start,int end){
    
    long long prev2=nums[start];
    long long prev1=0;
    long long curri;
    for(int i=start+1; i<=end; i++){
        int pick=nums[i];
        if(i>start+1){
            pick=pick+prev2;
        }
        int notpick=0+prev1;
        curri=max(pick,notpick);
        prev2=prev1;
        prev1=curri;

    }

    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }
    long long ans1=f(valueInHouse,0,n-2);
    long long ans2=f(valueInHouse,1,n-1);
    return max(ans1,ans2);
}