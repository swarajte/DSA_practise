#include <bits/stdc++.h>
using namespace std;

// question: https://leetcode.com/problems/trapping-rain-water/

// solution: make two vector for storing left max height and right max height and then water stored on given ith block will be min(left[i],right[i])-A[i] and then add for all blocks

int trap(vector<int> &height)
{
    int n = height.size();
    // create left and right vector for max blocks
    vector<int> left(n,-1);
    vector<int> right(n,-1);

    vector<int> st;
    // st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.back() <= height[i])
        {
            st.pop_back();
        }

        if (!st.empty())
        {
            left[i] = st.back();
            if (height[i] > st.back())
            {
                st.push_back(height[i]);
            }
        }
        else
        {
            st.push_back(height[i]);
        }
    }

    st.clear();

    for (int i = n-1; i>=0 ; i--)
    {
        while (!st.empty() && st.back() <= height[i])
        {
            st.pop_back();
        }

        if (!st.empty())
        {
            right[i] = st.back();
            if (height[i] > st.back())
            {
                st.push_back(height[i]);
            }
        }
        else
        {
            st.push_back(height[i]);
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(left[i]!=-1 && right[i]!=-1){
            ans+=min(left[i],right[i])-height[i];
        }
    }
    return ans;
}

int main()
{

    return 0;
}