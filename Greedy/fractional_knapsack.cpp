#include <bits/stdc++.h>
using namespace std;

// problem statement : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

bool static cmp(Item a, Item b)
{
    double r1 = (double)(a.value) / (double)(a.weight);
    double r2 = (double)(b.value) / (double)(b.weight);

    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    int currweight = 0;
    double currvalue = 0.0;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (currweight + arr[i].weight <= W)
        {
            currvalue += arr[i].value;
            currweight += arr[i].weight;
        }
        else
        {
            int remain = W - currweight;
            currvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return currvalue;
}

int main()
{

    return 0;
}