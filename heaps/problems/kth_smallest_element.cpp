#include <bits/stdc++.h>
using namespace std;
// space complexity = O(k) priority queue
int findKthsmallest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] < pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    vector<int> a={1,2,3,4,5,6,7};
    int k;
    cout<<"enter k:";
    cin>>k;
    cout<<"kth smallest element is: "<<findKthsmallest(a,k);
    return 0;
}