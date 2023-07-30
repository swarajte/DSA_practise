#include <bits/stdc++.h>
using namespace std;

bool binarysearch(int arr[], int s, int e, int key)
{
    int mid = (s + e) / 2;

    if(s>e){
        return false;
    }
    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] > key)
    {
        return binarysearch(arr, s, e - 1, key);
    }
    else if (arr[mid] < key)
    {
        return binarysearch(arr, s + 1, e, key);
    }

    return false;
}
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int key = 4;
    int s = 0;
    int e = 4;
    if (binarysearch(arr, s, e, key))
    {
        cout << "found key" << endl;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}