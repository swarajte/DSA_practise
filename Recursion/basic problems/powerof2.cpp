#include <bits/stdc++.h> 
using namespace std;

int PowerOf2(int n){
    if(n==0){
        return 1;
    }

    return 2*PowerOf2(n-1);
} 

int main()
{
    
    cout<<PowerOf2(2)<<endl;
    cout<<PowerOf2(4)<<endl;
    cout<<PowerOf2(5)<<endl;

    return 0;
}