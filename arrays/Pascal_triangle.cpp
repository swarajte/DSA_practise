#include <bits/stdc++.h>
using namespace std;

// question:- we have to create pascal triangle which is each elemnt is made by sum of upper ke two elements except first three and we are given with Num Rows and number of rows in our ans   

// if numRows=5
//              1
//             1  1
//            1  2  1 
//           1  3  3  1
//         1  4  6  4  1



vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i)
    {
        ans.push_back(vector<int>(i + 1, 1));
    }

    for (int i = 2; i < numRows; ++i)
    {
        for (int j = 1; j < ans[i].size() - 1; ++j)
        {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }

    return ans;
}

int main()
{

    return 0;
}