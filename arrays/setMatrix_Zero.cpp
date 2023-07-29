#include <bits/stdc++.h>
using namespace std;

// question is to make all rows and column of elements zeroes whose value is zero 
// 1) t.c =o(m*n*(m+m)) s.c.=O(1)  make all rows of 0 wala element -9999 then all col of 0 wala element -9999 then make all -9999 to 0 
void setZeroes_approach1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    if (matrix[i][k] != 0)
                    {
                        matrix[i][k] = -9999;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[k][j] != 0)
                    {
                        matrix[k][j] = -9999;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -9999)
            {
                matrix[i][j] = 0;
            }
        }
    }
}



int main()
{

    return 0;
}