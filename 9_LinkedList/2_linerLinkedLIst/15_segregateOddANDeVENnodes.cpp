#include <bits/stdc++.h>
using namespace std;
//2158 -71 . 64 2120
class Node{
    
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
        }
    
};

/*PROBLEM:
---------
Given a linked list, group all EVEN POSITION nodes first,
followed by all ODD POSITION nodes.

Position means node index in the list (1-based indexing),
NOT the value stored inside the node.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Positions:
1    2    3    4    5    6

Odd Position Nodes:
1 -> 3 -> 5

Even Position Nodes:
2 -> 4 -> 6

Output:
2 -> 4 -> 6 -> 1 -> 3 -> 5


IDEA:
-----
We do NOT create new nodes.

We separate the original list into two chains:

Even Chain:
2 -> 4 -> 6

Odd Chain:
1 -> 3 -> 5

Then connect:

Even Chain + Odd Chain

Result:
2 -> 4 -> 6 -> 1 -> 3 -> 5


POINTERS USED:
--------------
oddlist  -> points to current node in odd-position chain

evenList -> points to current node in even-position chain

oddHead  -> stores head of odd chain (node 1)
            Needed because oddlist keeps moving.

newHead  -> stores head of even chain (node 2)
            This becomes the final answer head.


INITIAL STATE:
--------------

1 -> 2 -> 3 -> 4 -> 5 -> 6
^    ^
O    E

oddHead = oddlist = 1
newHead = evenList = 2


LOOP LOGIC:
-----------

while(evenList != NULL && evenList->next != NULL)

Condition meaning:

evenList != NULL
    Current even node exists.

evenList->next != NULL
    Next odd node exists.

Without both checks, we cannot safely access
evenList->next and may dereference NULL.


STEP 1:
--------

oddlist->next = evenList->next;

Example:

1 -> 2 -> 3 -> 4 -> 5 -> 6

Connect current odd node to next odd node.

1 -> 3 -> 4 -> 5 -> 6

Node 2 is skipped.

Odd chain becomes:

1 -> 3 -> ...


STEP 2:
--------

oddlist = oddlist->next;

Move odd pointer forward.

oddlist now points to 3.

Reason:
Next iteration should extend the odd chain from node 3.


STEP 3:
--------

evenList->next = oddlist->next;

Current situation:

1 -> 3 -> 4 -> 5 -> 6
     ^
   oddlist

2 -> 3 -> 4 -> 5 -> 6
^
evenList

oddlist->next is 4

So:

2 -> 4 -> 5 -> 6

Even chain becomes:

2 -> 4 -> ...


STEP 4:
--------

evenList = evenList->next;

Move even pointer forward.

evenList now points to 4.

Reason:
Next iteration should extend the even chain from node 4.


AFTER FIRST ITERATION:
----------------------

Odd Chain:
1 -> 3 -> ...

Even Chain:
2 -> 4 -> ...


SECOND ITERATION:
-----------------

oddlist = 3
evenList = 4

oddlist->next = evenList->next

3 -> 5

oddlist = 5

evenList->next = oddlist->next

4 -> 6

evenList = 6


FINAL STATE:
------------

Even Chain:
2 -> 4 -> 6

Odd Chain:
1 -> 3 -> 5

Pointers:

newHead = 2
oddHead = 1


FINAL CONNECTION:
-----------------

evenList->next = oddHead;

2 -> 4 -> 6 -> 1 -> 3 -> 5


RETURN:
-------

return newHead;

Because answer starts from first even-position node.


COMPLEXITY:
-----------

Time Complexity:
O(N)
Each node visited once.

Space Complexity:
O(1)
Only a few pointers are used.
No extra list or array created.


PATTERN RECOGNITION:
--------------------

Use this pattern when:

- Need to separate odd/even POSITION nodes.
- Relative order must remain preserved.
- In-place rearrangement required.
- O(1) extra space expected.

Classic Pattern:
"Odd-Even Linked List / Position Segregation"
*/

Node*segregatingEvenAndOddNodes(Node*head){
    if(head==NULL || head->next==NULL)return head;
     Node*oddlist=head;
     Node*evenList=head->next;
   
     Node*newHead=evenList;

     Node*oddHead=oddlist;

     while(evenList && evenList->next!=NULL){
        oddlist->next=evenList->next;
        oddlist=oddlist->next;//moving to next node so that next in iteration a new node will be appended

        evenList->next=oddlist->next;
        evenList=evenList->next;

     }

     evenList->next=oddHead;

     return newHead;
}

int main() {
    
    return 0;
}