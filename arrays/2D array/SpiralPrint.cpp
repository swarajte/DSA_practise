#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();
    int total = row * col;

    int startrow = 0;
    int endrow = row - 1;
    int startcol = 0;
    int endcol = col - 1;

    int count = 0;
    while (count < total)
    {

        // printing first row and then updating first row
        for (int i = startcol; count < total && i <= endcol; i++)
        {
            ans.push_back(matrix[startrow][i]);
            count++;
        }
        startrow++;

        // printing last col and then updating last col
        for (int i = startrow; count < total && i <= endrow; i++)
        {
            ans.push_back(matrix[i][endcol]);
            count++;
        }
        endcol--;

        // printing last row and then updating last row
        for (int i = endcol; count < total && i >= startcol; i--)
        {
            ans.push_back(matrix[endrow][i]);
            count++;
        }
        endrow--;

        // printing first col and then updating first col
        for (int i = endrow; count < total && i >= startrow; i--)
        {
            ans.push_back(matrix[i][startcol]);
            count++;
        }
        startcol++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> a={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> ans=spiralOrder(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}