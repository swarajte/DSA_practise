#include <bits/stdc++.h>
using namespace std;

int firstocc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}
int lastocc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}
int main()
{   
    int arr[8]={1,2,2,2,3,4,5,6};
    cout<<"position of first occ is "<<firstocc(arr,8,2)<<" and position of last occ is "<<lastocc(arr,8,2)<<endl;
    cout<<"number of occurences of 2 is "<<lastocc(arr,8,2)-firstocc(arr,8,2)+1;
    return 0;
}