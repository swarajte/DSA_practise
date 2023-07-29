#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
        int val;
        Node*next;

    Node(int d){
        this->val=d;
        this->next=NULL;
    }
};
class compare{
        public:
            bool operator()(Node*a,Node*b){
                return a->val > b->val;
            }
    };

    Node* mergeKLists(vector<Node*>& lists) {
        
        if(lists.size()==0){
            return NULL;
        }

        int k=lists.size();
        //create minheap of type node* and two node pointers head and tail for result
        priority_queue<Node*,vector<Node*>,compare> minheap;
        Node*head=NULL;
        Node*tail=NULL;

        //push all  first nodes of all k linked lists
        for(int i=0; i<k; i++ ){
            if(lists[i]!=NULL){
                minheap.push(lists[i]);
            }
        }

        //store top of minheap i.e minimum element in temp ans ans make arrangement of head and tail accordingly to accomdate that minheap ka top and also check for its next minheap push

        while(!minheap.empty()){
            Node*top=minheap.top();
            minheap.pop();

            if(head==NULL){
                head=top;
                tail=top;
                if(tail->next!=NULL){
                    minheap.push(tail->next);
                }
            }
            else{
                tail=top;
                if(tail->next!=NULL){
                    minheap.push(tail->next);
                }
            }
        }

        return head;
    }
int main()
{

    return 0;
}