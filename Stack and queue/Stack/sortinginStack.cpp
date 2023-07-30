#include <bits/stdc++.h> 
using namespace std;

void printstack(stack<int> &st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void sortedinsert(stack<int> &st,int target){
    if(st.empty() || (!st.empty() && st.top()<target)){
        st.push(target);
    }
    
    int num=st.top();
    st.pop();
    sortedinsert(st,target);
    st.push(num);
}

void sortstack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num=st.top();
    st.pop();
    sortstack(st);
    sortedinsert(st,num);
}
int main()
{
    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    printstack(st);
    sortstack(st);
    printstack(st);
    return 0;
}