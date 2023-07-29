#include <bits/stdc++.h>
using namespace std;

void printwave(vector<vector<int>> a, int row, int col)
{

    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < row; j++)
            {
                cout << a[j][i]<<" ";
            }
            cout << endl;
        }
        else
        {
            for (int j = row-1; j >= 0; j--)
            {
                cout<<a[j][i]<<" ";
            }
            cout<<endl;
        }
    }
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

    cout<<"*********************"<<endl;

    printwave(a,3,3);
    return 0;
}