#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
bool solve_recur(int i, int j, string &p, string &s)
{
    // base case
    // both string exhausted therefore comparison done so true
    if (i < 0 && j < 0)
    {
        return true;
    }

    // s string is exhausted but p is not so comparison not completed so false
    if (i < 0 && j >= 0)
    {
        return false;
    }

    // if p is exhausted but s is not exhausted then it will be true if s is all *'s and false if not
    if (j < 0 && i >= 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (p[ii] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (p[i] == s[j] || p[i] == '?')
    {
        return solve_recur(i - 1, j - 1, p, s);
    }

    else if (p[i] == '*')
    {
        bool star_is_empty = solve_recur(i - 1, j, p, s);
        bool star_is_not_empty = solve_recur(i, j - 1, p, s);
        return star_is_empty || star_is_not_empty;
    }
    return false; // if reached here return false
}

bool solve_memo(int i,int j,string &p,string &s,vector<vector<int>> &dp){
        // base case
        // both string exhausted therefore comparison done so true
        if(i<0 && j<0){
            return true;
        }
        
        // s string is exhausted but p is not so comparison not completed so false
        if(i<0 && j>=0){
            return false;   
        }
        
        // if p is exhausted but s is not exhausted then it will be true if s is all *'s and false if not 
        if(j<0 && i>=0){
            for(int ii=0; ii<=i; ii++){
                if(p [ii]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        
        if(dp[i][j]!=-1){
           return dp[i][j];
        }

        if(p[i]==s[j] || p[i]=='?'){
            return dp[i][j]=solve_memo(i-1,j-1,p,s,dp);
        }
        
        else if(p[i]=='*'){
            bool star_is_empty=solve_memo(i-1,j,p,s,dp);
            bool star_is_not_empty=solve_memo(i,j-1,p,s,dp);
            return dp[i][j]=star_is_empty||star_is_not_empty;
        }
        return dp[i][j]=false;  // if reached here return false
    }

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();

    // return solve_recur(n - 1, m - 1, pattern, text);

    vector<vector<int>> dp(n,vector<int> (m,-1));
   return solve_memo(n-1,m-1,pattern,text,dp);
}
int main()
{

    return 0;
}