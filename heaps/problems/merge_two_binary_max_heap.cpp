#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[leftchild] > arr[largest])
    {

        largest = leftchild;
    }

    else if (rightchild < n && arr[rightchild] > arr[largest])
    {

        largest = rightchild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest);
    }
    
}


vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here

    vector<int> ans;

    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    int k = ans.size();
    for (int i = (k / 2) - 1; i >= 0; i--)
    {
        heapify(ans,i);
    }
    return ans;
}

int main()
{

    return 0;
}