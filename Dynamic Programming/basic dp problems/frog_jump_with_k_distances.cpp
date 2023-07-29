#include <bits/stdc++.h>
using namespace std;

int frog_jump_basic_recursion(int n, int k, vector<int> height)
{
    if (n == 0)
    {
        return 0;
    }

    int min_steps = INT_MAX;
    for (int i = 0; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jumps = frog_jump_basic_recursion(n - 1, k, height) + abs(height[n] - height[n - i]);
            min_steps = min(min_steps, jumps);
        }
    }
    // int l=frog_jump_basic_recursion(n-1,height)+abs(height[n]-height[n-1]);
    // int r=INT_MAX;
    // if(n>1)
    // {
    //     r=frog_jump_basic_recursion(n-2,height)+abs(height[n]-height[n-2]);
    // }

    // return min(l,r);
    return min_steps;
}

int frog_jump_memo(int n, int k, vector<int> height)
{
    vector<int> dp(n, -1);
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // int l=frog_jump_memo(n-1,height)+abs(height[n]-height[n-1]);
    // int r=INT_MAX;
    // if(n>1)
    //     r=frog_jump_memo(n-2,height)+abs(height[n]-height[n-2]);

    int min_steps = INT_MAX;
    for (int i = 0; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jumps = frog_jump_memo(n - 1, k, height) + abs(height[n] - height[n - i]);
            min_steps = min(min_steps, jumps);
        }
    }

    // return dp[n]=min(l,r);
    return dp[n] = min_steps;
}

int frog_jump_tabular(int n,int k, vector<int> height)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    int min_steps = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        // int l=dp[i-1]+abs(height[n]-height[n-1]);
        // int r=INT_MAX;
        // if(i>1)
        //     r=dp[i-2]+abs(height[n]-height[n-2]);

        // dp[i]=min(l,r);

        for (int j = 0; j <= k; j++)
        {
            if (n - j >= 0)
            {
                int jumps = frog_jump_tabular(i-j, k, height) + abs(height[n] - height[i - j]);
                min_steps = min(min_steps, jumps);
            }
        } 
        dp[i]=min_steps;
    }
    return dp[n];
}

int frog_jump_space_optimis(int n, vector<int> height)
{

    int prev1 = 0;
    int prev2 = 0;
    int curri = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = prev1 + abs(height[n] - height[n - 1]);
        int r = INT_MAX;
        if (i > 1)
            r = prev2 + abs(height[n] - height[n - 2]);

        prev2 = prev1;
        prev1 = curri;
        curri = min(l, r);
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    cout << "enter elements of height" << endl;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        height.push_back(t);
    }

    int ans0 = frog_jump_basic_recursion(n - 1, 2, height);
    int ans1 = frog_jump_memo(n - 1, 2, height);
    int ans2 = frog_jump_tabular(n - 1,2, height);
    int ans3 = frog_jump_space_optimis(n - 1, height);

    cout << "recursion ans           : " << ans0 << endl;
    cout << "top down ans           : " << ans1 << endl;
    // cout << "bottom up ans          : " << ans2 << endl;
    // cout << "space optimization ans : " << ans3 << endl;

    return 0;
}