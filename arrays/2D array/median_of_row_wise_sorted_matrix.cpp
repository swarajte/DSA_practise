#include <bits/stdc++.h>
using namespace std;

// solution : a median will have n/2 numbers less than itself if total number is n if count of numbers is greater than then we have to decrease search space by decreasing high high=mid-1 and if count is less than or equal to n/2 then we have to increase low=mid+1 and return low at the end
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int median(vector<vector<int>> &matrix, int m, int n)
{
    // Write your code here.
    int low = 1;
    int high = 1e9;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += countSmallerThanMid(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{

    return 0;
}