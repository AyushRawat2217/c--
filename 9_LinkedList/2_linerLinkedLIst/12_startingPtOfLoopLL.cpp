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

/*logic is i will
let the loop
*/
Node*startingPtOfLoopBf(Node*head){
    Node*mover=head;

    while(mover!=NULL){
    if(mover->next==mover)return mover;
    Node*mover2=head;
    while(mover2!=mover){
        if(mover->next==mover2)return mover;
    }
    }
    return NULL;
}


Node*startingPtOfLoopBf(Node*head){
    Node*mover=head;

    while(mover->next!=NULL){
    if(mover->next==mover)return mover;
    Node*mover2=head;
    while(mover2!=mover){
        if(mover->next==mover2)return mover;
        mover2=mover2->next;
    }
    mover=mover->next;
    }
    return head;
}


/*logic is
we use set to store pointers 
dekh maal lo ll ha
1 2 3 4 5 and 5 se jaakr loop hoa h 3 pe 
sbse sbse pehle list set 1-5 store krega 
fir 5 se loop hokr jaaega 3 pe 3 pe find != set.end toh isliye
return 3 hojaega , ye isloye hoga kyuki loop jaha se start hota h vohi first elemnt hota h repetion cycles ka
for ex 1 2 3 1 2 3 1 2 3
1 se start hua fir dusri cycle m dubara 1 se start hua easy
*/
Node*startingPtOfLoopBr(Node*head){
    unordered_set<Node*>st;
    while(head!=NULL){
        if(st.find(head)!=st.end())return head;
        head=head->next;
    }
    return head;
}


/*  logic is
Example:

1 -> 2-> 3->4-> 5 -> 6 -> 7 -> 8 -> 9
                ^                   |
                |___________________|

Loop starts at 5

Cycle: 5 -> 6 -> 7 -> 8 -> 9 -> 5
L = 5

Suppose slow and fast meet at 6.

x = distance(head -> loop start)
  = 1 -> 2 -> 3 -> 4 -> 5
  = 4 steps

y = distance(loop start -> meeting point)
  = 5 -> 6
  = 1 step

L - y = distance(meeting point -> loop start)
      = 6 -> 7 -> 8 -> 9 -> 5
      = 4 steps

So:

x = 4
L - y = 4

=> x = L - y

Meaning:

distance(head -> loop start)
=
distance(meeting point -> loop start)

That's why after the first meeting:

A = head
B = meeting point

Move both 1 step at a time:

A: 1 -> 2 -> 3 -> 4 -> 5
B: 6 -> 7 -> 8 -> 9 -> 5

//impppp ->Both travel 4 steps and meet at 5 (start of loop).
agr start head  se loop start ki distance  barbar h meet point ki distance loop start tkk
toh obviosly agr dono ko ham same baari chlayenge toh dono same point m aakr hi rukeng

Why does x = L - y ?

At meeting point:

slow distance = x + y
fast distance = 2(x + y)

Fast has traveled whole extra loops compared to slow:

2(x + y) = x + y + kL

=> x + y = kL

=> x = kL - y

Since kL is just one or more complete laps around the cycle,
(kL - y) lands on the same node as (L - y).

Therefore:

x = L - y   (mod L)

So the head pointer and meeting-point pointer are the same
distance away from the loop start, which is why they meet there.
*/
Node*startingPtOfLoopOpt(Node*head){
    
    Node*fast=head;
    Node*slow=head;

    while(fast!=NULL){

        slow=slow->next;
        fast=fast->next->next;


        /* i thought i would miss 1st or 2nd node as fast already moves to 2nd position
        but if there is a loop in 1st 2nd position then it will loop there itself nd slow will catch it once for all
        then will apply the meeting point and all the understanding we made*/
        if(fast==slow){
            Node*meetPoint=slow;//meetpoint
            Node*start=head;
        while(start!=meetPoint){//after x  or l-y steps they will be at start of loop
            start=start->next;
            meetPoint=meetPoint->next;
        }
        return start; //LOOP START IS FOUND
            
        }
    }
    return NULL;
}

//tc is on sc is o1


int main() {
    
    return 0;
}