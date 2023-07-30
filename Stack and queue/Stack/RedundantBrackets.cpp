#include <bits/stdc++.h> 
using namespace std;

bool redundantbrack(string &str){
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='('|| str[i]=='*' || str[i]=='+'|| str[i]=='-'|| str[i]=='/'){
            st.push(str[i]);
        }
        else{
            if(str[i]==')'){
                
                bool IsRedundant=true;
                while(st.top()!='('){
                    
                    char top=st.top();
                    if( top=='*' || top=='+'|| top=='-'|| top=='/'){
                        IsRedundant=false;
                    }
                    st.pop();
                }

                if(IsRedundant){
                    return true;
                }
                st.pop(); 
            }
        }
    }
    return false;
}


int main()
{
    string str="((a+b)+(l/m))";
    if(redundantbrack(str)){
        cout<<"redundant brackets found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}