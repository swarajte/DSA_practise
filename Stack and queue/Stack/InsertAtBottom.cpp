#include <bits/stdc++.h> 
using namespace std;

void print(stack<int> &st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }

}

void Insertatbottom(stack<int> &st,int target){
    if(st.empty()){
        st.push(target);
        return;
    }

    int num=st.top();
    st.pop();
    Insertatbottom(st,target);
    st.push(num);
}
int main()
{
    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    Insertatbottom(st,9);

    print(st);

    return 0;
}