#include <bits/stdc++.h> 
using namespace std;

bool CheckSortednRotated(vector<int> &a){
    int count=0;
    int n=a.size();
    for (int i = 1; i < n; i++)
    {
        if(a[i]<a[i-1]){
            count++;
        }
    }
    if(a[n-1]>a[0]){
        count++;
    }
    if(count<=1){
        return true;
    }
    return false;
}
int main()
{
    vector<int> a={3,4,5,1,2};

    if(CheckSortednRotated(a)){
        cout<<"given array is sorted and rotated";
    }
    else{
        cout<<"not it's not";
    }

    return 0;
}