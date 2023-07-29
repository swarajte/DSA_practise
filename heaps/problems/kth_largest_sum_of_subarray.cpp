#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &Arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum = Arr[j] + sum;
            if (pq.size() < K)
            {
                pq.push(sum);
            }
            else
            {
                if (pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

int main()
{
    vector<int> Arr = {};
    int N = Arr.size();
    int k = 4;
    int ans = kthLargest(Arr, N, k);

    return 0;
}