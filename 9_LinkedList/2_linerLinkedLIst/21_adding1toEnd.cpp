#include <bits/stdc++.h>
using namespace std;

//add 1 to number represented by ll first elemnt is leftmost number

class Node{
    public:
        int data;
        Node*next;
    
        Node(int val , Node*ptr=NULL){
            data=val;
            next=ptr;
        }
    
};

long long int nrAfterAdding1(Node*head){
    if(head==NULL)return 0;
    Node*mover=head;
    int count=0;
    while(mover){
        count=count*10+(mover->data);
        mover=mover->next;
    }
    count+=1;
    return count;
}

//only works for linked list which has 10 number of elemnt as lon long int can store up to 10 digits elemnts only

/*a idea i can think is
as i need tail to add the element but i cant
go to previous node carrying th carry as it will take
right to left traversal which is not possible in ll
but i can reverse the list then add and reverse the number that is possibble*/


Node*reverseTheLL(Node*head){
    Node*mover=head;
    Node*prevNode=NULL;
     Node*newHead;
    while(mover){
        newHead=mover;
        Node*nextNode=mover->next;//save the next node
        mover->next=prevNode;//change the pointer to previous
        prevNode=mover;//move prev node to the mover so that it can be reversed in next iteration aswell
        mover=nextNode;//move mover to nextnode so that in next iteration that node can point to prev now

        /*IMPORTANT
Reversal Logic:

nextNode = mover->next;
- Save the remaining part of the list before changing any links.
- Without this, the rest of the list would become unreachable after reversal.

mover->next = prevNode;
- Reverse the current link.
- Instead of pointing forward, the current node now points backward.

prevNode = mover;
- Move prevNode one step ahead.
- The current node has now become the last node of the reversed portion.

mover = nextNode;
- Move to the next unreversed node and repeat the process.

Visual:

Before:
NULL <- prevNode

1 -> 2 -> 3 -> 4
^
mover

After one iteration:

NULL <- 1

2 -> 3 -> 4
^
mover

The reversed part grows from left to right,
while mover traverses the unreversed part.

Key Idea:
Always save mover->next before reversing the link,
otherwise the remaining list will be lost.
*/
        
        //here nextnode will point to NULL , mover is at tail
        // these are mvoing like temp then mover then  nextnode , mover point to temp first
        //then temo nullify the next , then in later part , temp become mover mover moves ahead nxtpt ahead of mover then mover point to temp again\
        //it keeps goin until mover is NULL
    }

    return newHead;

  
}

/*OPTIMAL APPROACH 1 : REVERSE + CARRY PROPAGATION

Key Observation:
Adding 1 starts from the least significant digit (tail),
but a singly linked list can only be traversed from left to right.

Example:

1 -> 2 -> 9

We need to start from 9, but we cannot move backwards
from the tail to update previous nodes.

--------------------------------------------------

Idea:

1. Reverse the linked list.
   - The least significant digit becomes the head.
   - Carry can now be propagated in the direction of traversal.

2. Initialize carry = 1
   - We are effectively adding 1 to the number.

3. Traverse the reversed list.
   - sum = current_digit + carry
   - current_digit = sum % 10
   - carry = sum / 10

4. Continue propagating carry until:
   - carry becomes 0, or
   - the list ends.

5. If carry still exists after the last node:
   - Create a new node and store the carry.
   - Example:
       999 + 1 = 1000
     After reversal:
       9 -> 9 -> 9
     becomes:
       0 -> 0 -> 0 -> 1

6. Reverse the list again to restore the original order.

--------------------------------------------------

Example:

Original:
1 -> 2 -> 9

Reverse:
9 -> 2 -> 1

Add 1:
0 -> 3 -> 1

Reverse:
1 -> 3 -> 0

Answer:
130

--------------------------------------------------

Why Reverse?

Original List:
Carry must travel right -> left.

Singly Linked List:
Traversal is only left -> right.

By reversing the list, carry propagation and traversal
occur in the same direction.

--------------------------------------------------

Time Complexity : O(N)
Space Complexity: O(1)

N = number of nodes in the linked list.
*/
Node*ptrOfTheDigitAfterAdding1Opt1(Node*head){
    Node*head=reverseTheLL(head);
    Node*mover=head;

    int carry=1;

    while(mover && carry){//till carry exist
    int sum=mover->data+carry;
    mover->data=sum%10;
    carry=sum/10;

    /*If we reach the last node and still have a carry,
create a new node to store that carry.
Otherwise the most significant digit would be lost.
*/
    if(carry && mover->next==NULL){
        Node*New=new Node(carry);//creating a new node having value carry
        mover->next=New;
        carry=0;
    }

    mover=mover->next;
    
    }

    return reverseTheLL(head);

}



/*OPTIMAL APPROACH 2 : RECURSIVE CARRY PROPAGATION

Key Observation:
Adding 1 starts from the least significant digit (tail),
but a singly linked list only allows traversal from
head to tail.

Normally, propagating carry requires moving from
right to left, which is not directly possible in a
singly linked list.

--------------------------------------------------

Idea:

Use recursion to reach the tail first.

Going Down:
head -> tail

Returning Back:
tail -> head

Thus, recursion naturally processes nodes from
right to left while returning from recursive calls.

The recursion stack acts like a temporary
backward traversal mechanism.

--------------------------------------------------

Recursive Helper:

Base Case:
When node becomes NULL, return carry = 1.

Why return 1?

Because reaching NULL means we have moved past
the last digit, and this is where the "+1"
operation actually starts.

Example:

1 -> 2 -> 9 -> NULL

helper(NULL) returns 1

This carry is then propagated back through the list.

--------------------------------------------------

Processing During Return:

carry = helper(node->next)

sum = node->data + carry

node->data = sum % 10
carry      = sum / 10

Return carry to the previous node.

--------------------------------------------------

Example:

Original:
1 -> 2 -> 9

helper(NULL) returns 1

9 + 1 = 10
node = 0
return carry = 1

2 + 1 = 3
node = 3
return carry = 0

1 + 0 = 1
node = 1
return carry = 0

Result:
1 -> 3 -> 0

--------------------------------------------------

Special Case:

Original:
9 -> 9 -> 9

helper(NULL) returns 1

9 + 1 = 10
node = 0
return carry = 1

9 + 1 = 10
node = 0
return carry = 1

9 + 1 = 10
node = 0
return carry = 1

List becomes:
0 -> 0 -> 0

Final carry = 1

Create a new head node:

1 -> 0 -> 0 -> 0

--------------------------------------------------

Important:

The linked list is NOT reversed.

No pointers are modified.

Recursion is only used to process nodes
from tail to head by utilizing the call stack.

--------------------------------------------------

Time Complexity  : O(N)
Space Complexity : O(N)

N = number of nodes

Extra space comes from the recursion stack.
*/

int recursiveReverse(Node*head){//helper funtion it 
    //as using revcursion we can move from rifgthmost nosde to leftmost node 
    if(head==NULL)return 1;

    int carry=recursiveReverse(head->next);
    int sum=head->data+carry;
    head->data=sum%10;

    carry=sum/10;

    return carry;


}

Node*add1toEndOfLL(Node*head){
    int carry=recursiveReverse(head);
    if(carry){
        Node*newHead=new Node(carry);
        newHead->next=head;
        head=newHead;
    }
    return head;

}





Node*ptrOfTheDigitAfterAdding1Opt2(Node*head){

}


int main() {
    
    return 0;
}