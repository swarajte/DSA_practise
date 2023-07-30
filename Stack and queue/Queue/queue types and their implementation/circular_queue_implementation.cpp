#include <bits/stdc++.h>
using namespace std;

class Circular_queue
{   
    private:
        int * arr;
        int qfront;
        int rear;
        int qsize;
    
    public:
        Circular_queue(int n){
            qsize=n;
            arr=new int[qsize];
            qfront=-1;
            rear=-1;
        }

        void enqueue(int t){
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

        int dequeue(){
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
    Circular_queue q(4);
    q.enqueue(41);
    q.enqueue(75);
    q.enqueue(486);
    q.enqueue(63);
    q.enqueue(49);
    cout<<q.dequeue()<<endl;
    q.enqueue(49);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}