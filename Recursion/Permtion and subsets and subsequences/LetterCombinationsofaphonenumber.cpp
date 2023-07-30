#include <bits/stdc++.h> 
using namespace std;

void solve(string str,string mapping[],vector<string> &ans,string output,int index){
    if(index>=str.size()){
        ans.push_back(output);
        return;
    }

    int digit=str[index]-'0';
    string value=mapping[digit];
    for (int i = 0; i < value.size() ; i++)
    {
        output.push_back(value[i]);
        solve(str,mapping,ans,output,index+1);
        output.pop_back();
    }
}

int main()
{
    string str="234";
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqs","tuv","wxyz"}; 
    vector<string> ans;
    string output;
    int index=0; 

    solve(str,mapping,ans,output,index);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"{"<<ans[i]<<"}"<<endl;
    }
    

    return 0;
}