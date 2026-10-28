#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
    
    Node(int val){
        data=val;
        next=NULL;
    }
    Node(int val , Node*ptr){
        data=val;
        next=ptr;
    }

};

/*// Insert a new node at the beginning of the linked list.
// Create a node with the given value.
// Point its next to the current head.
// Return the new node's address as the new head.
*/
Node*insertAtStart(Node*head , int value){
    Node*newHead=new Node( value);
    newHead->next=head;
    return newHead;
}

Node*insertAtLast(Node*head , int val){
    Node*mover=head;//
    Node*newTail=new Node(val); // i got a address for val in the heap memory
    while(mover->next!=NULL)mover=mover->next;

    mover->next=newTail;
    return head;
}


/*we are given the kth position where we have to insert value in 
and along with that we are given the value too so we have insert the node tight after k-1th position
and whnever solving these problem or any probelm think in term of edge cases
*/
Node*insertAtKthPosition(Node*head , int val , int k){

    //1st case what if Ll is empty
if(head==NULL){
    
    //IF WE AR INSTRUCTED TO INSERT NODE AT K=1
    if(k==1){
        Node*newNode=new Node(val);
        return newNode;
     }
     else return head;// return head if k>1
    }


if(k == 1){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}


Node*mover=head;
int count=1;

while(mover!=NULL&&count<k-1){//MOVER BECOME NULL WHEN K IS OUT OF BOUND
    //MOVER STAYS AT LAST POSTION IF KTH ELEMNT WANT TO GET INSERTED AT TAILS
    mover=mover->next;
    count++;
}//my mover will be at k-1 th position


if(mover==NULL)return head;//means it was out of bound

//inserting at k-1th position
Node*temp=new Node(val);//create a address in heap
temp->next=mover->next;
mover->next=temp;

return head;
}



Node*insertBeforeVal(Node*head , int val , int k){ //insert value k before val

    //1st case what if Ll is empty
if(head==NULL)return head;

if(head->data==val){}
    
Node*mover=head;

while(mover->next!=NULL && mover->next->data!=val){//mover->next!=NULL , it means that it will move till last second so that
    //i at least stop to check mover->next ka data 
    mover=mover->next;
}//im aT node before the node HVing value val

if(mover->next==NULL)return head;//there is no val

//inserting before node of value k
Node*temp=new Node(k);//create a address in heap
temp->next=mover->next;
mover->next=temp;

return head;
}

int main() {
    
    return 0;
}