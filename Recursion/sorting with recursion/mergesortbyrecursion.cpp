#include <bits/stdc++.h>
using namespace std;

void mergetwosortedarrays(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int length1 = mid - s + 1;
    int length2 = e - mid;

    int *arr1 = new int[length1];
    int *arr2 = new int[length2];

    int firstindex = s;
    int secondindex = mid + 1;

    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[firstindex++];
    }
    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[secondindex++];
    }

    firstindex = 0;
    secondindex = 0;
    int resultindex = s;

    while (firstindex < length1 && secondindex < length2)
    {
        if (arr1[firstindex] < arr2[secondindex])
        {
            arr[resultindex++] = arr1[firstindex++];
        }
        else
        {
            arr[resultindex++] = arr2[secondindex++];
        }
    }

    while (firstindex < length1)
    {
        arr[resultindex++] = arr1[firstindex++];
    }
    while (secondindex < length2)
    {
        arr[resultindex++] = arr2[secondindex++];
    }  

    delete []arr1;
    delete []arr2;
}

void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
   
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    mergetwosortedarrays(arr, s, e);
}
int main()
{
    int arr[10] = {4, 6, 9, 3, 1, 8, 7, 11, 0, 5};
    int n = 10;
    int s = 0;
    int e = n - 1;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<endl;
    mergesort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}