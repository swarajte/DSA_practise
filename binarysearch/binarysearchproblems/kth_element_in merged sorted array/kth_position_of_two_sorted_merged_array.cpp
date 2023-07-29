#include <bits/stdc++.h>
using namespace std;

// solution : approach is like used to find median of twp sorted array, we have to basically pick some elements of first array and some of second array and find if they are picked correctly and if we pick x elements from array1 then we have to pick k-x from array 2 and if correctly picked return max(array1 ke max picked in left part,array2 ka max picked in left part )

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }
    int s = max(0, k - m);
    int e = min(k, n);

    while (s <= e)
    {
        int par1 = (s + e) / 2;
        int par2 = k - par1;
        int l1 = par1 == 0 ? INT_MIN : arr1[par1 - 1];
        int l2 = par2 == 0 ? INT_MIN : arr2[par2 - 1];
        int r1 = par1 == n ? INT_MAX : arr1[par1];
        int r2 = par2 == m ? INT_MAX : arr2[par2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            e = par1 - 1;
        }
        else
        {
            s = par1 + 1;
        }
    }
    return 1;
}

int main()
{

    return 0;
}