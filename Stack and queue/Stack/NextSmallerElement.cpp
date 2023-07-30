#include <bits/stdc++.h> 
using namespace std;

// solution link : https://www.youtube.com/watch?v=Du881K7Jtk8&t=139s
 
int main()
{
    vector<int> a={2,1,4,3};
    vector<int> ans(4);
    int n=a.size();
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        while(st.top()>=a[i]){
            st.pop();
        } 

        ans[i]=st.top(); 
        st.push(a[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}