#include <bits/stdc++.h> 
using namespace std;

bool solve(double n){
    if(n==2.0){
        return true;
    }
    if(n<2){
        return false;
    }

    return solve(n/2);
}
bool solve_1(int n){
    double N=n;
    return solve(N);
}
int main()
{
    if(solve(24)){
        cout<<"yes ";
    }
    else{
        cout<<" no";
    }

    return 0;
}