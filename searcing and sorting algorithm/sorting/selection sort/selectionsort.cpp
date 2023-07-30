#include <bits/stdc++.h> 
using namespace std;

void selectionsort(vector<int> a){
    for(int i=0; i<a.size(); i++){
        int minIndex=i;
        for (int j = i+1; j < a.size(); j++)
        {
            if(a[j]<a[minIndex]){
                minIndex=j;
            }
        }
        swap(a[minIndex],a[i]); 
    }
    for (int i = 0; i < a.size(); i++)
        {
            cout<<a[i]<<" ";
        }
}

int main()
{
    vector<int> a={6,2,8,4,10};
    selectionsort(a);
    return 0;
}