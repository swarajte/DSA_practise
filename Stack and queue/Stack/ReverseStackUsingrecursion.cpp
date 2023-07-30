#include <bits/stdc++.h>
using namespace std;

void print(stack<int> &st)
{
    while (st.size() != 0)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}
int main()
{
    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    print(st); 
    reverseStack(st);
    cout<<st.top();

    return 0;
}