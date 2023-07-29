#include <bits/stdc++.h>
using namespace std;

double distance(double x, double y, int p, int q)
{
    double X = abs(x - double(p));
    double Y = abs(y - double(q));

    double res = sqrt((X * X) + (Y * Y));

    return res;
}

double max_dist(vector<pair<int, int>> p, double x, tuple<int, int, int> l)
{

    double y = -((get<0>(l) * x + get<2>(l)) / get<1>(l));
    double maxi = 0;
    for (int i = 0; i < p.size(); i++)
    {
        maxi += distance(x, y, p[i].first, p[i].second);
    }
    return maxi;
}

double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n)
{
    // Write your code here
    double low = -1e3;
    double high = 1e3;
    double mid1 = low + (high - low) / 3;
    double mid2 = high - (high - low) / 3;
    double global_max = 1e18;

    while (high - low > 1e-3)
    {
        if (max_dist(p, mid1, l) > max_dist(p, mid2, l))
        {
            // global_max=max_dist(p,mid,l);
            low = mid1;
        }
        else
        {
            high = mid2;
        }
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
    }

    return max_dist(p, low, l);
}

int main()
{

    return 0;
}