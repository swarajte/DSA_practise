#include <bits/stdc++.h>
using namespace std;

// question : we have to rotate given matrix by 90degree
// approach 1 : observe relation between indices of input and output matrices and create 1 output matrix and update values accordingly
// t.c. :- O(n^2)   s.c.:- O(n^2)

// approach 2 : take transpose of matrix and then reverse each row
// t.c. :- O(n^2)   s.c.:- O(1)

void rotate_approach_1(vector<vector<int>> &matrix)
{
    // observing relation is : ans[i][j] = matrix[n - 1 - j][i];

    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = matrix[n - 1 - j][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}
void rotate_approach_2(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(matrix);
    cout << "*******************************************";
    cout << endl;
    rotate_approach_1(matrix);
    printMatrix(matrix);
    return 0;
}