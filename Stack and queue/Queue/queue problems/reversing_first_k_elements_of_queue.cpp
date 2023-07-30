#include <bits/stdc++.h> 
using namespace std;

void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    } 
    cout<<endl;
}

void solve(queue<int> &q,int k){
    stack<int> st;
    for(int i=0; i<k; i++){
        int val=q.front();
        q.pop();
        st.push(val);
    }

    while(!st.empty()){
        int val=st.top();
        q.push(val);
        st.pop();
    }
    int n=q.size()-k;
    for(int i=0; i<n; i++){
        int val=q.front();
        q.pop();
        q.push(val);
    }

}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);  
    print_queue(q);
    solve(q,3);
    print_queue(q);
    return 0;

    // logic:- firstly push elements to be reversed inside the stack and then push those elemnts back in queue till stack is empty after that use for loop and clip those n-k elemnts and push them at the back of our back 
}