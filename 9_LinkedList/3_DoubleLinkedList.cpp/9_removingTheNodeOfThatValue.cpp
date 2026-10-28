#include <bits/stdc++.h>
using namespace std;


class Node{ //initialising double linked list
    public:
        int data;
        Node*next;
        Node*prev;

  /**Imp regarding constructors
 * @brief Node constructor using default arguments.
 * * This design handles 1, 2, or 3 parameters seamlessly:
 * - Pass 1 arg (val): Creates an isolated node (next and prev default to NULL).
 * - Pass 2 args (val, nextPtr): Links forward; prev defaults to NULL.
 * - Pass 3 args (val, nextPtr, prevPtr): Fully links the node in both directions.
 * * Note: If you frequently need to pass ONLY (val, prevPtr), reorder the parameters
 * to (int val, Node* prevPtr = NULL, Node* nextPtr = NULL).
 */
    
 Node(int val , Node*nextPtr=NULL, Node*prevPtr=NULL){
        data=val;
        next=nextPtr;
        prev=prevPtr;
    }


};


//in this approach im creating a new dll to store node 
Node*remvngTheNodesOfValueKBf(Node*head , int k){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        if(head->data==k){
            delete head;
            return NULL;
        }
        return head;
    }
    Node*dummy=new Node(-1);
    Node*tail=dummy;

    Node*mover=head;
    Node*temp=NULL;

    /* Traverse the DLL node by node.

    Store nextNode first because current node may be
    attached to the new DLL or deleted.

    If current node's value != k:
    - Attach it after tail.
    - Update its prev pointer.
    - Move tail forward.

    Otherwise:
    - Delete the current node.

    Move to nextNode and continue until traversal ends.
*/
    while(mover){
        Node*nxtPtr=mover->next;
        if(mover->data!=k){
            mover->prev=(tail==dummy)?NULL:tail;//mover ka prev set krdiya

            //abh tail ka next set krna h

            tail->next=mover;//tail is the previous node
            tail=tail->next;

        }
        else{
          delete mover;
        }
        mover=nxtPtr;
        
    }
    Node*newHead=dummy->next;
    delete dummy;

    return newHead;
}

//here i will remove the node without creating an extra ll

/*in all the dll problems thibk as what if node is head
or what if head is tail means think in terms of edge cases */
Node*remvngTheNodesOfValueKOpt(Node*head , int k){
    if(head==NULL)return NULL;
    while(head && head->data==k){
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    if(!head)return NULL;
    Node*mover=head;
    head->prev=NULL; // " after Destroying  the prev head node , update everyone who was pointing to it."
    


    /*logic 
   First remove all leading nodes having value k and
    update head to the first valid node.

    Then traverse the remaining DLL.

    Whenever a node with value k is found:
    - Connect its previous node to its next node.
    - Update the next node's prev pointer (if it exists).
    - Delete the current node.

    Store nextNode before deletion so traversal can continue safely.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
    while(mover){
        Node*nxtptr=mover->next;
        if(mover->data==k){
            mover->prev->next=mover->next;
            if(nxtptr){
                nxtptr->prev=mover->prev;
            }
            delete mover;
        }
        mover=nxtptr;
    }
    return head;
    
}



int main() {
    
    return 0;
}