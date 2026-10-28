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


/*logic
    Traverse the sorted DLL from the second node onwards.

    For each node, compare its value with the previous node.
    If both values are equal, the current node is a duplicate.

    Remove the duplicate node by connecting its previous node
    directly to its next node and updating both DLL links.

    Store nextNode before deletion so traversal can continue safely.

    Since the DLL is sorted, duplicates always appear adjacent
    to each other, so comparing with the previous node is sufficient.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
Node*rmvDuplicateNode(Node*head){
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;

    Node*mover=head->next;

    while(mover){
        Node*prevPtr=mover->prev;
        Node*nxtPtr=mover->next;
        Node*temp=mover;
        if(mover->data==prevPtr->data){// 1 1 1 2 2 , mover is at 2nd 1 , so will chect 1st 1==2nd 1 , then i will remove the middle one , and join both , then i will remove last one and join 1st and 2nd one
            //here i will be removing the mover
           prevPtr->next=nxtPtr;
           if(nxtPtr)nxtPtr->prev=prevPtr;//if nxtPtr is null , i dont eant to derefrence the null
           delete temp;
        }
        mover=nxtPtr;

    }

    return head;
}



int main() {
    
    return 0;
}