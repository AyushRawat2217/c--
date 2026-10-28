#include <bits/stdc++.h>
using namespace std;

//i have to remove nth node from end

/*i can think of 
finding length of LL then  , converting from end to from start
in 5 length LL , 2 from end is 3rd from start

length-n = node from start

*/

class Node{
    
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
        }
    
};


int lengthOfLL(Node*head){
    if(head==NULL)return 0;
    Node*mover=head;
    int count=0;
    while(mover!=NULL){
        count++;
        mover=mover->next;
    }
    return count;
}

Node*newHeadBf(Node*head , int n){

int length=lengthOfLL(head);


if(length<n)return NULL;
if(length == n){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
int nodeFromStart=length-n;

Node*mover=head;

int i=1;
while(mover!=NULL &&  i<nodeFromStart-1){
    i++;
    mover=mover->next;
}//now im at node behind the nth node

if(mover==NULL||mover->next==NULL )return NULL;

if(mover->next->next==NULL){
    Node*temp=mover->next;
    mover->next=NULL;
    delete temp;
    return head;
}

Node*temp=mover->next;//store the old mover->next
Node*nxtPtr=temp->next;
mover->next=nxtPtr;
delete temp;
//delete nxtPtr; i dont have to delete the nth nde->next ptr , i just have to delete the node after connect left and right node

return head;

}

/*logic is

// Move fast pointer n nodes ahead to create a gap of n nodes between fast and slow.
//
// Once the gap is created, move both pointers together.
//
// Because the gap always remains n nodes,
// when fast reaches the last node,
// slow will be standing just before the nth node from the end.
//
// This is exactly where we want to be,
// because deleting a node in a linked list requires access
// to its previous node.
//
// Delete slow->next by linking:
// slow->next = slow->next->next;
//
// Special Case:
// If fast becomes NULL after moving n steps,
// it means the node to remove is the head itself.
// Return head->next.

*/

Node*newHeadOpt(Node*head , int n){
   if(head==NULL)return head;
   if(head->next==NULL){
    if(n==1){
        delete head;
        return NULL;
    }
     return head;
}
   

   Node*slow=head;
   Node*fast=head;
   while(n>0 && fast!=NULL){
    fast=fast->next;
    n--;
   }

   if(n>0)return head;//means fast became null before n beame 0 so it was out of bounds



   if(!fast){//if fast==NULL then it means n=length of list , and which means we have to remove the fhead
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
    }

   while(fast!=NULL && fast->next!=NULL){
    fast=fast->next;
    slow=slow->next;
   }//now slow is just before the node to be deleted


   Node*temp=slow->next;
   slow->next=temp->next;
   delete temp;
   

return head;

}



int main() {
    
    return 0;
}