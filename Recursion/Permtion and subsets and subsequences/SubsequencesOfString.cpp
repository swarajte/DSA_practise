#include <bits/stdc++.h> 
using namespace std;

void solve(string str,string output,int index,vector<string> &ans){
    if(index>=str.size()){
        ans.push_back(output);
        return;
    }

    // exclude ka call
    solve(str,output,index+1,ans);

    // include ka call
    char ele=str[index];
    output=output+ele;
    solve(str,output,index+1,ans);
}
int main()
{
    string str="abc";
    int index=0;
    string output="";
    vector<string> ans;
    solve(str,output,index,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"{"<<ans[i]<<"}"<<endl;
    }
    

    return 0;
}