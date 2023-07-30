#include <bits/stdc++.h> 
using namespace std;
class twostack{
    public: 
        int size;
        int top1;
        int top2;
        int * arr;

    twostack(int s){
        this->size=s;
        arr=new int[s];
        this->top1=-1;
        this->top2=s;
    }

    void push1(int ele){
        if(top2-top1>=1){
            top1++;
            arr[top1]=ele;
        }
        else{
            cout<<"stack overflown"<<endl;
        }
    }

    void push2(int ele){
        if(top2-top1>=1){
            top2--;
            arr[top2]=ele;
        }
        else{
            cout<<"stack overflown"<<endl;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
            cout<<"stack1 is empty"<<endl;
            return -1000;
        }
    }

    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
            
        }
        else{
            cout<<"stack2 is empty"<<endl;
            return -1000;
        }
    }

    int peek1(){
        if(top1==-1){
            cout<<"stack1 is empty "<<endl;
            return -1111;
        }
        else{
            return arr[top1];
        }
    }

    int peek2(){
        if(top2==size){
            cout<<"stack1 is empty "<<endl;
            return -1111;
        }
        else{
            return arr[top2];
        }
    } 

};
int main()
{
    twostack st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(8);
    st.push2(9);

    cout<<"top of stack1 is "<<st.peek1()<<" top of stack 2 is "<<st.peek2()<<endl;
    cout<<st.pop1()<<endl;
    st.push2(10);
    cout<<" top of stack 2 is "<<st.peek2()<<endl;
    cout<<"top of stack1 is "<<st.peek1();
    return 0;
}