#include <bits/stdc++.h>
using namespace std;

bool linearsearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linearsearch(arr + 1, size - 1, key);
    }
}
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int key = 1;
    if (linearsearch(arr, 5,key))
    {
        cout << "found key" << endl;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}