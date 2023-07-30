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

int maximum_area(vector<vector<int>> M, int n, int m)
{
    int area = largestRectangleArea(M[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        int newarea = largestRectangleArea(M[i]);
        area = max(area, newarea);
    }

    return area;
}
int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> M = {{0, 1, 1, 0}, 
                             {1, 1, 1, 1}, 
                             {1, 1, 1, 1}, 
                             {1, 1, 0, 0}
                            };
    cout << "largest area is : " << maximum_area(M, n, m);

    return 0;
}