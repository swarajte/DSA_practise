#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    BubbleSort(arr, n - 1);
}

int main()
{
    int arr[7] = {
        4,
        2,
        6,
        9,
        3,
        6,
        7,
    };
    int n = 7;
    BubbleSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}