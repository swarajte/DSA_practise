#include <bits/stdc++.h> 
using namespace std;
bool solutionPossible(vector<int> arr, int k,int mid){
    int cowCount=1;
    int lastpos=arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]-lastpos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastpos=arr[i];
        }
    }
    return false;
}
int aggresivecows(vector<int> a,int k){
    int s=0;
    int maxi=-1; 
    sort(a.begin(),a.end());
    for (int i = 0; i < a.size(); i++)
    {
        maxi=max(maxi,a[i]);
    }
    int e=maxi;
    int mid=(s+e)/2;
    int ans =0;
    while(s<=e){
        if(solutionPossible(a,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}
int main()
{
    vector<int> a={4,2,1,3,6};
    int k=2;

    int solution = aggresivecows(a,k);
    cout<<"ans is "<<solution;

    return 0;
}