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


int lengthOfLL(Node*head){}
Node*reverseTheLL(Node*head){}


Node*rotatedLLBr(Node*head , int k){
    if(head==NULL || head->next==NULL )return head;
    /*logic
    jo approach picle question m use ki thi ki pehle
    kth node tkk delink krna h fir uske baad reverse krke rejoin krna h 
    dekh rotation ko reverse ka use krke krr skte h
    jese K nodes rotate krna h ll m toh sbse pehle poori ll reverse krenge
    fir uske baad pehle ki k node reverse krenge fir last ki total-k nodes reverse krenge
    */

    int len=lengthOfLL(head);
    k%=len;//if k is greater than len , then divide it by len 
    if(k==0)return head;

    Node*newHead=reverseTheLL(head);
    

    Node*kthNode=newHead;
    int count=1;
    while(count<k){
        kthNode=kthNode->next;
        count++;
    }

    //node reversal for till k and len-k
    Node*nextNode=kthNode->next;
    kthNode->next=NULL;
    Node*firstPartTail=newHead;//the head of first part becomes tail after reversal 
    newHead=reverseTheLL(newHead);
    Node*otherGrpHead=reverseTheLL(nextNode);

    //linking both groups
    Node*mover=newHead;
    firstPartTail->next=otherGrpHead;

    return newHead;
}

Node*rotatedLLOpt(Node*head , int k){
    if(head==NULL || head->next==NULL )return head;
    /*LOGIC:

First convert the LL into a circular linked list by connecting
the tail to the head.

Example:

1 -> 2 -> 3 -> 4 -> 5
k = 3

After right rotation:

3 -> 4 -> 5 -> 1 -> 2

Notice that the last k nodes (3,4,5) move to the front.
Therefore, the first node of the last-k block becomes the
new head.

To obtain this:

newTail = (len-k)th node
newHead = newTail->next

After finding newHead, break the circle by:

newTail->next = NULL
*/

    int len=lengthOfLL(head);
    k%=len;//if k is greater than len , then divide it by len 
    if(k==0)return head;

    //creating  circular ll
    Node*orgTail=head;
    while(orgTail->next){
        orgTail=orgTail->next;
    }
    orgTail->next=head;

    //reaching new tail
    Node*tail=head;
    int count=1;
    while(count<(len-k)){
        tail=tail->next;
        count++;
    }
    
    Node*newHead=tail->next;
    tail->next=NULL;

    /*DOUBT:

Why does the standard circular linked list solution find the
newTail first instead of finding the newHead directly?

For example:

1 -> 2 -> 3 -> 4 -> 5
k = 2

After rotation:

4 -> 5 -> 1 -> 2 -> 3

It seems natural to find the newHead (4) first because that is
the node we ultimately want to return.

However, in a singly linked list we cannot move backwards.
Even if I find the newHead, I still need the node before it
(newTail = 3) so that I can break the circular list:

newTail->next = NULL

This means that after finding newHead, I may have to either:

1. Traverse again to find the node before it, or
2. Explicitly keep track of the previous node while searching.

In contrast, if I find newTail first, then newHead is obtained
immediately as:

newHead = newTail->next

So is finding newTail first preferred because it avoids the
extra work caused by the inability to move backwards in a
singly linked list and therefore leads to a cleaner solution?
*/



    return newHead;
}
int main() {
    
    return 0;
}