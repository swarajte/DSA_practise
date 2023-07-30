#include <bits/stdc++.h> 
using namespace std;

bool validparanthesis(string &str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        char ch=str[i]; 
        
        if(ch=='{' || ch=='[' || ch=='('){          // for opening brackets 
            st.push(ch);
        }
        else{                                       // for closing brackets
            if(st.empty()!=1){
                if((st.top()=='{' && ch=='}') || (st.top()=='[' && ch==']') || (st.top()=='(' && ch==')') ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string str="{[(]}";
    if(validparanthesis(str)){
        cout<<"valid paranthesis ";
    }
    else{
        cout<<" not valid";
    }
    
    

    return 0;
}