#include <bits/stdc++.h>
using namespace std;

// two approaches
// 1) by recusrsion passing (int start,int end ) as (0,n-1) in starting ,two cases
//     a)if(str[start]==str[end]) then both two are part of largest palindromic subsequence therefore return 2+solve(start++ and end--)
//     b) if str[start]!=str[end]  either longest palindromic subsequence will be by start++ or end-- find both and return max that is return max(solve(start++,end),solve(start,end--))
//     base case: if (i==j) reached on same element then return 1 as it will be part of longest palindromic case
//     if(i>j)  no longer a palindrome return 0

// 2) by finding longest common subsequence of str and reverse(str) will give us longest palindromic subsequence

// approach 1:
int solve_appr1(int start, int end, string &str)
{
    // base case
    if (start == end)
    {
        return 1;
    }
    if (start > end)
    {
        return 0;
    }

    // trying all possible stuff

    if (str[start] == str[end])
    {
        start++;
        end--;
        return 2 + solve_appr1(start, end, str);
    }

    return max(solve_appr1(start + 1, end, str), solve_appr1(start, end - 1, str));
}

// aproach 2:
string reverse(string &str)
{
    int s = 0;
    int e = str.size() - 1;

    while (s < e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str;
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    // return solve_recur(text1.size() - 1, text2.size() - 1, text1, text2);

    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return solve_memo(n-1,m-1,text1,text2,dp);

    // tabulation
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubseq(string str)
{
// aproach 1:
    // return solve_appr1(0, str.size() - 1, str);

// aproach 2:
    return longestCommonSubsequence(str,reverse(str));
}
int main()
{

    return 0;
}