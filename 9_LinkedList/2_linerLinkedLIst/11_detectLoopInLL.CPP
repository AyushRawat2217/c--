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
Brute-force cycle detection:

For each node (mover), check whether mover->next points to
any node that appears before mover in the list.

- If mover->next points to a previous node, a cycle exists.
- If mover->next == mover, it is a self-loop, which is also a cycle.

Idea:
A valid singly linked list can only move forward to a new node
or end at NULL. Pointing back to an already visited node means
the list contains a loop.

Time Complexity: O(n²)
Space Complexity: O(1)
*/
bool isThereAloopInLLbf(Node*head){
    if(head==NULL)return false;
    if(head->next==NULL)return false;
    Node*mover=head;

    while(mover->next!=NULL){
        Node*mover2=head;
        while(mover2!=mover){
            if(mover->next==mover2||mover->next==mover)return true;
            mover2=mover2->next;
        }
        mover=mover->next;
    }

    return false;
}


/*logic is
we use hashmap or unordered set  to store nodes
and use find property of set and map

tc is on , sc is on
*/
bool isThereAloopInLLbr(Node*head){
    if(head==NULL)return false;
    
    Node*mover=head;
    unordered_map<Node* , int>mpp;

    //or i could have used unordered set as well 

    while(mover!=NULL){
        if(mpp.find(mover)!=mpp.end())return true;
        mpp[mover]++;

        mover=mover->next;
    }

    return false;
}

/*logic
Use two pointers:

Slow moves 1 step.
Fast moves 2 steps.

If a cycle exists:
Fast enters the cycle and gains 1 node on slow every iteration,
so eventually both pointers meet.

If no cycle exists:
Fast reaches NULL (or fast->next becomes NULL),
therefore no loop is present.

| Iteration | Slow | Fast |
| --------- | ---- | ---- |
| Start     | 1    | 1    |
| 1         | 2    | 4    |
| 2         | 3    | 4    |
| 3         | 4    | 4    |
*/
bool isThereAloopInLLOpt(Node*head){
    if(head==NULL)return false;
    
    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)return true;
    }
//ek na ek baar toh match hogaaa
//pt wo loop k kisi bhi elemnt p hoskta h
    
    return false;
}



int main() {
    
    return 0;
}