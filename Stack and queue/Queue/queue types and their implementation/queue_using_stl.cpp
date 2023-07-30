#include <bits/stdc++.h> 
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(60);
    q.push(74);
    q.push(86);

    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl; 

    if(q.empty()){
        cout<<"queue is empty ";
    }
    else{
        cout<<"queue is not empty ";
    }

    return 0;
}