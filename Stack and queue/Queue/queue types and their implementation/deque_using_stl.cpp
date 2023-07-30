#include <bits/stdc++.h> 
using namespace std;


int main()
{
    deque<int> q;
    q.push_back(10);
    q.push_front(9);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop_back();
    cout<<q.back()<<endl; 
    q.pop_back(); 
    if(q.empty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<" queue is not empty "<<endl;
    }

    return 0;
}