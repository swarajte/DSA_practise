#include <bits/stdc++.h>
using namespace std;

// top down approach
int fibo1(int n, vector<int> &arr)
{
    if (n <= 1)
    {
        return n;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    arr[n] = fibo1(n - 1, arr) + fibo1(n - 2, arr);
    return arr[n];
} 

// bottom up approach 
int fibo2(int n,vector<int> &arr){
    arr[0]=0;
    arr[1]=1;

    for(int i=2; i<=n; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }

    return arr[n];
}


// space optimization
int fibo3(int n){
    int prev1=1;
    int prev2=0;

    for(int i=2; i<=n; i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}

int main()
{
    int n = 4;
    vector<int> arr(n+1);
    for (int i = 0; i <=n; i++)
    {
        arr[i] = -1;
    }

    cout << "fibo of nth number is " << fibo3(n)<<endl;
    cout << "fibo of nth number is " << fibo2(n, arr)<<endl;
    cout << "fibo of nth number is " << fibo1(n, arr)<<endl;

    return 0;
}