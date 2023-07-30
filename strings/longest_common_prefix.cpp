#include <bits/stdc++.h>
using namespace std;


// when vector of string is sorted it is according to alphabetic order 
string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string r = strs[0];
    int n = strs[0].length();
    string s = strs[strs.size() - 1];
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (r[i] == s[i])
        {
            ans += r[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    vector<string> strs={"flower","flow","flight"};
    sort(strs.begin(),strs.end());
    for (int i = 0; i < strs.size(); i++)
    {
        cout<<strs[i]<<" ";
    }
    string ans=longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}
