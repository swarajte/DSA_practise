#include <bits/stdc++.h> 
using namespace std;

void ReverseString(string &str,int s,int e ){
    if(s>e){
        return ;
    }
    else{
        swap(str[s],str[e]);
        s++;
        e--;
        ReverseString(str,s,e);
    }
}
int main()
{
    string str;
    cout<<"enter string to be reversed "<<endl;
    cin>>str;
    int s=0;
    int e=str.length()-1; 

    ReverseString(str,s,e);

    cout<<str;

    

    return 0;
}