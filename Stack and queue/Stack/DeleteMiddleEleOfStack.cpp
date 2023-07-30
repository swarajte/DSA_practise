#include <bits/stdc++.h> 
using namespace std;
void print(stack<int> &st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }

} 

void solve(stack<int> &st,int count,int n){
    if(count==n/2){
        st.pop();
        return ;
    }

    int num=st.top();
    st.pop();

    solve(st,count+1,n);

    st.push(num);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.push(5);

    solve(st,0,4);

    print(st);

    return 0;
}