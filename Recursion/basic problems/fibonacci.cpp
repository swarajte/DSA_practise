#include <bits/stdc++.h> 
using namespace std;

int Fibo(int n){
    if(n==0 || n==1){
        return n;
    }

    return Fibo(n-1)+Fibo(n-2);
} 

int main()
{
    
    cout<<Fibo(1)<<endl;
    cout<<Fibo(2)<<endl;
    cout<<Fibo(3)<<endl;
    cout<<Fibo(4)<<endl;

    return 0;
}