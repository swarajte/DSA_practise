#include <bits/stdc++.h> 
using namespace std;

int tour(vector<int> petrol,vector<int> distance,int n){
    int deficit=0;
    int balance=0;
    int start=0;

    for (int i = 0; i < n; i++)
    {
        balance+=petrol[i]-distance[i];
        if(balance<0) {
            deficit+=balance;
            balance=0;
            start=i+1;
        }  
    } 

    if(deficit+balance>=0){
        return start;
    }
    else{
        return -1;
    }
}

int main()
{
    vector<int> petrol={4,6,7,4};
    vector<int> distance={6,5,3,5};
    int n=4;
    cout<<tour(petrol,distance,n);
    return 0;
}