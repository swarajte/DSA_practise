#include <bits/stdc++.h> 
using namespace std;

void rotateArray(vector<int> &a,int k){
    vector<int> temp(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        temp[(i+k)%a.size()]=a[i];
    }
    a=temp;
}
int main()
{
    vector<int> a={0,1,2,3,4,5,6};
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    rotateArray(a,2);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}