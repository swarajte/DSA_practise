#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> arr, int n, int m)
{
    sort(arr.begin(), arr.end());
    int MinDiff = INT_MAX;
    for (int i = 0; i + m-1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < MinDiff)
        {
            MinDiff = diff;
        }
    }
    return MinDiff;
}
int main()
{

    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    int n = a.size();
    cout << findMinDiff(a, n, m);
    return 0;
}