#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int currSum = 0, maximumSumSubarray = INT_MIN;
    for (auto num : nums)
    {
        currSum += num;
        if (currSum > maximumSumSubarray)
        {
            maximumSumSubarray = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maximumSumSubarray;
}

int main()
{
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};


    cout<<"maximum sum possible for continuos sub array is : "<<maxSubArray(a);

    return 0;
}