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

Node*convertingArrayToLLThenReturningHead(vector<int>&arr){
    if(arr.empty())return NULL;
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

bool isLInkedListApalindromeBF(Node*head){
Node*mover=head;
stack<int>st;

while(mover!=NULL){
    st.push(mover->data);
    mover=mover->next;
}

mover=head;

while(mover!=NULL){
    if(mover->data!=st.top())return false;
    st.pop();
    mover=mover->next;
}
return true;
}





Node*reverseLLrec(Node*head){
    if(head==NULL||head->next==NULL)return head;//ACTUAL M BASE CONDN HEAD->NET==NULL H KYUKI WE WANT TO STOP ATLAST ELEMNT
Node*newHead=reverseLLrec(head->next);//at the end of recursion this becomes the last //now i dont want to tamper my new head so i wont move it

Node*temp=head->next;
temp->next=head;
head->next=NULL;//NULLIFY KRIYA MENE PEHLE JO HEAD AAGHE WALE ELEMNT KO PT KRRA THA

return newHead;
}


/*logic is 
i will get to the middle point then i will reverse the  2nd half of array
then i will compare both halfs if any of the node fails the fomaprision return false , else return true*/

bool isLInkedListApalindromeOpt(Node*head){//use 2 ptrs if u want to reduce space comlexity to o1 from oN 

    /*Node*left=head;

    Node*right=head;

    while(right->next!=NULL)right=right->next;

    it wont work as i can track previous node in singly linked list
    so i have to use the finding middle node using slow fast ptr
    */

    Node*slow=head;
    Node*fast=head;
// 1 2 3 4 5 
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //for even length fast is always NULL and for odd fast is at last node
    //That's why some linked-list problems use the final state of fast to determine 
    //whether the list length is odd or even.

    
    
    if(fast!=NULL){//means the length of linked list is odd
        Node*midPoint=slow;
        Node*mover=head;

        Node*mover2=reverseLLrec(midPoint->next);//midpoint ka next daaalo kyu odd nr LL aise hoti h ,  12 [3] 21
        //mid point k baad wale elemnt hojaenge reverse fir check krlena ki start se mid k pehle tkk is qual to mid k baaad se end tkk ki nhi?
        
        while(mover!=midPoint){
            if(mover->data!=mover2->data)return false;
            mover=mover->next;
            mover2=mover2->next;
        }

    }

    else{
        Node*midPoint=slow;
        Node*mover=head;

        Node*mover2=reverseLLrec(midPoint);

        while(mover!=midPoint){
            if(mover->data!=mover2->data)return false;
            mover=mover->next;
            mover2=mover2->next;
        }
        
    

    }


    return true;


}


int main() {
    vector<int>arr={1,2,5 , 6};
    Node*head=convertingArrayToLLThenReturningHead(arr);
    
    if(isLInkedListApalindromeBF(head))cout<<"true";
    else cout<<"false";
    
    return 0;
}