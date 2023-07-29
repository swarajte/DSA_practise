#include <bits/stdc++.h>
using namespace std;

int pivotIndex(int nums[],int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    return s;
}

int main()
{
    int arr[5] = {8,10,17,1,3};
    int ans=pivotIndex(arr,5);
    cout<<"index of pivot element is "<<ans;

    return 0;
}