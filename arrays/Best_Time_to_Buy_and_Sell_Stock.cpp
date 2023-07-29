#include <bits/stdc++.h>
using namespace std;

// question : we are given with array of prices prices[i] representing price on ith day we have to find maximum profit by selecting appropriate buying and selling also we cannot sell before buying

// approach 1 : two loops for in for and find maximum profit
// t.c : O(n^2)  s.c = O(1)
int maxProfit_approach1(vector<int> &prices)
{
    int maxi = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            maxi = max(maxi, prices[j] - prices[i]);
        }
    }
    if (maxi > 0)
    {
        return maxi;
    }
    return 0;
}


// approach 2 : iterate in for loop and consider ith day as selling therefore profit = prices[i]- minimum before ith day,,,,,,initialy consider minimum as prices[0] and update mini in each iteration 
// t.c : O(n)  s.c = O(1)
int maxProfit_approach2(vector<int> &prices)
{
    int maxProfit = 0;
    int miniBuy=prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        int profit=prices[i]-miniBuy;
        maxProfit=max(profit,maxProfit);
        miniBuy=min(prices[i],miniBuy);
    }
    
    return maxProfit;
}
int main()
{
    vector<int> prices={7,1,5,3,6,4}; 
    cout<<"maximum profit will be : "<<maxProfit_approach2(prices);
    return 0;
}