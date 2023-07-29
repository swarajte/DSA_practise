#include <bits/stdc++.h>
using namespace std;

// solution link : https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/3212178/Day-52-oror-Binary-Search-oror-Easiest-Beginner-Friendly-Sol

int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid % 2 == 1)
        {
            mid--;
        }
        if (nums[mid] != nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 2;
        }
    }
    return nums[left];
}

int main()
{

    return 0;
}