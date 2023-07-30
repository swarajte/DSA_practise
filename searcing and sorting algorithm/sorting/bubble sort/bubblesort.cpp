#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++) // it will run for n-1 times
    {
        bool swapped=false;
        for (int j = 0; j < a.size() - i; j++)
        {
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;                             //optimization for making best case time complexity = o(n) from o(n^2)  
        }
    }
}
int main()
{

    vector<int> a={1,7,6,10,9,14};
    bubblesort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}