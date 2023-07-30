#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (temp < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            j--;
        }
        a[j + 1] = temp;
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    vector<int> a = {4, 2, 1, 3};
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    insertionsort(a);
    return 0;
}