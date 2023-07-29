#include <bits/stdc++.h>
using namespace std;

// question :- we are array of 0s,1s,2s we have to sort without using stl and O(1) space complexity
// approach 1: use any sorting algo
// approach 2: count no of 0s,1s,2s in array by O(n) and then make array modification accordingly
// approach 3: Dutch National Flag Algorithm

// here `0′, `1′ and `2′. The array is divided into four sections:
// arr[1] to arr[low – 1]
// arr[low] to arr[mid – 1]
// arr[mid] to arr[high – 1]
// arr[high] to arr[n]
// initially low=0 ,mid=0 and high=n-1

// If the ith element is 0 then swap the element to the low range. low++ and mid++
// Similarly, if the element is 1 then keep it as it is. mid++
// If the element is 2 then swap it with an element in high range. mid++ and high--

void sortColors_approach2(vector<int> &nums)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cnt0++;
        }
        else if (nums[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }

    for (int i = 0; i <= cnt0 - 1; i++)
    {
        nums[i] = 0;
    }
    for (int i = cnt0; i <= cnt0 + cnt1 - 1; i++)
    {
        nums[i] = 1;
    }
    for (int i = cnt0 + cnt1; i <= cnt0 + cnt1 + cnt2 - 1; i++)
    {
        nums[i] = 2;
    }
}

void Dutch_National_Flag_Algorithm(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
            mid++;
        }
    }

}


int main()
{
    vector<int> a = {2, 0, 2, 1, 1, 0};
    // sortColors_approach2(a);
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    Dutch_National_Flag_Algorithm(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}