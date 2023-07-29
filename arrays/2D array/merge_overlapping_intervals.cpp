#include <bits/stdc++.h>
using namespace std;

// question : we are given with intervals like [[1,3],[2,6],[8,10],[15,18],[16,17]] and we have reduce it down to [[1,6][8,10][15,18]]

// approach: push_back intial interval in ans and in for loop from i=1 for intervals check................. if intervals[i][0]i.e start is less than ans.back ka end i.e. ans.back()[2] if yes make start=ans.back()[0] and end=max(end , ans.back wala)  and pop_back previous entry and pushback this newly updated entry ...................else push_back start and end without anything

// t.c. =O(n) s.c.=O(N^2)

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (start <= ans.back()[1])
        {
            start = ans.back()[0];
            end = max(end, ans.back()[1]);
            ans.pop_back();
            ans.push_back({start, end});
        }
        else
        {
            ans.push_back({start, end});
        }
    }

    return ans;
}

void printMatrix(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18},{16,17}}; 

    vector<vector<int>> ans=merge(intervals);

    printMatrix(intervals);
    cout<<"merged intervals: "<<endl;
    printMatrix(ans);
    

    return 0;
}