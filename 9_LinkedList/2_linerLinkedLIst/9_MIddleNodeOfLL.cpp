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

/*first approach i can think of is
counting length
than according to odd and even length finding the mid node
for odd mid is len+1/2 for even its the second mid node
*/
int lenOfLL(Node*head){
    int len=1;
    Node*mover=head;
    while(mover->next!=NULL){
        len++;
        mover=mover->next;
    }
    return len;
}

Node*returnTheMidNodeBF(Node*head){
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;

    int len=lenOfLL(head);

    
    //for odd
    if(len&1){
        len=(len+1)/2;
    }
    else{
       len=(len/2)+1; //i want the 2nd middle node  for even
    }


   //code is same for both even and odd thats wwhy i put itafter if 
    
        int count=1;
        Node*mover=head;
        while(count<len){
            count++;
            mover=mover->next;
        }
        return mover;
}


/*logic for opt approach is
creating a slow pinter which moves 
1 step and fast ptr which moves two steps
by the time fast ptr is at end slow ptr
is at mid

let say 5 elemnts
1 2 3 4 5 

fisrst it , fast next next , at 3 ,
slow next next at 2  , then fast next next at 5 , slow next at 3


1 2 3 4
foreven num , fast nxt nxt , 3
fast nxt nxt null , then i have to break it

lets say 1 2 3 4 5 6
fst nxt nxt 3 , slow nxt 2
fast nxt nxt 6 , slw 6 
fanst nxt nxt null ,then i have to stop
means first compute fast next next , then check if null , if yes break else move slow


or optimal can be first move slow then move fast the n loop check whther fat!=null and fast-next!=null , if any of it is false loop breaks it super easy
 */

Node*returnTheMidNodeOpt(Node*head){
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;

    
    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;
    }

    return slow;
}


int main() {
    
    return 0;
}