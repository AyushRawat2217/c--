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

int lengthOfLL(Node*head){
}

Node*reverseTheLL(Node*start ){
    Node*mover=start;
    Node*newHead;
    Node*temp=NULL;
    while(mover){
        newHead=mover;
        Node*nxtPtr=mover->next;
        mover->next=temp;
        temp=mover;

        mover=nxtPtr;
    }

    return newHead;
}


Node*findKthNode(Node*start ,int k){
    int count =1;
    while(start && count<k){
        count++;
        start=start->next;
    }
    return start;
}



/*logic
REVERSE LINKED LIST IN GROUPS OF SIZE K

Example:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
k = 3

Expected:
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8


--------------------------------------------------
CORE IDEA
--------------------------------------------------

For every group of k nodes:

1. Find the kth node.
2. Save the start of the next group.
3. Detach the current group.
4. Reverse the current group.
5. Reconnect everything.
6. Move to the next group.

--------------------------------------------------
ITERATION 1
--------------------------------------------------

Initial List:

head
 |
 v
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

mover = 1


STEP 1 : Find kth node

1 -> 2 -> 3
          ^
       kthNode


STEP 2 : Save next group

nextGroup = kthNode->next

nextGroup = 4

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
          ^
       kthNode


STEP 3 : Detach current group

kthNode->next = NULL

Current Group:
1 -> 2 -> 3 -> NULL

Remaining:
4 -> 5 -> 6 -> 7 -> 8


STEP 4 : Reverse current group

1 -> 2 -> 3

becomes

3 -> 2 -> 1

newHead = 3

IMPORTANT:

mover is STILL pointing to node 1.

Before reversal:

mover
 |
 v
1 -> 2 -> 3

After reversal:

3 -> 2 -> 1
          ^
          |
        mover

The variable mover never moved.
Only links changed.

Therefore:

Old Head = New Tail

This is the most important observation.


STEP 5 : Connect group

Since this is the first group:

head = newHead

head
 |
 v
3 -> 2 -> 1

Now connect tail to remaining list:

mover->next = nextGroup

1->next = 4

List becomes:

3 -> 2 -> 1 -> 4 -> 5 -> 6 -> 7 -> 8


STEP 6 : Update pointers

prevTail = mover

prevTail
    |
    v
3 -> 2 -> 1 -> 4 -> 5 -> 6 -> 7 -> 8

mover = nextGroup

mover = 4


--------------------------------------------------
ITERATION 2
--------------------------------------------------

Current List:

3 -> 2 -> 1 -> 4 -> 5 -> 6 -> 7 -> 8
               ^
             mover


STEP 1 : Find kth node

4 -> 5 -> 6
          ^
       kthNode


STEP 2 : Save next group

nextGroup = 7


STEP 3 : Detach

4 -> 5 -> 6 -> NULL

7 -> 8


STEP 4 : Reverse

4 -> 5 -> 6

becomes

6 -> 5 -> 4

newHead = 6

mover still points to 4.

After reversal:

6 -> 5 -> 4
          ^
          |
        mover


STEP 5 : Connect to previous reversed group

Currently:

3 -> 2 -> 1

6 -> 5 -> 4

They are separate pieces.

How do we connect them?

Using prevTail.

prevTail points to 1.

prevTail->next = newHead

1->next = 6

Now:

3 -> 2 -> 1 -> 6 -> 5 -> 4


STEP 6 : Connect tail to next group

mover->next = nextGroup

4->next = 7

Result:

3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8


STEP 7 : Update

prevTail = mover

prevTail = 4

mover = nextGroup

mover = 7


--------------------------------------------------
ITERATION 3
--------------------------------------------------

7 -> 8

Need 3 nodes.

Not enough nodes.

findKthNode() returns NULL.

Stop.

Remaining nodes stay unchanged.


FINAL ANSWER

3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8


--------------------------------------------------
WHY DO WE NEED prevTail ?
--------------------------------------------------

Suppose first group is already reversed:

3 -> 2 -> 1

Now second group gets reversed:

6 -> 5 -> 4

How do we connect:

1 ---> 6

?

We need a pointer to node 1.

That pointer is prevTail.

prevTail always points to the tail of the
previously reversed group.

Connection:

prevTail->next = newHead


--------------------------------------------------
WHY DOES prevTail = mover WORK ?
--------------------------------------------------

Before reversal:

mover
 |
 v
1 -> 2 -> 3

After reversal:

3 -> 2 -> 1
          ^
          |
        mover

mover still points to node 1.

Node 1 is now the tail.

Therefore:

prevTail = mover

means

prevTail = tail of current reversed group


--------------------------------------------------
WHY SPECIAL HANDLING FOR FIRST GROUP ?
--------------------------------------------------

Initially:

prevTail = NULL

If we directly do:

prevTail->next = newHead

it becomes:

NULL->next

which crashes.

Therefore first group does:

head = newHead

and all later groups do:

prevTail->next = newHead


--------------------------------------------------
ROLE OF EACH POINTER
--------------------------------------------------

mover
    = start of current group

kthNode
    = end of current group

nextGroup
    = start of next group

newHead
    = head after reversing current group

prevTail
    = tail of previous reversed group

head
    = final answer's head


--------------------------------------------------
MOST IMPORTANT MEMORY TRICK
--------------------------------------------------

After reversing a group:

Old Head = New Tail

Since mover was pointing to the old head,
mover automatically becomes the tail after reversal.

That single observation makes the entire
k-group reversal algorithm easy.
*/


Node*revKsizeLL(Node*head , int k){
    if(head==NULL || head->next==NULL || k==0||k==1)return head;

    Node*mover=head;
    Node*prevTail=NULL;
    while(mover){
        Node*kthNode=findKthNode(mover , k);
        if(!kthNode){//k surpsased the emaining elemnts now i will add the remianingf elemnt to reversed grouped ll
            if(prevTail){
                prevTail->next=mover;
            }
            break;
        }
        Node*nxtGroup=kthNode->next;
        nxtGroup->next=NULL;// i cant reverse a group of linked list until its detached from the list 
        Node*newHead=reverseTheLL(mover);//reversing the ll till kth node

        if(mover==head){//first group
            head=newHead;
        }
        else{
            prevTail->next=newHead;//to attach 1st reversed group to another reverse group-
        }

        mover->next=nxtGroup;//connecting reversed group 1 to un reversed next group so i can process it in next iterations

        prevTail=mover;//moving prevtail to the last tail
        mover=nxtGroup;//moving the mover

    }
    return head;
}
int main() {
    
    return 0;
}