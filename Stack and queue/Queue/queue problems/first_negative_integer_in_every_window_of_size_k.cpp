#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n, int k)
{

    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i); // processing first window
        }
    }

    if (dq.size() != 0)
    {
        ans.push_back(arr[dq.front()]);
    } // storing ans for first window of size k
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front(); // removal of element out of window's size
        }

        if (arr[i] < 0)
        {
            dq.push_back(i); //  addition of new integer in our window
        }

        if (dq.size() != 0)
        {
            ans.push_back(arr[dq.front()]);
        }                   // storing ans for window of size k
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}
int main()
{
    vector<int> arr={-8,2,3,-6,10};
    int n=5;
    int k=2;
    vector<int> ans=solve(arr,n,k); 

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}