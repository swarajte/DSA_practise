#include <bits/stdc++.h>
using namespace std;

bool IsPresent(int arr[][3], int target, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // for (int i = 0; i < 3; i++)
    // {                                                // taking input in 2d array
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {                                                    // this will display the matrix row wise
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {                                                     // this will display the matrix column wise
    //         cout<<matrix[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int target;
    // cout << "enter the target to be found";
    // cin >> target;
    // if (IsPresent(matrix, target, 3, 3))
    // {                                        // finding element in 2d array
    //     cout << "element found";
    // }
    // else
    // {
    //     cout << "not found ";
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     int rsum=0;
    //     for (int j = 0; j < 3; j++)
    //     {                                            // this will give us row wise sum of all rows in the 2d arrau
    //         rsum=rsum+matrix[i][j];
    //     }
    //     cout<<rsum<<endl;
    // }

    // int maxi=INT_MIN;
    // int index=-1;
    // for (int i = 0; i < 3; i++)
    // {                                                  // this give us largest row wise sum with it's row number
    //     int rowsum = 0;
        
    //     for (int j = 0; j < 3; j++)
    //     {
    //         rowsum=rowsum+matrix[i][j];
    //     }
    //     if(rowsum>maxi){
    //         maxi=rowsum;
    //         index=i;
    //     }
    // }
    // cout<<"largest row wise sum of matrix is "<<maxi<<" with row number "<<index+1;
    return 0;
}