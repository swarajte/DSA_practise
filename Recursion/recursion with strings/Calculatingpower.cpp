#include <bits/stdc++.h> 
using namespace std;

int calculatepower(int a,int b){
    if(b==0){
        return 1;
    }

    if(b%2==0){
        return calculatepower(a,b/2)*calculatepower(a,b/2);
    }
    else{
        return a*calculatepower(a,b/2)*calculatepower(a,b/2);
    }
}
int main()
{

    int a,b;
    cout<<"enter a and b "<<endl;
    cin>>a>>b;
    cout<<a<<" ^ "<<b<<" = "<<calculatepower(a,b);
    return 0;
}