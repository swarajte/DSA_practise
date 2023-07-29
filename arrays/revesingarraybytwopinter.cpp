#include <bits/stdc++.h>
using namespace std;

void reversebydoublepointer(vector<int> &a, int size)
{
    int s = 0;
    int e = size - 1;
    while (s <= e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}
int main()
{
    int n = 4;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    reversebydoublepointer(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}