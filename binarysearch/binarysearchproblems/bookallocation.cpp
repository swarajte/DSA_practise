#include <bits/stdc++.h> 
using namespace std; 

bool isPossibleSol(vector<int> arr,int mid,int m){
    int pagesum=0;
    int studentcount=1;
    for (int i = 0; i < arr.size(); i++)
    {
        if(pagesum<=mid){
            pagesum=+arr[i];
        }
        else{
            studentcount++;
            if(studentcount>m  || arr[i]>mid){
                return false;
            }
            // pagesum=0;
            pagesum =arr[i];
        }
    }
    return true;
}
int bookallocation(vector<int> arr,int m){
    int s=0;
    int sum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum=+arr[i];
    }
    int e=sum;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(isPossibleSol(arr,mid,m)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;

}
int main()
{
    int m=2;
    int n=4;
    vector<int> a;
    for (int i = 1; i <=n; i++)
    {
        int t=10*i;
        a.push_back(t); 
    } 

    int ans = bookallocation(a,m);
    cout<<" ans is "<<ans;
    
    return 0;
}