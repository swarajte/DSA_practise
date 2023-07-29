#include <bits/stdc++.h>
using namespace std;

bool static cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> mkp = make_pair(start[i], end[i]);
        p.push_back(mkp);
    }

    int cnt = 1;

    sort(p.begin(), p.end(), cmp);

    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[k].second < p[i].first)
        {
            cnt++;
            k = i;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}