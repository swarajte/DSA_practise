#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<vector<int>> &m){
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while(st.size()!=1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();

        if(m[a][b]==1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int ans=st.top();
    int rcount=0;
    int colcount=0;

    for (int i = 0; i < n; i++)
    {
        if(m[ans][i]==0){
            rcount++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(m[i][ans]==1){
            colcount++;
        }
    } 

    if(rcount!=n || colcount!=n-1){
        return -1;
    }
    else{
        return ans;
    }

}
int main()
{
    int n = 3;
    vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}}; 
    cout<<solve(n,m);
    return 0;
}