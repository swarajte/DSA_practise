#include <bits/stdc++.h>
using namespace std;

void merge2sortedarray(int a[], int na, int b[], int nb,int c[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < na && j < nb)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else if (a[i] > b[j])
        {
            c[k++] = b[j++];
        }
    }

    while (i < na)
    {
        c[k++] = a[i++];
    }
    while (j < nb)
    {
        c[k] = b[j];
        j++;
        k++;
    }

}

int main()
{
    int a[5] = {1, 3, 5, 7, 9};
    int b[3]= {2, 4, 6};
    int c[8]={0};
    merge2sortedarray(a, 5, b, 3,c);
    for (int i = 0; i < 8; i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}