#include <bits/stdc++.h> 
using namespace std;

class Queue{
    private:
        int*arr;
        int qfront;
        int rear;
        int size;

    public:
        Queue(int k){
            size=k;
            arr=new int[size];
            rear=0;
            qfront=0;
        }

        bool isEmpty(){
            if(qfront==rear){
                return true;
            }
            else{
                return false;
            }
        }

        void enqueue(int t){
            if(rear==size-1){
                cout<<" queue is full "<<endl;
            }
            else{
                arr[rear]=t;
                rear++;
            }
        }

        int dequeue(){
            if(isEmpty()){
                return -1;
            }
            else{
                int ans=arr[qfront];
                arr[qfront]=-1;
                qfront++;
                if(qfront==rear){
                    qfront=0;
                    rear=0;
                }
                return ans;
            }
        }

        int front(){
            if(isEmpty()){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }

        int qsize(){
            if(isEmpty()){
                return 0;
            }
            else{
                return rear-qfront+1;
            }
        }

};


int main()
{

    Queue q(5); 
    q.enqueue(10);
    q.enqueue(200);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 

    cout<<q.qsize()<<endl; 
    // cout<<q.dequeue()<<endl; 
    // cout<<q.qsize()<<endl;

    cout<<q.front()<<endl; 
    q.enqueue(445);
    return 0;
}