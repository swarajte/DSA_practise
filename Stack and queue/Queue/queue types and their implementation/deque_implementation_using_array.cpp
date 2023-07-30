#include <bits/stdc++.h> 
using namespace std;

class Deque{
    private:
        int * arr;
        int qfront;
        int rear;
        int qsize;
    
    public:
        Deque(int n){
            qsize=n;
            arr=new int[qsize];
            qfront=-1;
            rear=-1;
        }

        void push_back(int t){
            if((rear==qsize-1 && qfront==0) || (rear==(qfront-1)%(qsize-1))){
                cout<<" queue is full "<<endl;          // check if queue is full 
            }

            else if(qfront==-1 && rear==-1){ // given queue is empty and first element to be pushed
                qfront =0;
                rear=0;
                arr[rear]=t;
            }

            else if( rear==qsize-1 && qfront!=0){
                rear=0;
                arr[rear]=t;          // rear is at the last posistion and we have to make rear=0 to maintain cyclic nature
            }

            else{
                rear++;         // normal push operation
                arr[rear]=t;
            }
        }
        void push_front(int t){
            if((rear==qsize-1 && qfront==0) || (rear==(qfront-1)%(qsize-1))){
                cout<<" queue is full "<<endl;          // check if queue is full 
            }
            else if(qfront==-1){
                qfront=0;
                rear=0;             // if queue is empty and we have to push in front
                arr[qfront]=t;
            }
            else if(qfront==0){
                qfront=qsize-1;
                arr[qfront]=t;      // to maintain cyclic nature and when front is at first position 
            }
            else{
                qfront --;
                arr[qfront]=t;
            }
        }

        int pop_back(){
            int ans =arr[rear];
            if(qfront==-1 && rear==-1){
                cout<<"queue is empty "<<endl;  // check if queue is empty 
                return -1;
            }
            else if(qfront==rear){
                qfront=-1;          // single element is present in deque
                rear=-1;
            }
            else if(rear==0){
                rear=qsize-1; // to maintain the cyclic nature 
            }
            else{
                rear--;
            }

            return ans;
        }
        
        int pop_front(){
            int ans=arr[qfront];
            if(qfront==-1 && rear==-1){
                cout<<"queue is empty "<<endl;  // check if queue is empty 
                return -1;
            }
            else if(qfront==rear){    
                qfront=-1;  // single element is present in queue
                rear=-1;
            }
            else if(qfront==qsize-1){
                qfront=0;       // front is at last position make front=0 to maintain cyclic nature 
            }
            else{
                qfront++;  // normal execution
            }

            return ans;

        }

};

int main()
{
    Deque q(4);
    q.push_back(10);
    q.push_front(9);
    q.push_front(8);
    q.push_back(11);
    cout<<q.pop_front()<<endl;
    q.push_front(13);
    cout<<q.pop_front()<<endl;
    cout<<q.pop_front()<<endl;
    cout<<q.pop_front()<<endl;
    cout<<q.pop_front()<<endl;
    cout<<q.pop_front()<<endl;
    

    return 0;
}