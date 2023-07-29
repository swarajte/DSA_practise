#include <bits/stdc++.h>
using namespace std;

int f_recursive(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[0][task];
                maxi = max(maxi, point);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f_recursive(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int f_memoiz(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[0][task];
                maxi = max(maxi, point);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f_memoiz(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int f_tabular(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // if(day==0){
    //     int maxi=0;
    //     for(int task=0; task<3; task++){
    //         if(task!=last){
    //             int point=points[0][task];
    //             maxi=max(maxi,point);
    //         }
    //     }
    //     return maxi;
    // }

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
   
    int n=points.size();
    for (int day = 1; day < n; day++)
    {
        for (last = 0; last < 4; last++)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            return dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
    // for(int task=0; task<3; task++)
    // {
    //     if(task!=last){
    //         int point=points[day][task] + f_memoiz(day-1,task,points,dp);
    //         maxi=max(maxi,point);
    //     }
    // }
    // return dp[day][last]=maxi;
}

int f_optimisi_space(int day,int last,vector<vector<int>> &points,vector<vector<int> > &dp){
    // if(day==0){
    //     int maxi=0;
    //     for(int task=0; task<3; task++){
    //         if(task!=last){
    //             int point=points[0][task];
    //             maxi=max(maxi,point);
    //         }
    //     }
    //     return maxi;
    // }

    // if(dp[day][last]!=-1){
    //     return dp[day][last];
    // }
    // int maxi=0;
    // for(int task=0; task<3; task++)
    // {
    //     if(task!=last){
    //         int point=points[day][task] + f(day-1,task,points,dp);
    //         maxi=max(maxi,point);
    //     }
    // }
    // return dp[day][last]=maxi;
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // if (dp[day][last] != -1)
    // {
    //     return dp[day][last];
    // }
   
    int n=points.size();
    for (int day = 1; day < n; day++)
    {
        for (last = 0; last < 4; last++)
        {
            dp[day][last]=0;
            
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
            
        }
    }

    return dp[n - 1][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // return f_recursive(n-1,3,points);
    return f_memoiz(n - 1, 3, points, dp);
}

int main()
{
    return 0;
}