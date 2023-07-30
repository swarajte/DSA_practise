#include <bits/stdc++.h> 
using namespace std;

int main()
{
    stack<int> st;
    st.push(22);
    st.push(28);
    st.push(46);

    cout<<st.top()<<endl; 
    st.pop();
    cout<<st.top()<<endl; 

    st.pop();
    st.pop();

    if(st.empty()){
        cout<<"stack is empty";
    }

    return 0;
}