#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        // kind of backtracking to the previous state
        swap(str[index], str[i]);
    }
}

int main()
{
    string str = "abc";
    int index = 0;
    vector<string> ans;
    string output;
    solve(str, index, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{" << ans[i] << "}" << endl;
    }
    return 0;
}