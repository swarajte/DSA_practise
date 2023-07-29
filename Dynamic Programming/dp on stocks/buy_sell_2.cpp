#include <bits/stdc++.h>
using namespace std;

// problem statement: You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve

// intution : if we buy a stock we have to sell it inorder to buy another stock
// so at any given day (excluding 0th day) we have 2 choices to buy or to sell if we have buyed on previous day we will sell and vice versa ....if we are selling we arev eventually adding in profit ans if we buy we are eventually substarcting from profit so
// we have to consider one int prev_condition to signify if we have buyed previously or sold and int i starting from 0th day and it will have prev_condition = 0 as free to buy (0 to but previously sold and vice versa)

int solve_recur(int i, int prev_condititon, vector<int> &prices)
{
    if (i == prices.size())
    {
        return 0;
    }

    // if we have sold previously so buy i.e if prev_condition=0
    int profit = 0;
    if (prev_condititon == 0)
    {
        // 2 choice to buy on ith day or to buy after ith day some other day after i i+1
        profit = max((-prices[i] + solve_recur(i + 1, 1, prices)), 0 + solve_recur(i + 1, 0, prices));
    }
    else
    {
        profit = max((prices[i] + solve_recur(i + 1, 0, prices)), (0 + solve_recur(i + 1, 1, prices)));
    }
    return profit;
}
int maxProfit(vector<int> &prices)
{
    return solve_recur(0, 0, prices);
}
int solve_memo(int i, int prev_condition, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size())
    {
        return 0;
    }

    if (dp[i][prev_condition] != -1)
    {
        return dp[i][prev_condition];
    }

    // if we have sold previously so buy i.e if prev_condition=0
    int profit = 0;
    if (prev_condition == 0)
    {
        // 2 choice to buy on ith day or to buy after ith day some other day after i i+1
        profit = max((-prices[i] + solve_memo(i + 1, 1, prices, dp)), 0 + solve_memo(i + 1, 0, prices, dp));
    }
    else
    {
        profit = max((prices[i] + solve_memo(i + 1, 0, prices, dp)), (0 + solve_memo(i + 1, 1, prices, dp)));
    }
    return dp[i][prev_condition] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve_memo(0, 0, prices, dp);
}
int main()
{

    return 0;
}