#include <bits/stdc++.h> 
using namespace std;

int lengthOfLongestSubarray(int arr[],int n)
{
    unordered_map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0) ans=i+1;
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            else ans=max(ans,i-mp[sum]);
        }
        return ans;
}

int main()
{

    return 0;
}