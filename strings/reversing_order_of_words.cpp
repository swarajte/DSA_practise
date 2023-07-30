#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    stack<string> st;
    string ans = "";
    int index = 0;
    while (index < s.length())
    {
        string pushs = "";
        if (s[index] == ' ')
        {
            index++;
            continue;
        }
        else
        {
            string word = "";
            while (index < s.size() && s[index] != ' ')
            {
                word += s[index];
                index++;
            }
            st.push(word);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (!st.empty())
        {
            ans += " ";
        }
    }

    return ans;
}

int main()
{
    string s=" my name is kgf";
    string ans=reverseWords(s);
    cout<<ans; 
    return 0;
}