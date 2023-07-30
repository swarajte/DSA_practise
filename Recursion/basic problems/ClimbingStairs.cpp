#include <bits/stdc++.h> 
using namespace std;

int CountWays(int n){
    if(n<0){
        return 0;      //if the recursive call goes for n as negative number
    }

    if(n==0){
        return 1;       // as man is standing on 0th stair so there is only 1 way he can reach stair no 0
    }

    return CountWays(n-1)+CountWays(n-2); // man must have reached nth stair either by jumping two steps form n-2 or 1 step from n-1
}
int main()
{
    cout<<CountWays(3);
    return 0;
}