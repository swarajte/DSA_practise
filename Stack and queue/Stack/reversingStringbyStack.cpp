#include <bits/stdc++.h> 
using namespace std;

int main()
{
    string name="telkhade";
    stack<char> st; 
    string ans="";

    for(int i=0; i<name.length(); i++){
        char ch=name[i];
        st.push(ch);
    }

    while (st.size()!=0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    cout<<ans;

    return 0;
}