#include <bits/stdc++.h> 
using namespace std;

void print_LCS(string text1, string text2){
    int n = text1.size();
    int m = text2.size();

        // tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base cases initiated for tabulation
    // for (int j = 0; j <= m; j++)
    // {
    //     dp[0][j] = 0;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    

    string ans="";
    
    int i=n; 
    int j=m;

    while(i>0 && j>0){
        if(text1[i-1]==text2[j-2]){
            // we have to add in ans atring and update index as index--
            ans=text1[i-1]+ans;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            // not matching and dp[i-1][j]>dp[i][j-2]
            i--;
        }
        else{
            j--;
        }
    }

    cout<<ans;

}
int main()
{
    string s1="abcde";
    string s2="bdgek";

    // string ans="1";
    print_LCS(s1,s2);
    // cout<<ans;
    return 0;
}