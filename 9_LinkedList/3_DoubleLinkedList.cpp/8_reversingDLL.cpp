#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node*next;
        Node*prev;


        Node(int val , Node*nextPtr=NULL , Node*prevPtr=NULL){
            data=val;
            next=nextPtr;
            prev=prevPtr;
        }
    
};
//1)i can create a new DLL usinf the everse vector


// 2)or i can traverse array from behind then replace values of dll
//2)
Node*headOfreverseDLL(vector<int>&arr , Node*head){//if original array is given
    Node*mover=head;
    for (int i = arr.size()-1; i >= 0; i--) {
        mover->data=arr[i];
        mover=mover->next;
    }

    return head;
}

Node*headOfreverseDLLBf( Node*head){
    if(head==NULL)return head;
    else if(head->next=NULL)return head;
    
    Node*mover=head;
    Node*tail=head;

    while(tail->next!=NULL){
        tail=tail->next;
    }//im at tails



   /* * Two-pointer termination condition:
     * 1. mover != tail : Prevents out-of-bounds in odd-length lists. 
     * Stops when both pointers meet on the exact same middle node.
     * 2. tail->next != mover : Prevents data corruption in even-length lists.
     * Stops immediately after the middle two nodes cross paths, 
     * ensuring elements are not swapped a second time.
     */
    while(mover!=tail && tail->next!=mover){
        swap(mover->data , tail->data);
        tail=tail->prev;
        mover=mover->next;
    }


    return head;
}


/*logic is
swap the next and prev node 
1 2 3 4 hai 1 ka next 2 hai prr
reverse mai 4 3 2 1 , 1 abh 2 ka next bn gya h
toh aise hi pointer reverse krne se hojaega
*/
Node*headOfreverseDLLOPt( Node*head){
    Node*mover=head;
    Node*tail=head;

    Node*mover=head;
    Node*newHead;
    while(mover!=NULL){
        swap(mover->next ,mover->prev);
        Node*newHead=mover;//last processed node
        mover=mover->prev;//because next has become prev now
    }
    return newHead;
}



int main() {
    
    return 0;
}