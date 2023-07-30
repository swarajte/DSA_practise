#include <bits/stdc++.h> 
using namespace std;

string solve(string str){
    string ans="";
    queue<char> q;
    unordered_map<char,int> count;
    for (int i = 0; i < str.length(); i++)
    {
        char ch=str[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(count[ch]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    } 

    return ans;
}

int main()
{
    string str="aabc";
    string ans=solve(str);

    cout<<ans;

    return 0;
}