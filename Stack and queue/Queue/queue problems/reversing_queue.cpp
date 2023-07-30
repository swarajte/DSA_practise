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

void reversal_using_stack(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
} 


void reversal_using_recursion(queue<int> &q){
    if(q.empty()){
        return;
    }

    int fr=q.front(); 
    q.pop();
    reversal_using_recursion(q);
    q.push(fr);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); 
    // print_queue(q);
    // reversal_using_stack(q);
    // print_queue(q);

    print_queue(q);
    reversal_using_recursion(q);
    print_queue(q);
    return 0;
}