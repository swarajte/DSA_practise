#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base cases initiated for tabulation
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}


string print_LCSubstr(string X, string Y){
    int m = X.length();
    int n = Y.length();

        // tabulation
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int len[2][n+1];
    int currRow=0;
    int result=0;
    int end;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==0 || j==0){
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else
            {
                len[currRow][j]=0;
            }
        }
        currRow=1-currRow;

    }

    

    if(result==0){
        return "-1";
    }

    return X.substr(end-result+1,result);

}

int main()
{
    cout<<print_LCSubstr("leetco","leet");

    return 0;
}