#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{
    int row = 3;
    int col = 4;

    int s = 0;
    int e = row * col - 1;
    int mid = s + ((e - s) / 2);

    while (s <= e)
    {
        int element = matrix[mid / col][mid % col];

        if (target == element)
        {
            return true;
        }

        else if (target > element)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }

        mid = s + ((e - s) / 2);
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix= {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 3, 60}};

    int target = 16;

    if(searchMatrix(matrix,target)){
        cout<<" element found ";
    }
    else{
        cout<<"element not found ";
    }
    return 0;
}