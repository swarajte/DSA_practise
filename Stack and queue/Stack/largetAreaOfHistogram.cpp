#include <bits/stdc++.h>
using namespace std;

vector<int> nextsmallerindex(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevsmallerindex(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextsmallerindex(heights, n);
    vector<int> prev(n);
    prev = prevsmallerindex(heights, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << "largest arae of rectangular histogram is " << largestRectangleArea(arr) << endl;
    // vector<int> next = nextsmallerindex(arr, arr.size());
    // vector<int> prev = prevsmallerindex(arr, arr.size());

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << next[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << prev[i] << " ";
    // }

    return 0;
}