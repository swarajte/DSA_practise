#include <bits/stdc++.h> 
using namespace std;



double squarerootbybs(double x){
    int s=1;
    int e=x;
    int mid=(s+e)/2;
    int ans=0;
    while(s<=e){
        if(mid*mid==x){
            return mid;
        }

        else if(mid*mid>x){                 // time complexity log(n) as we are using binary search
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

double precisionofsquareroot(double x,int n,double sol){
    double ans=sol;
    double factor=1;
    for(int i=0; i<n; i++){
        factor=factor/10;
        for(double j=ans; j*j<=x; j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main()
{
    double x;
    cout<<"enter number "<<endl;
    cin>>x;
    double sol=squarerootbybs(x);
    cout<<sol<<endl;
    cout<<precisionofsquareroot(x,3,sol);
    return 0;
}