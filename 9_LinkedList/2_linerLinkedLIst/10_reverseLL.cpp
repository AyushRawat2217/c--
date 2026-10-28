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
we will use stack we will iput in stack then it will go from
first to last then when we will pop to insert back to array then
elemnt will we inserted fom last to first
*/

/*IMPPP
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
Node*reverseLLBF(Node*head){
    stack<int>st;
    Node*mover=head;

    while(mover->next!=NULL){
        st.push(mover->data);
        mover=mover->next;
    }
    
    Node*mover1=head;
    while(mover1->next!=NULL){
       mover1->data=st.top();//it equates with top element
       st.pop();
       mover1=mover->next;
    }
    
    return head;
    
}

/*logic for optimal approach*


/*
REVERSE A SINGLY LINKED LIST (ITERATIVE)

Example:

1 -> 2 -> 3 -> 4 -> NULL

becomes

4 -> 3 -> 2 -> 1 -> NULL


CORE PROBLEM:
-------------
To reverse a node's pointer, we need to make it point backwards.

Example:

1 -> 2

should become

1 -> NULL

But if we directly change:

mover->next = NULL;

we lose access to node 2 and the rest of the list.

Therefore, before changing any pointer, we must SAVE the next node.


POINTERS USED:
--------------
mover : current node being processed

temp  : stores mover->next so we don't lose the remaining list

prev  : points to the already reversed portion of the list


ALGORITHM:
----------

For every node:

1. Save the next node

   temp = mover->next;

2. Reverse the current node's link

   mover->next = prev;

3. Move prev forward

   prev = mover;

4. Move mover forward

   mover = temp;


VISUAL DRY RUN:
---------------

Initially:

prev = NULL

mover
  ↓
1 -> 2 -> 3 -> NULL


Iteration 1:

temp = 2

1 -> NULL

prev
 ↓
1 -> NULL

mover
 ↓
2 -> 3 -> NULL


Iteration 2:

temp = 3

2 -> 1 -> NULL

prev
 ↓
2 -> 1 -> NULL

mover
 ↓
3 -> NULL


Iteration 3:

temp = NULL

3 -> 2 -> 1 -> NULL

prev
 ↓
3 -> 2 -> 1 -> NULL

mover = NULL


Loop ends because mover becomes NULL.


IMPORTANT OBSERVATION:
----------------------
At the end:

head still points to old node 1.

prev points to node 3 (new head).

Therefore:

return prev;


MEMORY TRICK:
-------------
SAVE -> REVERSE -> MOVE -> MOVE

temp = mover->next;
mover->next = prev;
prev = mover;
mover = temp;


TIME  : O(N)
SPACE : O(1)
*/
Node*reverseLLOpt(Node*head){

    Node*mover=head;
    Node*temp=NULL;
    Node*prev=NULL;

    while(mover!=NULL){
       temp=mover->next;//save the next pointer
       mover->next=prev;//reverse the pointer of mover make it point backwards
        prev=mover;//move the prev to mover node so that in next interation the next elemnt face towards it
        mover=temp;//moving mover to temp
    }

    return head;
}


/*logic is
newhead recuriselvy chlta rhega until a point 
it end up at last elemnent  kyuki head->next jaara h uske andr
and pehle head ka next 2 elemnt tha toh 2nd elemnt se last tkk , fir 3rd elemnt se last tkk
and similarly last elemnt hit hoga and uss time function return head krdega
prr head newHead ki value hogi last element , kyuki nth recusion m jbh reverseLL recur.. fn chla toh head ki value ki jgh
last elemnt ka ptr gyaa tha , newhead=last elemnt

and fir jbh ham nth recursion se n-1th recusion m jaate h toh uss time toh head ki valuue last secong elemnt gyi thi 
main fn mai toh head = last second elemnt h
fir front = head->next jo last elemnt h 
front ka next head bna do , jo last second elemnt h
and head ka prev ptr jo last jo ki 2nd elemnt se last elemnt ki trf point hota tha use nullify krdo
and head return krdo newHead jo ki last elemnt hi h
fir aate h ham n-2 th recursion m jisme last 3rd lemnt ka ptr pass hua tha , last 3rd elemnt head hogya h abh and piclhle recusion ki vjh se newhead (last elemnt ka ptr) abh 2nd last ko pt krra h
and recursivle ye new head upr upr aata rhegaaa
abh front = head next  jo last 2nd lemnt h
fir last second elemnt ko last  3rd elemnt ko point krega fir same aisa chlega until  1st elemnt
*/
Node*reverseLLrecursion(Node*head){
    if(head==NULL&& head->next==NULL)return head;

    Node*newHead=reverseLLrecursion(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=NULL;

    return newHead;
    
}



int main() {
    
    return 0;
}