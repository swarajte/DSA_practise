#include <bits/stdc++.h> 
using namespace std;

int minCost(vector<int> arr, int n) {
        // Your code here
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        int ans=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            
            int sum=a+b;
            ans+=sum;
            pq.push(sum);
            
        }
        return ans;
    }
int main()
{
    vector<int> ropes={4, 3, 2, 6};
    int n=ropes.size();
    cout<<"minimum cost = "<<minCost(ropes,n);

    return 0;
}