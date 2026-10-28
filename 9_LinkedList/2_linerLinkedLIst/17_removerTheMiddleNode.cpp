#include <bits/stdc++.h>
using namespace std;

class Node{
    
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
        }
    
};

/*logic is
i will check the length then go to mid 
according to odd or even*/

int lengthOfLL(Node*head){

}

/*edgse case ar
no elemnt 
1 elemnt and 2 elemnts 
for 3 4 ,5 this works very fine*/
Node*newHeadAfterRmvingMidNodeOpt(Node*head){


if(head==NULL)return head;
if(head->next==NULL){
    delete head;
    return NULL;
}
if(head->next->next==NULL){
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node*slow=head;
Node*fast=head;
Node*prevPtr;

while(fast!=NULL && fast->next!=NULL){
    prevPtr=slow;
    slow=slow->next;
    fast=fast->next->next;
}

Node*temp=prevPtr->next;
prevPtr->next=temp->next;
delete temp;

return head;

}

int main() {
    
    return 0;
}