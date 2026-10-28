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


Node*sort012ofLLByRearrangingNodes(Node*head){
    /*i create three dummy nodes 
    jinke aaghe se mai apna 0 , 1 , 2 nodes 
    k link jodunga othewise , node initialise krne wali process complicate hojati*/
    Node dummy0(-1);
    Node dummy1(-2);
    Node dummy2(-3);


    /*these are the extension for the
     three sublists containin 0 , 1 ,2 nodes*/

     /*Tail starts at the dummy node because initially
the sublist contains only the dummy node.

dummy.next is NULL at the beginning, so using:
    Node* tail = dummy.next;
would make tail NULL and tail->next would crash.

By starting with:
    Node* tail = &dummy;

the first node can be attached safely using:
    tail->next = mover;

After each insertion, tail is moved forward
to keep pointing to the last node of the sublist.
*/
    Node*tail0=&dummy0;
    Node*tail1=&dummy1;
    Node*tail2=&dummy2;

    Node*mover=head;

    while(mover){
        if(mover->data==0){
            tail0->next=mover;
            tail0=tail0->next;
        }
        else if(mover->data==1){
            tail1->next=mover;
            tail1=tail1->next;
        }

        else{
            tail2->next=mover;
            tail2=tail2->next;
        }
        
        mover=mover->next;

    }

    /*now lets link all the lists
    the the head of main link list will connect dummy0 next
    then tail0 connect with dummy 1->next  and similarly tail1
     connect with dummy2 next and at last tail2 points null and head is returned
    */

    head=dummy0.next;
    tail0->next=dummy1.next;
    tail1->next=dummy2.next;
    tail2->next=NULL;

    /*******************************************************
'.' vs '->'

Use '.' when the variable itself is an object.

    Node dummy(-1);
    dummy.next;      // Correct

Use '->' when the variable is a pointer to an object.

    Node* mover = head;
    mover->next;     // Correct

The arrow operator automatically dereferences
the pointer before accessing the member.

    mover->next
is equivalent to:
    (*mover).next

Examples:

    Node dummy(-1);
    dummy->next;     // Wrong (dummy is not a pointer)

    Node* mover = head;
    mover.next;      // Wrong (mover is a pointer)
*******************************************************/


    return head;
   

}

Node*convertingArrayToLLThenReturningHead(vector<int>&arr){
    Node*head=new Node(arr[0]);//returns the adress of the node where value is arr[0] and which is pointing to null
    Node*mover=head;//mover works as a setter to join nodes , it will be the pointer which
    //will travel all across the array

    for (int i = 1; i < arr.size(); i++) {
      Node*temp=new Node(arr[i]);//returns address of node with arr[1] as data at first iteration and stored in temp , temp stores the adress where the node containing arr[i] is saved
      mover->next=temp;//mover points to the adress which hold node which store arr[i]
      //if this is first iteration then the node which hold arr[0] now holds adress of node which store [arr[1]]
      mover=temp; //lets move the mover to the temp do that we can point it to next node in next iteration
    }

    return head;

}


int main() {
    vector<int>arr={0,1,2,1,0,0,2};
    Node*head=convertingArrayToLLThenReturningHead(arr);
    Node*newHead=sort012ofLLByRearrangingNodes(head);

    Node*mover=newHead;
    while(mover){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    
    return 0;
}
    